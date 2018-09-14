#pragma once
#include "lexicon.hpp"
#include "lm.hpp"

template <size_t _mu>
class doc_lm_dir_feature : public doc_feature {

   public:
    doc_lm_dir_feature(Lexicon &lex) : doc_feature(lex) {}

    void lm_dir_compute(query_train &qry, doc_entry &doc, Document &doc_idx, FieldIdMap &field_id_map) {
        for (auto &q : qry.q_ft) {
            // skip non-existent terms
            if (lexicon.is_oov(q.first)) {
                continue;
            }

            if (doc_idx.freq(q.first) == 0) {
                continue;
            }

            _score_doc += calculate_lm(doc_idx.freq(q.first),
                                        lexicon[q.first].term_count(),
                                        doc_idx.length(),
                                        _coll_len,
                                        _mu);

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

                double field_score =
                    calculate_lm(doc_idx.freq(field_id, q.first),
                                  lexicon[q.first].field_term_count(field_id),
                                  doc_idx.field_len(field_id),
                                  _coll_len,
                                  _mu);
                _accumulate_score(field_str, field_score);
            }
        }

        doc.lm_dir_2500         = _score_doc;
        doc.lm_dir_2500_body    = _score_body;
        doc.lm_dir_2500_title   = _score_title;
        doc.lm_dir_2500_heading = _score_heading;
        doc.lm_dir_2500_inlink  = _score_inlink;
        doc.lm_dir_2500_a       = _score_a;
    }
};
