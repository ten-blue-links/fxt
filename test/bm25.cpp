#include <catch2/catch.hpp>

#include "fxt/features/bm25/bm25.hpp"

TEST_CASE("Simple BM25 score") {
  rank_bm25 ranker;
  ranker.set_k1(1.0);
  ranker.set_b(0.5);
  ranker.num_docs = 10000;
  ranker.avg_doc_len = 100.0;

  REQUIRE(Approx(3.9941) == ranker.calculate_docscore(1, 10, 1000, 100));
}
