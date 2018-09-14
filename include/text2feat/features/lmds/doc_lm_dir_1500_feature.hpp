#pragma once

#include "doc_lm_dir_feature.hpp"

class doc_lm_dir_1500_feature : public doc_lm_dir_feature<1500> {

   public:
    doc_lm_dir_1500_feature(Lexicon &lex) : doc_lm_dir_feature(lex) {}

    void compute(query_train &qry, doc_entry &doc, Document &doc_idx, FieldIdMap &field_id_map) {
        lm_dir_compute(qry, doc, doc_idx, field_id_map);
        doc.lm_dir_1500         = _score_doc;
        doc.lm_dir_1500_body    = _score_body;
        doc.lm_dir_1500_title   = _score_title;
        doc.lm_dir_1500_heading = _score_heading;
        doc.lm_dir_1500_inlink  = _score_inlink;
        doc.lm_dir_1500_a       = _score_a;
    }
};
