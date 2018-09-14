#pragma once

#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include "bm25_proximity.hpp"

#include "query_train_file.hpp"
#include "tp_dist.hpp"

struct term_data {
    // The term id
    uint64_t tid;
    // Total number of documents containing this term
    uint64_t total_term_docs;
    // Number of times term `t` occurs in document `d`
    size_t f_dt;
    // Weight for Xiaolu, et al.
    double w_q;
    // Query pos
    int query_pos;

    term_data() : term_data(0, 0, 0, 0, 0) {}

    term_data(int id, uint64_t term_count, size_t freq_dt, double idf_weight, int qpos)
        : tid(id), total_term_docs(term_count), f_dt(freq_dt), w_q(idf_weight), query_pos(qpos) {}
};

class doc_proximity_feature {

    const int        cdf_empty = -1;
    Lexicon &        lexicon;
    bm25_proximity<> ranker;
    size_t           feature_id = 0;
    double           score      = 0.0;

    // term stats cache
    std::map<uint64_t, term_data> term_data_map;

   public:
    doc_proximity_feature(Lexicon &lex) : lexicon(lex) {
        ranker.num_docs    = lex.document_count();
        auto num_terms     = lex.term_count();
        ranker.avg_doc_len = (double)num_terms / ranker.num_docs;
    }

    void compute(doc_entry &doc, query_train &query, Document &doc_idx) {
        score = 0.0;

        // condensed direct file
        std::vector<std::pair<uint64_t, int>> cdf;
        // for tp_interval_score
        std::vector<indri::utility::greedy_vector<int>> acc_positions;
        std::vector<term_data>                          acc_terms;

        int i = 0;
        int s = 0;
        for (auto &tid : query.tids) {
            if (lexicon.is_oov(tid)) {
                continue;
            }
            if (doc_idx.freq(tid) !=0) {
                ++s;
                term_data curr_term(tid,
                                    lexicon[tid].document_count(),
                                    doc_idx.freq(tid),
                                    ranker.calculate_wq(doc_idx.freq(tid)),
                                    query.pos[i]);
                term_data_map.insert(std::pair<uint64_t, term_data>(tid, curr_term));

                _acc_positions_insert(acc_positions, doc_idx.positions(tid), acc_terms, curr_term);

                for (auto pos : doc_idx.positions(tid)) {
                    cdf.push_back(std::make_pair(tid, pos));
                }
            }
            ++i;
        }

        if (s < 2) {
            return;
        }

        // sort cdf
        std::sort(cdf.begin(),
                  cdf.end(),
                  [](const std::pair<uint64_t, int> &lhs, const std::pair<uint64_t, int> &rhs) {
                      return lhs.second < rhs.second;
                  });

        // find bigrams of all query term pairs
        score = 0.0;
        cdf_search(TP_BIGRAM, cdf, query, 8, doc.length);
        doc.bm25_bigram_u8 = score;

        // Xiaolu, et al.
        doc.bm25_tp_dist_w100 = tp_interval_score(acc_positions, acc_terms, 100, doc.length);

        // Clear for next doc
        term_data_map.clear();
    }

    enum term_pair_type {
        TP_NONE = 0,
        TP_BIGRAM,
        TP_ORDERED,
        TP_UNORDERED,
    };

    struct term_pair {
        enum term_pair_type type;
        int                 distance;
        std::pair<int, int> term_a;
        std::pair<int, int> term_b;
        double              score;

        term_pair(enum term_pair_type ty,
                  int                 dist,
                  std::pair<int, int> a,
                  std::pair<int, int> b,
                  double              s)
            : type(ty), distance(dist), term_a(a), term_b(b), score(s) {}
    };

    // Takes a sorted condensed direct file (CDF) of query terms that appear in
    // the document. It is assumed the CDF is sorted according to term position,
    // the query term pairs may appear unordered as they occur within the
    // document. The main loop in this function performs a bigram scan over these
    // unordered query term pairs in the order that they appear within the CDF.
    void cdf_search(const enum term_pair_type                    ty,
                    std::vector<std::pair<uint64_t, int>> const &cdf,
                    const query_train &                          query,
                    const int                                    window,
                    const int                                    doc_length) {
        std::vector<term_pair> found;

        // Callers of this function will use window parameter of 2 for bigram, 8
        // for window of 8, etc. But internal to this function the window value is
        // `window - 1`.
        const int _window = window - 1;

        for (size_t i = 0; i < cdf.size() - 1; ++i) {
            // bigram scan
            for (size_t j = i + 1; j < cdf.size(); i = j++) {
                auto      lhs  = cdf[i];
                auto      rhs  = cdf[j];
                const int dist = rhs.second - lhs.second;

                // Skip bigrams with the same term
                if (lhs.first == rhs.first) {
                    continue;
                }

                // There is no need to check that `lhs.second < rhs.second` (i.e. is
                // not a bigram) since it is assumed that `cdf` is already sorted
                // and we're scanning for unordered bigrams for all query terms.

                if (dist > 0 && dist <= _window) {
                    auto data_a = term_data_map[lhs.first];
                    auto data_b = term_data_map[rhs.first];
                    int  q_ft;

                    q_ft = 0;
                    {
                        auto it = query.q_ft.find(lhs.first);
                        if (it != query.q_ft.end()) {
                            q_ft = it->second;
                        }
                    }
                    score += ranker.score(q_ft, data_a.f_dt, data_a.total_term_docs, doc_length);

                    q_ft = 0;
                    {
                        auto it = query.q_ft.find(rhs.first);
                        if (it != query.q_ft.end()) {
                            q_ft = it->second;
                        }
                    }
                    score += ranker.score(q_ft, data_b.f_dt, data_b.total_term_docs, doc_length);
                    found.emplace_back(ty, dist, lhs, rhs, score);
                }
            }
        }
    }

    /**
     * Bigram interval score. Based on Lu, et al. Efficient and Effective Higher
     * Order Proximity Modeling, ICTIR 2016.
     */
    double tp_interval_score(const std::vector<indri::utility::greedy_vector<int>> &acc_positons,
                             const std::vector<term_data> &                         acc_terms,
                             const int                                              wsize,
                             const double                                           W_d) {
        double                    doc_score = 0.0;
        std::pair<double, double> curr_score;
        double                    lambda_o = 0.4;
        double                    lambda_u = 0.4;

        for (size_t i = 0; i < acc_positons.size() - 1; ++i) {
            term_data                          term_i     = acc_terms[i];
            indri::utility::greedy_vector<int> i_position = acc_positons[i];
            for (size_t j = (i + 1); j < acc_positons.size(); ++j) {
                //!< do the sweep only when bigrams are formed
                term_data term_j      = acc_terms[j];
                int       delta_order = term_j.query_pos - term_i.query_pos;
                if (std::abs(delta_order) == 1) {
                    indri::utility::greedy_vector<int> j_position = acc_positons[j];
                    if (delta_order > 0) {
                        curr_score = TPDist::calc_tp_dist(
                            i_position, j_position, term_i.w_q, term_j.w_q, wsize);
                    } else {
                        curr_score = TPDist::calc_tp_dist(
                            j_position, i_position, term_j.w_q, term_i.w_q, wsize);
                    }
                    curr_score.first = lambda_o * ranker.calculate_tf_score(curr_score.first, W_d);
                    curr_score.second =
                        lambda_u * ranker.calculate_tf_score(curr_score.second, W_d);
                    doc_score += curr_score.first;
                    doc_score += curr_score.second;
                }
            }
        }

        return doc_score;
    }

    /**
     * Vector insert ordered by f_dt. Xiaolu, et al.
     */
    void _acc_positions_insert(std::vector<indri::utility::greedy_vector<int>> &pos_vec,
                               const std::vector<uint32_t> &                          pos_el,
                               std::vector<term_data> &                         term_vec,
                               term_data &                                      term_el) {

        if (pos_vec.empty()) {
            pos_vec.push_back(pos_el);
            term_vec.push_back(term_el);
            return;
        }

        auto pos_itr  = pos_vec.begin();
        auto term_itr = term_vec.begin();
        while (pos_el.size() > pos_itr->size() && pos_itr != pos_vec.end()) {
            //!< if current freq is larger than the previous ones
            ++pos_itr;
            ++term_itr;
        }
        pos_vec.insert(pos_itr, pos_el);
        term_vec.insert(term_itr, term_el);
    }


};
