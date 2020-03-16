#include <catch2/catch.hpp>

#include "tesserae/forward_index.hpp"
#include "tesserae/forward_index_interactor.hpp"

TEST_CASE("minimum length of each field within a document") {
  Document doc;
  doc.set_fields({0, 1});
  ForwardIndexInteractor intereactor;
  std::vector<std::vector<uint16_t>> dummy_lengths = {
      {10, 20},  // field 0
      {50, 40},  // field 1
  };

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
  std::vector<std::vector<uint16_t>> dummy_lengths = {
      {10, 20},  // field 0
      {50, 40},  // field 1
  };

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
