/*
 * Copyright 2020 The Tesserae authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#include <cstdint>

#include "tesserae/forward_index.hpp"

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
};
