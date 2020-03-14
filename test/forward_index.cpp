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

TEST_CASE("document set term frequency") {
  Document doc;
  doc.set_terms({1, 5, 7, 7, 1, 1, 1});

  doc.set_freq(1, 4);
  doc.set_freq(7, 2);

  REQUIRE(0 == doc.freq(42));
  REQUIRE(4 == doc.freq(1));
  REQUIRE(2 == doc.freq(7));
}

TEST_CASE("document set unkown term frequency") {
  Document doc;
  doc.set_terms({1, 2, 3});

  doc.set_freq(64, 1);

  REQUIRE(0 == doc.freq(64));
  REQUIRE(0 == doc.freq(1));
  REQUIRE(0 == doc.freq(2));
  REQUIRE(0 == doc.freq(3));
}
