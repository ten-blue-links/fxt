#pragma once

#include "doc_bm25_feature.hpp"

/**
 * BM25 using Atire's parameters.
 */
class doc_bm25_atire_feature : public doc_bm25_feature {

public:
  doc_bm25_atire_feature(Lexicon &lex) : doc_bm25_feature(lex) {}

  void compute(query_train &qry, doc_entry &doc, Document &doc_idx, FieldIdMap &field_id_map) {
    ranker.set_k1(90);
    ranker.set_b(40);

    bm25_compute(qry, doc, doc_idx, field_id_map);

    doc.bm25_atire = _score_doc;
    doc.bm25_atire_body = _score_body;
    doc.bm25_atire_title = _score_title;
    doc.bm25_atire_heading = _score_heading;
    doc.bm25_atire_inlink = _score_inlink;
    doc.bm25_atire_a = _score_a;
  }
};
