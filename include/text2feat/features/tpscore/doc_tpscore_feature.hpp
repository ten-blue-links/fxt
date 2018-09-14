#pragma once

#include <cmath>

#include "features/bm25/doc_bm25_feature.hpp"

struct bctp_term {
    int    id;
    double weight      = 0.0;
    double accumulator = 0.0;
    int    doc_count   = 0;
};

struct bctp_scorer {
    size_t num_docs    = 0;
    double k1          = 0.9;
    double b           = 0.4;
    double avg_doc_len = 0.0;

    double score(std::vector<bctp_term> &terms, doc_entry &doc, Document &doc_idx) {
        double score = 0.0;

        if (terms.size() < 3 || doc.length < terms.size()) {
            return score;
        }

        std::map<int, bctp_term *> term_map;
        for (auto &t : terms) {
            term_map.insert(std::make_pair(t.id, &t));
        }
        score_terms(term_map, doc_idx.terms());

        for (auto const &term : terms) {
            double weight = std::min(1.0, term.weight);
            double K      = k1 * ((1 - b) + (b * (doc.length / avg_doc_len)));
            double x      = term.accumulator * (1 + k1);
            double y      = term.accumulator + K;

            score += weight * (x / y);
        }

        return score;
    }

    void score_terms(std::map<int, bctp_term *> &terms, const std::vector<uint32_t> &doc_positions) {
        bctp_term *curr_term = nullptr;
        bctp_term *prev_term = nullptr;
        size_t     prev_pos  = 0;

        for (auto &t : terms) {
            t.second->weight = rw_idf_weight(t.second->doc_count);
        }

        for (size_t pos = 0; pos < doc_positions.size(); ++pos) {
            int term_id = doc_positions[pos];
            if (terms.count(term_id) == 1) {
                curr_term = terms[term_id];
                if (prev_term && prev_term->id != curr_term->id) {
                    curr_term->accumulator += prev_term->weight * distance(pos, prev_pos);
                    prev_term->accumulator += curr_term->weight * distance(pos, prev_pos);
                }
                prev_term = curr_term;
                prev_pos  = pos;
            }
        }
    }

    inline double rw_idf_weight(size_t num_doc_term) {
        if (num_doc_term == 0) {
            return 0;
        }
        return std::log(num_docs / num_doc_term);
    }

    inline double distance(size_t pos_i, size_t pos_j) { return std::pow(pos_j - pos_i, -2); }
};

class doc_tpscore_feature : public doc_bm25_feature {
    bctp_scorer ranker_bctp;

   public:
    doc_tpscore_feature(Lexicon &lex) : doc_bm25_feature(lex) {
        ranker_bctp.num_docs    = _num_docs;
        ranker_bctp.avg_doc_len = _avg_doc_len;
    }

    void compute(query_train &qry, doc_entry &doc, Document &doc_idx, FieldIdMap &field_id_map) {
        auto bm25_atire = doc.bm25_atire;
        if(bm25_atire == 0) {
            ranker.set_k1(90);
            ranker.set_b(40);
            bm25_compute(qry, doc, doc_idx, field_id_map);
            bm25_atire = _score_doc;
        }

        std::vector<bctp_term> bctp_query;
        for (auto &q : qry.q_ft) {
            bctp_term t;
            if (lexicon.is_oov(q.first)) {
                continue;
            }
            t.id        = q.first;
            t.doc_count = lexicon[q.first].document_count();
            bctp_query.push_back(t);
        }

        double tp_score = ranker_bctp.score(bctp_query, doc, doc_idx);
        // The TP-Score is BM25 + BCTP
        doc.tpscore = bm25_atire + tp_score;
    }
};
