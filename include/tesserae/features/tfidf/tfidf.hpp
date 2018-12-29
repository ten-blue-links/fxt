/*
 * Copyright 2018 The Tesserae authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#pragma once

static double calculate_tfidf(double d_f, double t_idf, double dlen, size_t num_docs) {
    double doc_norm = 1.0 / dlen;
    double w_dq     = 1.0 + std::log(d_f);
    double w_Qq     = std::log(1.0 + ((double)num_docs / t_idf));
    return (doc_norm * w_dq * w_Qq);
}
