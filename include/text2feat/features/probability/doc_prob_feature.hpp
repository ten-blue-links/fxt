#pragma once

#include "prob.hpp"

class doc_prob_feature : public doc_feature {

   public:
    doc_prob_feature(Lexicon &lex) : doc_feature(lex) {}

    void compute(query_train &qry, doc_entry &doc, Document &doc_idx, FieldIdMap &field_id_map) {
        for (auto &q : qry.q_ft) {
            // skip non-existent terms
            if (q.first == 0) {
                continue;
            }

            if (doc_idx.freq(q.first) == 0) {
                continue;
            }

            _score_doc += calculate_prob(doc_idx.freq(q.first), doc_idx.length());

            // Score document fields
            for (const std::string &field_str : _fields) {
                int field_id = field_id_map[field_str];
                if (field_id < 1) {
                    // field is not indexed
                    continue;
                }

                if (0 == doc_idx.field_len(field_id)) {
                    continue;
                }
                if (doc_idx.freq(field_id, q.first) == 0) {
                    continue;
                }

                double field_score = calculate_prob(
                    doc_idx.freq(field_id, q.first), doc_idx.field_len(field_id));
                _accumulate_score(field_str, field_score);
            }
        }

        doc.prob         = _score_doc;
        doc.prob_body    = _score_body;
        doc.prob_title   = _score_title;
        doc.prob_heading = _score_heading;
        doc.prob_inlink  = _score_inlink;
        doc.prob_a       = _score_a;
    }
};
