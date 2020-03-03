/*
 * Copyright 2018 The Tesserae authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#pragma once

double calculate_lm(uint32_t d_f, uint64_t c_f, uint32_t dlen, uint64_t clen,
                    double mu) {
  double numerator = d_f + mu * c_f / clen;
  double denominator = dlen + mu;
  return std::log(numerator / denominator);
}
