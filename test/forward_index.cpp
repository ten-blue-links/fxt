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

TEST_CASE("document set field term frequency") {
  auto field_id = 0;
  Document doc;
  doc.set_terms({1, 5, 7, 7, 1, 1, 1});
  doc.set_fields({0});

  doc.set_freq(field_id, 1, 4);
  doc.set_freq(field_id, 7, 2);

  REQUIRE(0 == doc.freq(field_id, 42));
  REQUIRE(4 == doc.freq(field_id, 1));
  REQUIRE(2 == doc.freq(field_id, 7));
}

TEST_CASE("document set unkown field term frequency") {
  auto field_id = 0;
  Document doc;
  doc.set_terms({1, 2, 3});
  doc.set_fields({0});

  // unkown term
  doc.set_freq(field_id, 64, 1);
  // unkown field
  doc.set_freq(1, 64, 1);
  doc.set_freq(field_id, 1, 1);
  doc.set_freq(field_id, 2, 1);
  doc.set_freq(field_id, 3, 1);

  // unkown term
  REQUIRE(0 == doc.freq(field_id, 64));
  // unkown field
  REQUIRE(0 == doc.freq(1, 64));
  REQUIRE(1 == doc.freq(field_id, 1));
  REQUIRE(1 == doc.freq(field_id, 2));
  REQUIRE(1 == doc.freq(field_id, 3));
}

TEST_CASE("document field minimum length initialization") {
  Document doc;
  doc.set_fields({0, 1});

  doc.set_field_min_len(0, 100);
  // field `1` not set

  REQUIRE(100 == doc.field_min_len(0));
  REQUIRE(0 == doc.field_min_len(1));
}
