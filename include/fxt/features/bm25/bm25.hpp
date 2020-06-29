/*
 * Copyright 2018 The Fxt authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#pragma once

#include <cmath>

struct rank_bm25 {
  const double epsilon_score = 1e-6;
  double k1;
  double b;
  size_t num_docs;
  double avg_doc_len;

  void set_k1(const double val) { k1 = val; }
  void set_b(const double val) { b = val; }
  double calculate_docscore(const double f_qt, const double f_dt,
                            const double f_t, const double W_d) const {
    double w_qt = std::max(
        epsilon_score, std::log((num_docs - f_t + 0.5) / (f_t + 0.5)) * f_qt);
    double K_d = k1 * ((1 - b) + (b * (W_d / avg_doc_len)));
    double w_dt = ((k1 + 1) * f_dt) / (K_d + f_dt);

    return w_dt * w_qt;
  }
};
