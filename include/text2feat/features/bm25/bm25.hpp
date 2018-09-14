#pragma once

#include <cmath>

struct rank_bm25 {
    const double epsilon_score = 1e-6;
    double       k1;
    double       b;
    size_t       num_docs;
    double       avg_doc_len;

    void   set_k1(const uint32_t n) { k1 = n / 100.0; }
    void   set_b(const uint32_t n) { b = n / 100.0; }
    double calculate_docscore(const double f_qt,
                              const double f_dt,
                              const double f_t,
                              const double W_d) const {
        double w_qt =
            std::max(epsilon_score, std::log((num_docs - f_t + 0.5) / (f_t + 0.5)) * f_qt);
        double K_d  = k1 * ((1 - b) + (b * (W_d / avg_doc_len)));
        double w_dt = ((k1 + 1) * f_dt) / (K_d + f_dt);

        return w_dt * w_qt;
    }
};