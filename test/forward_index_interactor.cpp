#include <catch2/catch.hpp>

#include "tesserae/forward_index.hpp"
#include "tesserae/forward_index_interactor.hpp"

static std::vector<std::vector<uint16_t>> get_dummy_lengths() {
  return {
      {10, 20},  // field 0
      {50, 40},  // field 1
  };
}

TEST_CASE("minimum length of each field within a document") {
  Document doc;
  doc.set_fields({0, 1});
  ForwardIndexInteractor intereactor;
  auto dummy_lengths = get_dummy_lengths();

  for (size_t i = 0; i < dummy_lengths.size(); i++) {
    auto field_id = i;
    for (auto field_len : dummy_lengths[i]) {
      doc.set_field_len(field_id, doc.field_len(field_id) + field_len);

      intereactor.process_field_min_len(doc, field_id, field_len);
    }
  }

  REQUIRE(10 == doc.field_min_len(0));
  REQUIRE(40 == doc.field_min_len(1));
}

TEST_CASE("maximum length of each field within a document") {
  Document doc;
  doc.set_fields({0, 1});
  ForwardIndexInteractor intereactor;
  auto dummy_lengths = get_dummy_lengths();

  for (size_t i = 0; i < dummy_lengths.size(); i++) {
    auto field_id = i;
    for (auto field_len : dummy_lengths[i]) {
      doc.set_field_len(field_id, doc.field_len(field_id) + field_len);

      intereactor.process_field_max_len(doc, field_id, field_len);
    }
  }

  REQUIRE(20 == doc.field_max_len(0));
  REQUIRE(50 == doc.field_max_len(1));
}

TEST_CASE("sum of squares of document field") {
  uint16_t field_id = 0;
  uint16_t field_len = 10;
  Document doc;
  ForwardIndexInteractor intereactor;
  doc.set_fields({field_id});
  doc.set_field_len(field_id, doc.field_len(field_id) + field_len);

  intereactor.process_field_len_sum_sqrs(doc, field_id, field_len);

  REQUIRE(100 == doc.field_len_sum_sqrs(field_id));
}

TEST_CASE("multiple sum of squares of document field") {
  uint16_t field_id = 0;
  uint16_t field_len;
  Document doc;
  ForwardIndexInteractor intereactor;
  doc.set_fields({field_id});

  field_len = 10;
  doc.set_field_len(field_id, doc.field_len(field_id) + field_len);
  intereactor.process_field_len_sum_sqrs(doc, field_id, field_len);

  field_len = 7;
  doc.set_field_len(field_id, doc.field_len(field_id) + field_len);
  intereactor.process_field_len_sum_sqrs(doc, field_id, field_len);

  REQUIRE(149 == doc.field_len_sum_sqrs(field_id));
}

TEST_CASE("length of a document field") {
  uint16_t field_id = 0;
  uint16_t field_len = 10;
  Document doc;
  ForwardIndexInteractor intereactor;
  doc.set_fields({field_id});

  intereactor.process_field_len(doc, field_id, field_len);

  REQUIRE(10 == doc.field_len(field_id));
}

TEST_CASE("cumulative length of a document field") {
  uint16_t field_id = 0;
  uint16_t field_len;
  Document doc;
  ForwardIndexInteractor intereactor;
  doc.set_fields({field_id});

  field_len = 10;
  intereactor.process_field_len(doc, field_id, field_len);
  field_len = 5;
  intereactor.process_field_len(doc, field_id, field_len);

  REQUIRE(15 == doc.field_len(field_id));
}
