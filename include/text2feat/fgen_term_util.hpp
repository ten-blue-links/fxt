/*
 * Copyright 2018 The text2feat authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#pragma once

#include "text2feat/stopwords.h"
#include <set>

const char **         stopwords = fgen_krovetz_stopwords;
std::set<std::string> load_stopmap(void) {
    std::set<std::string> set;
    int                   i, num = 0;

    for (i = 0; stopwords[i] != NULL; i++) {
        auto curr = set.find(stopwords[i]);
        if (curr != set.end()) {
            fprintf(stderr, "ERROR: Duplicate stopword <%s>!\n", stopwords[i]);
            exit(EXIT_FAILURE);
        } else {
            set.insert(stopwords[i]);
        }
        num++;
    }

    return set;
}

std::unordered_map<std::string, term_t> load_termmap(const char *fname) {
    std::unordered_map<std::string, term_t> map;
    FILE *                                  input = NULL;
    char                                    d_str[1024];
    uint64_t                                cf;
    uint64_t                                cdf;
    double                                  geo_mean;
    int                                     num = 0;

    double bm25_median_score;
    double bm25_firstq_score;
    double bm25_thirdq_score;
    double bm25_max_score;
    double bm25_min_score;
    double bm25_mean_score;
    double bm25_score_variance;
    double bm25_score_stddev;
    double bm25_score_confidence;
    double bm25_score_harmonic_mean;

    double tf_median_score;
    double tf_firstq_score;
    double tf_thirdq_score;
    double tf_max_score;
    double tf_min_score;
    double tf_mean_score;
    double tf_score_variance;
    double tf_score_stddev;
    double tf_score_confidence;
    double tf_score_harmonic_mean;

    double lm_median_score;
    double lm_firstq_score;
    double lm_thirdq_score;
    double lm_max_score;
    double lm_min_score;
    double lm_mean_score;
    double lm_score_variance;
    double lm_score_stddev;
    double lm_score_confidence;
    double lm_score_harmonic_mean;

    double dfr_median_score;
    double dfr_firstq_score;
    double dfr_thirdq_score;
    double dfr_max_score;
    double dfr_min_score;
    double dfr_mean_score;
    double dfr_score_variance;
    double dfr_score_stddev;
    double dfr_score_confidence;
    double dfr_score_harmonic_mean;

    double dph_median_score;
    double dph_firstq_score;
    double dph_thirdq_score;
    double dph_max_score;
    double dph_min_score;
    double dph_mean_score;
    double dph_score_variance;
    double dph_score_stddev;
    double dph_score_confidence;
    double dph_score_harmonic_mean;

    double be_median_score;
    double be_firstq_score;
    double be_thirdq_score;
    double be_max_score;
    double be_min_score;
    double be_mean_score;
    double be_score_variance;
    double be_score_stddev;
    double be_score_confidence;
    double be_score_harmonic_mean;

    double pr_median_score;
    double pr_firstq_score;
    double pr_thirdq_score;
    double pr_max_score;
    double pr_min_score;
    double pr_mean_score;
    double pr_score_variance;
    double pr_score_stddev;
    double pr_score_confidence;
    double pr_score_harmonic_mean;

    if ((input = fopen(fname, "rb")) == NULL) {
        fprintf(stderr, "fopen(%s)\n", fname);
        exit(EXIT_FAILURE);
    }

    while (fscanf(input,
                  "%s %" SCNu64 " %" SCNu64
                  " %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf "
                  "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf "
                  "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf "
                  "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf "
                  "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n",
                  d_str,
                  &cf,
                  &cdf,
                  &geo_mean,
                  &bm25_median_score,
                  &bm25_firstq_score,
                  &bm25_thirdq_score,
                  &bm25_max_score,
                  &bm25_min_score,
                  &bm25_mean_score,
                  &bm25_score_variance,
                  &bm25_score_stddev,
                  &bm25_score_confidence,
                  &bm25_score_harmonic_mean,
                  &tf_median_score,
                  &tf_firstq_score,
                  &tf_thirdq_score,
                  &tf_max_score,
                  &tf_min_score,
                  &tf_mean_score,
                  &tf_score_variance,
                  &tf_score_stddev,
                  &tf_score_confidence,
                  &tf_score_harmonic_mean,
                  &lm_median_score,
                  &lm_firstq_score,
                  &lm_thirdq_score,
                  &lm_max_score,
                  &lm_min_score,
                  &lm_mean_score,
                  &lm_score_variance,
                  &lm_score_stddev,
                  &lm_score_confidence,
                  &lm_score_harmonic_mean,
                  &pr_median_score,
                  &pr_firstq_score,
                  &pr_thirdq_score,
                  &pr_max_score,
                  &pr_min_score,
                  &pr_mean_score,
                  &pr_score_variance,
                  &pr_score_stddev,
                  &pr_score_confidence,
                  &pr_score_harmonic_mean,
                  &be_median_score,
                  &be_firstq_score,
                  &be_thirdq_score,
                  &be_max_score,
                  &be_min_score,
                  &be_mean_score,
                  &be_score_variance,
                  &be_score_stddev,
                  &be_score_confidence,
                  &be_score_harmonic_mean,
                  &dph_median_score,
                  &dph_firstq_score,
                  &dph_thirdq_score,
                  &dph_max_score,
                  &dph_min_score,
                  &dph_mean_score,
                  &dph_score_variance,
                  &dph_score_stddev,
                  &dph_score_confidence,
                  &dph_score_harmonic_mean,
                  &dfr_median_score,
                  &dfr_firstq_score,
                  &dfr_thirdq_score,
                  &dfr_max_score,
                  &dfr_min_score,
                  &dfr_mean_score,
                  &dfr_score_variance,
                  &dfr_score_stddev,
                  &dfr_score_confidence,
                  &dfr_score_harmonic_mean) == 74) {
        auto it = map.find(d_str);
        if (it != map.end()) {
            fprintf(stderr, "ERROR: Duplicate term <%s>!\n", d_str);
            exit(EXIT_FAILURE);
        } else {
            term_t curr;
            curr.term     = d_str;
            curr.cf       = cf;
            curr.cdf      = cdf;
            curr.geo_mean = geo_mean;

            curr.bm25_median_score        = bm25_median_score;
            curr.bm25_firstq_score        = bm25_firstq_score;
            curr.bm25_thirdq_score        = bm25_thirdq_score;
            curr.bm25_max_score           = bm25_max_score;
            curr.bm25_min_score           = bm25_min_score;
            curr.bm25_mean_score          = bm25_mean_score;
            curr.bm25_score_variance      = bm25_score_variance;
            curr.bm25_score_stddev        = bm25_score_stddev;
            curr.bm25_score_harmonic_mean = bm25_score_harmonic_mean;

            curr.tf_median_score        = tf_median_score;
            curr.tf_firstq_score        = tf_firstq_score;
            curr.tf_thirdq_score        = tf_thirdq_score;
            curr.tf_max_score           = tf_max_score;
            curr.tf_min_score           = tf_min_score;
            curr.tf_mean_score          = tf_mean_score;
            curr.tf_score_variance      = tf_score_variance;
            curr.tf_score_stddev        = tf_score_stddev;
            curr.tf_score_harmonic_mean = tf_score_harmonic_mean;
            curr.lm_median_score        = lm_median_score;
            curr.lm_firstq_score        = lm_firstq_score;
            curr.lm_thirdq_score        = lm_thirdq_score;
            curr.lm_max_score           = lm_max_score;
            curr.lm_min_score           = lm_min_score;
            curr.lm_mean_score          = lm_mean_score;
            curr.lm_score_variance      = lm_score_variance;
            curr.lm_score_stddev        = lm_score_stddev;
            curr.lm_score_harmonic_mean = lm_score_harmonic_mean;

            curr.pr_median_score        = pr_median_score;
            curr.pr_firstq_score        = pr_firstq_score;
            curr.pr_thirdq_score        = pr_thirdq_score;
            curr.pr_max_score           = pr_max_score;
            curr.pr_min_score           = pr_min_score;
            curr.pr_mean_score          = pr_mean_score;
            curr.pr_score_variance      = pr_score_variance;
            curr.pr_score_stddev        = pr_score_stddev;
            curr.pr_score_harmonic_mean = pr_score_harmonic_mean;

            curr.be_median_score        = be_median_score;
            curr.be_firstq_score        = be_firstq_score;
            curr.be_thirdq_score        = be_thirdq_score;
            curr.be_max_score           = be_max_score;
            curr.be_min_score           = be_min_score;
            curr.be_mean_score          = be_mean_score;
            curr.be_score_variance      = be_score_variance;
            curr.be_score_stddev        = be_score_stddev;
            curr.be_score_harmonic_mean = be_score_harmonic_mean;

            curr.dph_median_score        = dph_median_score;
            curr.dph_firstq_score        = dph_firstq_score;
            curr.dph_thirdq_score        = dph_thirdq_score;
            curr.dph_max_score           = dph_max_score;
            curr.dph_min_score           = dph_min_score;
            curr.dph_mean_score          = dph_mean_score;
            curr.dph_score_variance      = dph_score_variance;
            curr.dph_score_stddev        = dph_score_stddev;
            curr.dph_score_harmonic_mean = dph_score_harmonic_mean;

            curr.dfr_median_score        = dfr_median_score;
            curr.dfr_firstq_score        = dfr_firstq_score;
            curr.dfr_thirdq_score        = dfr_thirdq_score;
            curr.dfr_max_score           = dfr_max_score;
            curr.dfr_min_score           = dfr_min_score;
            curr.dfr_mean_score          = dfr_mean_score;
            curr.dfr_score_variance      = dfr_score_variance;
            curr.dfr_score_stddev        = dfr_score_stddev;
            curr.dfr_score_harmonic_mean = dfr_score_harmonic_mean;

            map[curr.term] = curr;
        }
        num++;
    }

    fclose(input);
    return map;
}

std::unordered_map<std::string, size_t> load_querymap(char **termv, size_t len) {
    std::unordered_map<std::string, size_t> map;

    for (size_t i = 0; i < len; ++i) {
        auto curr = map.find(termv[i]);
        if (curr != map.end()) {
            ++curr->second;
        } else {
            map[termv[i]] = 1;
        }
    }

    return map;
}

query_t load_query(char **termv, size_t len) {
    query_t q;
    for (size_t i = 0; i < len; ++i) {
        q.terms.push_back(termv[i]);
    }
    q.len = len;
    return q;
}
