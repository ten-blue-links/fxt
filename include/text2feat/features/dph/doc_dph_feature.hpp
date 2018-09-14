#pragma once
#include "lexicon.hpp"
#include "dph.hpp"

class doc_dph_feature : public doc_feature {
   public:
    doc_dph_feature(Lexicon &lex) : doc_feature(lex) {}

    void compute(query_train &qry, doc_entry &doc, Document &doc_idx, FieldIdMap &field_id_map) {
        for (auto &q : qry.q_ft) {
            // skip non-existent terms
            if (lexicon.is_oov(q.first)) {
                continue;
            }

            if (doc_idx.freq(q.first) == 0) {
                continue;
            }

            _score_doc += calculate_dph(
                doc_idx.freq(q.first), lexicon[q.first].term_count(), _num_docs, _avg_doc_len, doc_idx.length());

            // Score document fields
            for (const std::string &field_str : _fields) {
                int field_id = field_id_map[field_str];
                if (field_id < 1) {
                    // field is not indexed
                    continue;
                }

                if (doc_idx.field_len(field_id) == 0) {
                    continue;
                }
                if (doc_idx.freq(field_id, q.first) == 0) {
                    continue;
                }

                int field_term_cnt = lexicon[q.first].field_term_count(field_id);
                if (0 == field_term_cnt) {
                    continue;
                }

                double field_score =
                    calculate_dph(doc_idx.freq(field_id, q.first),
                                   field_term_cnt, _num_docs, _avg_doc_len,
                                   doc_idx.field_len(field_id));
                _accumulate_score(field_str, field_score);
            }
        }

        doc.dph         = _score_doc;
        doc.dph_body    = _score_body;
        doc.dph_title   = _score_title;
        doc.dph_heading = _score_heading;
        doc.dph_inlink  = _score_inlink;
        doc.dph_a       = _score_a;
    }
};
