#pragma once

double calculate_dph(uint32_t d_f, uint64_t c_f, uint32_t num_docs,
                     double avg_dlen, uint32_t dlen) {
  double f, norm, score;
  f = (double)d_f / (double)dlen;
  norm = (1.0 - f) * (1.0 - f) / (d_f + 1.0);
  score = 1.0 * norm *
          ((double)d_f * log2(((double)d_f * (double)avg_dlen / (double)dlen) *
                              ((double)num_docs / (double)c_f)) +
           0.5 * log2(2.0 * M_PI * d_f * (1.0 - f)));
  return (score);
}