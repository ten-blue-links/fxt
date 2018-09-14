#pragma once

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <string>
#include <vector>

template <uint32_t t_k1 = 90, uint32_t t_b = 40>
struct bm25_proximity {
    static const double   k1;
    static const double   b;
    static const double   epsilon_score;
    size_t                num_docs;
    double                avg_doc_len;

    double score(const double f_qt, const double f_dt, const double f_t, const double W_d) const {
        double w_qt = std::max(epsilon_score, std::log((num_docs / f_t) * f_qt));
        double K_d  = k1 * ((1 - b) + (b * (W_d / avg_doc_len)));
        double w_dt = ((k1 + 1) * f_dt) / (K_d + f_dt);

        return w_dt * w_qt;
    }

    /**
     * calculate the tf part score only
     *
     * @param double f_dt. tf count
     * @param double W_d. document length.
     * @return double. score of tf part only.
     */
    double calculate_tf_score(const double f_dt, const double W_d) const {
        double K_d  = k1 * ((1 - b) + (b * (W_d / avg_doc_len)));
        double w_dt = ((k1 + 1) * f_dt) / (K_d + f_dt);

        return w_dt;
    }

    /**
     * only calculate the idf value based on bm25
     *
     * @param double f_t. df value
     * @return double. w_q
     */
    double calculate_wq(const double f_t) const { return std::log(num_docs / f_t); }
};

template <uint32_t t_k1, uint32_t t_b>
const double bm25_proximity<t_k1, t_b>::k1 = (double)t_k1 / 100.0;

template <uint32_t t_k1, uint32_t t_b>
const double bm25_proximity<t_k1, t_b>::b = (double)t_b / 100.0;

template <uint32_t t_k1, uint32_t t_b>
const double bm25_proximity<t_k1, t_b>::epsilon_score = 1e-6;
