/*
 * Copyright 2018 The Tesserae authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#pragma once

#include <cmath>

inline double calculate_lm(uint32_t d_f, uint64_t c_f, uint32_t dlen,
                           uint64_t clen, double mu) {
  double numerator = d_f + mu * (c_f / clen);
  double denominator = dlen + mu;
  return std::log(numerator / denominator);
}

/**
 * Dirichlet scoring function as per Indri implementation. Smoothing is applied
 * to the given context (a.k.a. collection). See
 * `indri::query::DirichletTermScoreFunction`.
 */
class DirichletTermScore {
  double mu_;
  double mu_collection_;
  double collection_frequency_;

 public:
  DirichletTermScore(double mu)
      : mu_(mu), mu_collection_(0.0), collection_frequency_(0.0) {}

  /**
   * Set up the current scoring context. This is usually the collection, but
   * could be document fields. (Fields are not supported).
   *
   * See `indri::query::TermScoreFunctionFactory::get`.
   */
  void set_context(uint32_t ctx_frequency, uint32_t ctx_length) {
    if (ctx_frequency > 0) {
      collection_frequency_ = double(ctx_frequency) / double(ctx_length);
    } else {
      collection_frequency_ = 1.0 / double(ctx_length * 2.);
    }

    mu_collection_ = mu_ * collection_frequency_;
  }

  /**
   * The idea here is for composability with other data structures.
   */
  double operator()(uint32_t ctx_frequency, uint32_t ctx_length,
                    uint32_t global_frequency, uint32_t global_length) {
    return score(ctx_frequency, ctx_length, global_frequency, global_length);
  }

  /**
   * Score a single term.
   */
  double score(uint32_t ctx_frequency, uint32_t ctx_length,
               uint32_t global_frequency, uint32_t global_length) {
    set_context(global_frequency, global_length);
    // See `indri::query::DirichletTermScore::scoreOccurrence`.
    double result =
        (double(ctx_frequency) + mu_collection_) / (double(ctx_length) + mu_);
    return std::log(result);
  }
};
