#include <catch2/catch.hpp>

#include "tesserae/forward_index.hpp"

TEST_CASE("set terms on index of one document") {
  std::vector<uint32_t> terms = {1, 2, 3, 1, 4, 5, 6, 7, 1, 1};
  std::vector<uint32_t> uniq_terms = {1, 2, 3, 4, 5, 6, 7};
  Document doc;

  doc.set_terms(terms);

  REQUIRE(terms == doc.terms());
  REQUIRE(uniq_terms == doc.unique_terms());
}

TEST_CASE("set terms on index of multiple documents") {
  std::vector<uint32_t> terms = {5, 2, 3, 3, 9, 6};
  std::vector<uint32_t> uniq_terms = {2, 3, 5, 6, 9};
  Document doc;

  doc.set_terms(terms);

  REQUIRE(terms == doc.terms());
  REQUIRE(uniq_terms == doc.unique_terms());
}
