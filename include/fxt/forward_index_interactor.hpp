/*
 * Copyright 2020 The Fxt authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#include <cstdint>

#include "fxt/forward_index.hpp"

/**
 * This is the interface for handling operations within `create_forward_index`.
 */
class ForwardIndexInteractor {
 public:
  ForwardIndexInteractor() = default;

  void process_field_min_len(Document &doc, uint16_t field_id,
                             uint16_t field_len) {
    if (doc.field_min_len(field_id) > field_len) {
      doc.set_field_min_len(field_id, field_len);
    }
  }

  void process_field_max_len(Document &doc, uint16_t field_id,
                             uint16_t field_len) {
    if (doc.field_max_len(field_id) < field_len) {
      doc.set_field_max_len(field_id, field_len);
    }
  }

  void process_field_len_sum_sqrs(Document &doc, uint16_t field_id,
                                  uint16_t field_len) {
    uint32_t sqrs = field_len * field_len;
    doc.set_field_len_sum_sqrs(field_id,
                               doc.field_len_sum_sqrs(field_id) + sqrs);
  }

  void process_field_len(Document &doc, uint16_t field_id, uint16_t field_len) {
    doc.set_field_len(field_id, doc.field_len(field_id) + field_len);
  }
};
