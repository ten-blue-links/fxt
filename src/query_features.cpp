/*
 * Copyright 2018 The text2feat authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

// Pre-retrieval query features:
//
//   * Query length of non-stop words in the query
//   * Simplified clarity score
//   * Std deviation of the IDF of the terms in query
//   * Gamma2: IDF max / IDF min
//   * Query scope
//   * AvIDF on full query
//   * AvIDF on non-stopwords in the query
//   * AvICTF on full query
//   * AvICTF on non-stopwords in the query

#include <cmath>
#include <limits>
#include <string>
#include <unordered_map>

#include "fgen_term_qry.hpp"
#include "query_features.h"

#define ZETA 1.960

static int is_stopword(std::set<std::string> &set, const std::string &term) {
    int  ret = 0;
    auto w   = set.find(term);
    if (w != set.end()) {
        ret = 1;
    }
    return ret;
}

static uint64_t total_docs  = 0;
static uint64_t total_terms = 0;
static double   avg_doc_len = 0.0;

/* Initialize global collection statistics */
void query_features_init(uint64_t num_docs, uint64_t num_terms) {
    total_docs  = num_docs;
    total_terms = num_terms;
    avg_doc_len = (double)num_terms / num_docs;
}

/* Query length of non-stop words in the query */
int q_stopped_len(std::set<std::string> &set, query_t &query) {
    int qlen = 0;

    for (size_t i = 0; i < query.len; ++i) {
        auto w = set.find(query.terms[i]);
        if (w == set.end()) {
            ++qlen;
        }
    }

    return qlen;
}

/*
 * The standard deviation of the IDF of the terms in the query.
 *
 * He and Ounis. Inferring Query Performance Using Pre-retrieval Predictors,
 * SPIRE 2004.
 */
void gamma1(query_t &                                q,
            std::unordered_map<std::string, term_t> &termmap,
            std::set<std::string> &                  set) {
    size_t i;
    double avg = 0.0, sum = 0.0, sum_sqrs = 0.0, variance = 0.0;
    double std_dev = 0.0, idf = 0.0;

    for (i = 0; i < q.len; i++) {
        std::string term = q.terms[i];
        auto        ct   = termmap.find(term);
        if (ct == termmap.end()) {
            continue;
        }
        if (is_stopword(set, term)) {
            continue;
        }

        idf = (std::log2(total_docs + 0.5) / ct->second.cdf) / std::log2(total_docs + 1);
        sum += idf;
        sum_sqrs += idf * idf;
    }

    if (q.len_stopped) {
        avg      = sum / q.len_stopped;
        variance = sum_sqrs / q.len_stopped - avg * avg;
        std_dev  = sqrt(variance);

        q.tfidf_avg        = avg;
        q.tfidf_variance   = variance;
        q.tfidf_std_dev    = std_dev;
        q.tfidf_confidence = ZETA * (q.tfidf_std_dev / (sqrt(q.len_stopped)));
    }
}

/*
 * The maximum and minimum IDF among the terms in query respectively.
 *
 * He and Ounis. Inferring Query Performance Using Pre-retrieval Predictors,
 * SPIRE 2004.
 */
double gamma2(query_t &                                q,
              std::unordered_map<std::string, term_t> &termmap,
              std::set<std::string> &                  set) {
    size_t i;
    double min = std::numeric_limits<double>::max();
    double max = 0.0;

    for (i = 0; i < q.len; i++) {
        std::string term = q.terms[i];
        auto        ct   = termmap.find(term);
        if (ct == termmap.end()) {
            continue;
        }
        if (is_stopword(set, term)) {
            continue;
        }

        if (ct->second.tf_min_score < min) {
            min = ct->second.tf_min_score;
        }
        if (ct->second.tf_max_score > max) {
            max = ct->second.tf_max_score;
        }
    }

    return max / min;
}

/*
 * Simplified clarity score.
 *
 * He and Ounis. Inferring Query Performance Using Pre-retrieval Predictors,
 * SPIRE 2004.
 */
double scs_score(query_t &                                q,
                 std::unordered_map<std::string, size_t> &qmap,
                 std::unordered_map<std::string, term_t> &termmap,
                 std::set<std::string> &                  set) {
    size_t i;
    double score = 0.0;
    double p_ml  = 0.0;

    if (q.len_stopped) {
        return score;
    }

    for (i = 0; i < q.len; i++) {
        std::string term = q.terms[i];
        auto        qt   = qmap.find(term);
        if (qt == qmap.end()) {
            continue;
        }
        if (is_stopword(set, term)) {
            continue;
        }
        auto ct = termmap.find(term);
        if (ct == termmap.end()) {
            continue;
        }

        p_ml = (double)qt->second / q.len_stopped;
        score += p_ml * std::log2(p_ml / ((double)ct->second.cf / total_terms));
    }

    return score;
}

/*
 * Query scope
 *
 * V. Plachouras, I. Ounis, G. Amati, C. J. van Rijsbergen. University of
 * Glasgow at the Web Track: Dynamic application of hyperlink analysis using
 * the query scope.
 */
double query_scope(query_t &                                q,
                   std::unordered_map<std::string, term_t> &termmap,
                   std::set<std::string> &                  set) {
    size_t   i;
    uint64_t sum_cdf = 0;

    for (i = 0; i < q.len; i++) {
        std::string term = q.terms[i];
        auto        ct   = termmap.find(term);
        if (ct == termmap.end()) {
            continue;
        }
        if (is_stopword(set, term)) {
            continue;
        }

        sum_cdf += ct->second.cdf;
    }

    return (double)sum_cdf / total_docs;
}

/*
 * Compute AvIDF for the non-stopwords of the query and the full query.
 */
void avidf(query_t &                                q,
           std::unordered_map<std::string, term_t> &termmap,
           std::set<std::string> &                  set) {
    size_t i;
    double idf = 0.0, idf_full = 0.0;

    for (i = 0; i < q.len; i++) {
        std::string term = q.terms[i];
        auto        ct   = termmap.find(term);
        if (ct == termmap.end()) {
            continue;
        }
        if (is_stopword(set, term)) {
            idf_full += (std::log2(total_docs + 0.5) / ct->second.cdf) / std::log2(total_docs + 1);
            continue;
        }

        idf += (std::log2(total_docs + 0.5) / ct->second.cdf) / std::log2(total_docs + 1);
    }

    if (q.len_stopped) {
        q.avidf = idf / q.len_stopped;
    }
    q.avidf_full = idf_full / q.len;
}

/*
 * Compute AvICTF for the non-stopwords of the query and the full query.
 */
void avictf(query_t &                                q,
            std::unordered_map<std::string, term_t> &termmap,
            std::set<std::string> &                  set) {
    size_t i;
    double ictf = 0.0, ictf_full = 0.0;

    for (i = 0; i < q.len; i++) {
        std::string term = q.terms[i];
        auto        ct   = termmap.find(term);
        if (ct == termmap.end()) {
            continue;
        }
        if (is_stopword(set, term)) {
            ictf_full +=
                (std::log2(total_terms + 0.5) / ct->second.cf) / std::log2(total_terms + 1);
            continue;
        }

        ictf += (std::log2(total_terms + 0.5) / ct->second.cf) / std::log2(total_terms + 1);
    }

    if (q.len_stopped) {
        q.avictf = ictf / q.len_stopped;
    }
    q.avictf_full = ictf_full / q.len;
}
