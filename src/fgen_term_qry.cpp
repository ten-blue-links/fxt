/*
 * Copyright 2018 The Tesserae authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

#include <inttypes.h>
#include <stdio.h>

#include "fgen_term_qry.hpp"
#include "query_features.h"
#include "tesserae/stopwords.h"

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

    // fprintf(stderr, "Number of terms loaded [%d]\n", num);
    fclose(input);
    return map;
}

const char **stopwords = fgen_krovetz_stopwords;

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

    // fprintf (stderr, "Number of stopwords loaded [%d]\n", num);
    return set;
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

static bool count_done    = false;
static int  feature_count = 0;
static void ffmt(std::stringstream &buf, long double val) {
    if (!count_done) {
        ++feature_count;
    }
    buf << "," << std::fixed << std::setprecision(5) << val;
}

std::string fgen_term_qry_main(std::unordered_map<std::string, term_t> &termmap,
                               std::string &                            qid,
                               char **                                  termv,
                               size_t                                   termc) {
    int               tcnt = 0, i = 0;
    std::stringstream buf;

    std::vector<term_t> terms(MAXTERM);

    /* pre-retrieval query features */
    auto stopmap      = load_stopmap();
    auto querymap     = load_querymap(termv, termc);
    auto query        = load_query(termv, termc);
    query.len_stopped = q_stopped_len(stopmap, query);
    query.scs_score   = scs_score(query, querymap, termmap, stopmap);
    query.scope_score = query_scope(query, termmap, stopmap);
    gamma1(query, termmap, stopmap);
    query.tfidf_gamma2 = gamma2(query, termmap, stopmap);
    avidf(query, termmap, stopmap);
    avictf(query, termmap, stopmap);

    std::string term;
    for (size_t j = 0; j < termc; ++j) {
        term    = termv[j];
        auto ct = termmap.find(term);
        if (ct != termmap.end()) {
            terms[tcnt].term                     = ct->second.term;
            terms[tcnt].cdf                      = ct->second.cdf;
            terms[tcnt].cf                       = ct->second.cf;
            terms[tcnt].geo_mean                 = ct->second.geo_mean;
            terms[tcnt].bm25_median_score        = ct->second.bm25_median_score;
            terms[tcnt].bm25_firstq_score        = ct->second.bm25_firstq_score;
            terms[tcnt].bm25_thirdq_score        = ct->second.bm25_thirdq_score;
            terms[tcnt].bm25_max_score           = ct->second.bm25_max_score;
            terms[tcnt].bm25_min_score           = ct->second.bm25_min_score;
            terms[tcnt].bm25_mean_score          = ct->second.bm25_mean_score;
            terms[tcnt].bm25_score_variance      = ct->second.bm25_score_variance;
            terms[tcnt].bm25_score_stddev        = ct->second.bm25_score_stddev;
            terms[tcnt].bm25_score_harmonic_mean = ct->second.bm25_score_harmonic_mean;
            terms[tcnt].tf_median_score          = ct->second.tf_median_score;
            terms[tcnt].tf_firstq_score          = ct->second.tf_firstq_score;
            terms[tcnt].tf_thirdq_score          = ct->second.tf_thirdq_score;
            terms[tcnt].tf_max_score             = ct->second.tf_max_score;
            terms[tcnt].tf_min_score             = ct->second.tf_min_score;
            terms[tcnt].tf_mean_score            = ct->second.tf_mean_score;
            terms[tcnt].tf_score_variance        = ct->second.tf_score_variance;
            terms[tcnt].tf_score_stddev          = ct->second.tf_score_stddev;
            terms[tcnt].tf_score_harmonic_mean   = ct->second.tf_score_harmonic_mean;
            terms[tcnt].lm_median_score          = ct->second.lm_median_score;
            terms[tcnt].lm_firstq_score          = ct->second.lm_firstq_score;
            terms[tcnt].lm_thirdq_score          = ct->second.lm_thirdq_score;
            terms[tcnt].lm_max_score             = ct->second.lm_max_score;
            terms[tcnt].lm_min_score             = ct->second.lm_min_score;
            terms[tcnt].lm_mean_score            = ct->second.lm_mean_score;
            terms[tcnt].lm_score_variance        = ct->second.lm_score_variance;
            terms[tcnt].lm_score_stddev          = ct->second.lm_score_stddev;
            terms[tcnt].lm_score_harmonic_mean   = ct->second.lm_score_harmonic_mean;
            terms[tcnt].dfr_median_score         = ct->second.dfr_median_score;
            terms[tcnt].dfr_firstq_score         = ct->second.dfr_firstq_score;
            terms[tcnt].dfr_thirdq_score         = ct->second.dfr_thirdq_score;
            terms[tcnt].dfr_max_score            = ct->second.dfr_max_score;
            terms[tcnt].dfr_min_score            = ct->second.dfr_min_score;
            terms[tcnt].dfr_mean_score           = ct->second.dfr_mean_score;
            terms[tcnt].dfr_score_variance       = ct->second.dfr_score_variance;
            terms[tcnt].dfr_score_stddev         = ct->second.dfr_score_stddev;
            terms[tcnt].dfr_score_harmonic_mean  = ct->second.dfr_score_harmonic_mean;
            terms[tcnt].dph_median_score         = ct->second.dph_median_score;
            terms[tcnt].dph_firstq_score         = ct->second.dph_firstq_score;
            terms[tcnt].dph_thirdq_score         = ct->second.dph_thirdq_score;
            terms[tcnt].dph_max_score            = ct->second.dph_max_score;
            terms[tcnt].dph_min_score            = ct->second.dph_min_score;
            terms[tcnt].dph_mean_score           = ct->second.dph_mean_score;
            terms[tcnt].dph_score_variance       = ct->second.dph_score_variance;
            terms[tcnt].dph_score_stddev         = ct->second.dph_score_stddev;
            terms[tcnt].dph_score_harmonic_mean  = ct->second.dph_score_harmonic_mean;
            terms[tcnt].be_median_score          = ct->second.be_median_score;
            terms[tcnt].be_firstq_score          = ct->second.be_firstq_score;
            terms[tcnt].be_thirdq_score          = ct->second.be_thirdq_score;
            terms[tcnt].be_max_score             = ct->second.be_max_score;
            terms[tcnt].be_min_score             = ct->second.be_min_score;
            terms[tcnt].be_mean_score            = ct->second.be_mean_score;
            terms[tcnt].be_score_variance        = ct->second.be_score_variance;
            terms[tcnt].be_score_stddev          = ct->second.be_score_stddev;
            terms[tcnt].be_score_harmonic_mean   = ct->second.be_score_harmonic_mean;
            terms[tcnt].pr_median_score          = ct->second.pr_median_score;
            terms[tcnt].pr_firstq_score          = ct->second.pr_firstq_score;
            terms[tcnt].pr_thirdq_score          = ct->second.pr_thirdq_score;
            terms[tcnt].pr_max_score             = ct->second.pr_max_score;
            terms[tcnt].pr_min_score             = ct->second.pr_min_score;
            terms[tcnt].pr_mean_score            = ct->second.pr_mean_score;
            terms[tcnt].pr_score_variance        = ct->second.pr_score_variance;
            terms[tcnt].pr_score_stddev          = ct->second.pr_score_stddev;
            terms[tcnt].pr_score_harmonic_mean   = ct->second.pr_score_harmonic_mean;
            tcnt++;
        } else {
            // printf ("TERM=%s not found.\n", term);
        }
    }

    if (tcnt == 0) {
        fprintf(stderr, "WARN: No terms for Query %s\n in collection.\n", qid.c_str());
        if (!count_done) {
            fprintf(stderr, "WARN: Can't fill zeros count not complete.\n");
        }
        int i;
        for (i = 0; i < feature_count; ++i) {
            ffmt(buf, 0);
        }
    } else {
        /* Do this for each metric - BM25*/
        ffmt(buf, tcnt);
        {
            long double acdf    = 0.0;
            double      agm     = 0.0;
            double      aimpact = 0.0;
            double      amean   = 0.0;
            double      amedian = 0.0;
            double      ahmean  = 0.0;
            double      avar    = 0.0;
            double      aiqr    = 0.0;

            double   min        = std::numeric_limits<double>::max();
            double   max        = 0.0;
            double   min_mean   = std::numeric_limits<double>::max();
            double   max_mean   = 0.0;
            double   min_hmean  = std::numeric_limits<double>::max();
            double   max_hmean  = 0.0;
            double   min_median = std::numeric_limits<double>::max();
            double   max_median = 0.0;
            double   min_fq     = std::numeric_limits<double>::max();
            double   max_fq     = 0.0;
            double   min_tq     = std::numeric_limits<double>::max();
            double   max_tq     = 0.0;
            double   min_var    = std::numeric_limits<double>::max();
            double   max_var    = 0.0;
            uint64_t cdf_max = 0, cdf_min = UINT64_MAX;
            double   gm_min = std::numeric_limits<double>::max();
            double   gm_max = 0.0;

            for (i = 0; i < tcnt; i++) {
                if (terms[i].bm25_max_score < min)
                    min = terms[i].bm25_max_score;
                if (terms[i].bm25_max_score > max)
                    max = terms[i].bm25_max_score;
                if (terms[i].bm25_mean_score < min_mean)
                    min_mean = terms[i].bm25_mean_score;
                if (terms[i].bm25_mean_score > max_mean)
                    max_mean = terms[i].bm25_mean_score;
                if (terms[i].bm25_score_harmonic_mean < min_hmean)
                    min_hmean = terms[i].bm25_score_harmonic_mean;
                if (terms[i].bm25_score_harmonic_mean > max_hmean)
                    max_hmean = terms[i].bm25_score_harmonic_mean;
                if (terms[i].bm25_median_score < min_median)
                    min_median = terms[i].bm25_median_score;
                if (terms[i].bm25_median_score > max_median)
                    max_median = terms[i].bm25_median_score;
                if (terms[i].bm25_firstq_score < min_fq)
                    min_fq = terms[i].bm25_firstq_score;
                if (terms[i].bm25_firstq_score > max_fq)
                    max_fq = terms[i].bm25_firstq_score;
                if (terms[i].bm25_thirdq_score < min_tq)
                    min_tq = terms[i].bm25_thirdq_score;
                if (terms[i].bm25_thirdq_score > max_tq)
                    max_tq = terms[i].bm25_thirdq_score;
                if (terms[i].bm25_score_variance < min_var)
                    min_var = terms[i].bm25_score_variance;
                if (terms[i].bm25_score_variance > max_var)
                    max_var = terms[i].bm25_score_variance;
                if (terms[i].cdf < cdf_min)
                    cdf_min = terms[i].cdf;
                if (terms[i].cdf > cdf_max)
                    cdf_max = terms[i].cdf;
                if (terms[i].geo_mean < gm_min)
                    gm_min = terms[i].geo_mean;
                if (terms[i].geo_mean > gm_max)
                    gm_max = terms[i].geo_mean;

                acdf += terms[i].cdf;
                agm += terms[i].geo_mean;
                aimpact += terms[i].bm25_max_score;
                amean += terms[i].bm25_mean_score;
                ahmean += terms[i].bm25_score_harmonic_mean;
                amedian += terms[i].bm25_median_score;
                avar += terms[i].bm25_score_variance;
                aiqr += (terms[i].bm25_firstq_score - terms[i].bm25_thirdq_score);
            }
            ffmt(buf, std::rintl(acdf / tcnt));
            ffmt(buf, agm / tcnt);
            ffmt(buf, aimpact / tcnt);
            ffmt(buf, amean / tcnt);
            ffmt(buf, ahmean / tcnt);
            ffmt(buf, amedian / tcnt);
            ffmt(buf, aiqr / tcnt);
            ffmt(buf, avar / tcnt);

            ffmt(buf, cdf_min);
            ffmt(buf, cdf_max);
            ffmt(buf, gm_min);
            ffmt(buf, gm_max);
            ffmt(buf, min);
            ffmt(buf, max);
            ffmt(buf, min_mean);
            ffmt(buf, max_mean);
            ffmt(buf, min_median);
            ffmt(buf, max_median);
            ffmt(buf, min_hmean);
            ffmt(buf, max_hmean);
            ffmt(buf, min_var);
            ffmt(buf, max_var);
            ffmt(buf, min_fq);
            ffmt(buf, max_fq);
            ffmt(buf, min_tq);
            ffmt(buf, max_tq);
        }
        /* Do this for each metric - TFIDF*/
        {
            double aimpact = 0.0;
            double amean   = 0.0;
            double amedian = 0.0;
            double ahmean  = 0.0;
            double avar    = 0.0;
            double aiqr    = 0.0;

            double min        = std::numeric_limits<double>::max();
            double max        = 0.0;
            double min_mean   = std::numeric_limits<double>::max();
            double max_mean   = 0.0;
            double min_hmean  = std::numeric_limits<double>::max();
            double max_hmean  = 0.0;
            double min_median = std::numeric_limits<double>::max();
            double max_median = 0.0;
            double min_fq     = std::numeric_limits<double>::max();
            double max_fq     = 0.0;
            double min_tq     = std::numeric_limits<double>::max();
            double max_tq     = 0.0;
            double min_var    = std::numeric_limits<double>::max();
            double max_var    = 0.0;

            for (i = 0; i < tcnt; i++) {
                if (terms[i].tf_max_score < min)
                    min = terms[i].tf_max_score;
                if (terms[i].tf_max_score > max)
                    max = terms[i].tf_max_score;
                if (terms[i].tf_mean_score < min_mean)
                    min_mean = terms[i].tf_mean_score;
                if (terms[i].tf_mean_score > max_mean)
                    max_mean = terms[i].tf_mean_score;
                if (terms[i].tf_score_harmonic_mean < min_hmean)
                    min_hmean = terms[i].tf_score_harmonic_mean;
                if (terms[i].tf_score_harmonic_mean > max_hmean)
                    max_hmean = terms[i].tf_score_harmonic_mean;
                if (terms[i].tf_median_score < min_median)
                    min_median = terms[i].tf_median_score;
                if (terms[i].tf_median_score > max_median)
                    max_median = terms[i].tf_median_score;
                if (terms[i].tf_firstq_score < min_fq)
                    min_fq = terms[i].tf_firstq_score;
                if (terms[i].tf_firstq_score > max_fq)
                    max_fq = terms[i].tf_firstq_score;
                if (terms[i].tf_thirdq_score < min_tq)
                    min_tq = terms[i].tf_thirdq_score;
                if (terms[i].tf_thirdq_score > max_tq)
                    max_tq = terms[i].tf_thirdq_score;
                if (terms[i].tf_score_variance < min_var)
                    min_var = terms[i].tf_score_variance;
                if (terms[i].tf_score_variance > max_var)
                    max_var = terms[i].tf_score_variance;

                aimpact += terms[i].tf_max_score;
                amean += terms[i].tf_mean_score;
                ahmean += terms[i].tf_score_harmonic_mean;
                amedian += terms[i].tf_median_score;
                avar += terms[i].tf_score_variance;
                aiqr += (terms[i].tf_firstq_score - terms[i].tf_thirdq_score);
            }
            ffmt(buf, aimpact / tcnt);
            ffmt(buf, amean / tcnt);
            ffmt(buf, ahmean / tcnt);
            ffmt(buf, amedian / tcnt);
            ffmt(buf, aiqr / tcnt);
            ffmt(buf, avar / tcnt);

            ffmt(buf, min);
            ffmt(buf, max);
            ffmt(buf, min_mean);
            ffmt(buf, max_mean);
            ffmt(buf, min_median);
            ffmt(buf, max_median);
            ffmt(buf, min_hmean);
            ffmt(buf, max_hmean);
            ffmt(buf, min_var);
            ffmt(buf, max_var);
            ffmt(buf, min_fq);
            ffmt(buf, max_fq);
            ffmt(buf, min_tq);
            ffmt(buf, max_tq);
        }
        /* Do this for each metric LM*/
        {
            double aimpact = 0.0;
            double amean   = 0.0;
            double amedian = 0.0;
            double ahmean  = 0.0;
            double avar    = 0.0;
            double aiqr    = 0.0;

            double min        = std::numeric_limits<double>::max();
            double max        = 0.0;
            double min_mean   = std::numeric_limits<double>::max();
            double max_mean   = 0.0;
            double min_hmean  = std::numeric_limits<double>::max();
            double max_hmean  = 0.0;
            double min_median = std::numeric_limits<double>::max();
            double max_median = 0.0;
            double min_fq     = std::numeric_limits<double>::max();
            double max_fq     = 0.0;
            double min_tq     = std::numeric_limits<double>::max();
            double max_tq     = 0.0;
            double min_var    = std::numeric_limits<double>::max();
            double max_var    = 0.0;

            for (i = 0; i < tcnt; i++) {
                if (terms[i].lm_max_score < min)
                    min = terms[i].lm_max_score;
                if (terms[i].lm_max_score > max)
                    max = terms[i].lm_max_score;
                if (terms[i].lm_mean_score < min_mean)
                    min_mean = terms[i].lm_mean_score;
                if (terms[i].lm_mean_score > max_mean)
                    max_mean = terms[i].lm_mean_score;
                if (terms[i].lm_score_harmonic_mean < min_hmean)
                    min_hmean = terms[i].lm_score_harmonic_mean;
                if (terms[i].lm_score_harmonic_mean > max_hmean)
                    max_hmean = terms[i].lm_score_harmonic_mean;
                if (terms[i].lm_median_score < min_median)
                    min_median = terms[i].lm_median_score;
                if (terms[i].lm_median_score > max_median)
                    max_median = terms[i].lm_median_score;
                if (terms[i].lm_firstq_score < min_fq)
                    min_fq = terms[i].lm_firstq_score;
                if (terms[i].lm_firstq_score > max_fq)
                    max_fq = terms[i].lm_firstq_score;
                if (terms[i].lm_thirdq_score < min_tq)
                    min_tq = terms[i].lm_thirdq_score;
                if (terms[i].lm_thirdq_score > max_tq)
                    max_tq = terms[i].lm_thirdq_score;
                if (terms[i].lm_score_variance < min_var)
                    min_var = terms[i].lm_score_variance;
                if (terms[i].lm_score_variance > max_var)
                    max_var = terms[i].lm_score_variance;

                aimpact += terms[i].lm_max_score;
                amean += terms[i].lm_mean_score;
                ahmean += terms[i].lm_score_harmonic_mean;
                amedian += terms[i].lm_median_score;
                avar += terms[i].lm_score_variance;
                aiqr += (terms[i].lm_firstq_score - terms[i].lm_thirdq_score);
            }
            ffmt(buf, aimpact / tcnt);
            ffmt(buf, amean / tcnt);
            ffmt(buf, ahmean / tcnt);
            ffmt(buf, amedian / tcnt);
            ffmt(buf, aiqr / tcnt);
            ffmt(buf, avar / tcnt);

            ffmt(buf, min);
            ffmt(buf, max);
            ffmt(buf, min_mean);
            ffmt(buf, max_mean);
            ffmt(buf, min_median);
            ffmt(buf, max_median);
            ffmt(buf, min_hmean);
            ffmt(buf, max_hmean);
            ffmt(buf, min_var);
            ffmt(buf, max_var);
            ffmt(buf, min_fq);
            ffmt(buf, max_fq);
            ffmt(buf, min_tq);
            ffmt(buf, max_tq);
        }
        /* Do this for each metric - PR*/
        {
            double aimpact = 0.0;
            double amean   = 0.0;
            double amedian = 0.0;
            double ahmean  = 0.0;
            double avar    = 0.0;
            double aiqr    = 0.0;

            double min        = std::numeric_limits<double>::max();
            double max        = 0.0;
            double min_mean   = std::numeric_limits<double>::max();
            double max_mean   = 0.0;
            double min_hmean  = std::numeric_limits<double>::max();
            double max_hmean  = 0.0;
            double min_median = std::numeric_limits<double>::max();
            double max_median = 0.0;
            double min_fq     = std::numeric_limits<double>::max();
            double max_fq     = 0.0;
            double min_tq     = std::numeric_limits<double>::max();
            double max_tq     = 0.0;
            double min_var    = std::numeric_limits<double>::max();
            double max_var    = 0.0;

            for (i = 0; i < tcnt; i++) {
                if (terms[i].pr_max_score < min)
                    min = terms[i].pr_max_score;
                if (terms[i].pr_max_score > max)
                    max = terms[i].pr_max_score;
                if (terms[i].pr_mean_score < min_mean)
                    min_mean = terms[i].pr_mean_score;
                if (terms[i].pr_mean_score > max_mean)
                    max_mean = terms[i].pr_mean_score;
                if (terms[i].pr_score_harmonic_mean < min_hmean)
                    min_hmean = terms[i].pr_score_harmonic_mean;
                if (terms[i].pr_score_harmonic_mean > max_hmean)
                    max_hmean = terms[i].pr_score_harmonic_mean;
                if (terms[i].pr_median_score < min_median)
                    min_median = terms[i].pr_median_score;
                if (terms[i].pr_median_score > max_median)
                    max_median = terms[i].pr_median_score;
                if (terms[i].pr_firstq_score < min_fq)
                    min_fq = terms[i].pr_firstq_score;
                if (terms[i].pr_firstq_score > max_fq)
                    max_fq = terms[i].pr_firstq_score;
                if (terms[i].pr_thirdq_score < min_tq)
                    min_tq = terms[i].pr_thirdq_score;
                if (terms[i].pr_thirdq_score > max_tq)
                    max_tq = terms[i].pr_thirdq_score;
                if (terms[i].pr_score_variance < min_var)
                    min_var = terms[i].pr_score_variance;
                if (terms[i].pr_score_variance > max_var)
                    max_var = terms[i].pr_score_variance;

                aimpact += terms[i].pr_max_score;
                amean += terms[i].pr_mean_score;
                ahmean += terms[i].pr_score_harmonic_mean;
                amedian += terms[i].pr_median_score;
                avar += terms[i].pr_score_variance;
                aiqr += (terms[i].pr_firstq_score - terms[i].pr_thirdq_score);
            }
            ffmt(buf, aimpact / tcnt);
            ffmt(buf, amean / tcnt);
            ffmt(buf, ahmean / tcnt);
            ffmt(buf, amedian / tcnt);
            ffmt(buf, aiqr / tcnt);
            ffmt(buf, avar / tcnt);

            ffmt(buf, min);
            ffmt(buf, max);
            ffmt(buf, min_mean);
            ffmt(buf, max_mean);
            ffmt(buf, min_median);
            ffmt(buf, max_median);
            ffmt(buf, min_hmean);
            ffmt(buf, max_hmean);
            ffmt(buf, min_var);
            ffmt(buf, max_var);
            ffmt(buf, min_fq);
            ffmt(buf, max_fq);
            ffmt(buf, min_tq);
            ffmt(buf, max_tq);
        }
        /* Do this for each metric - BE*/
        {
            double aimpact = 0.0;
            double amean   = 0.0;
            double amedian = 0.0;
            double ahmean  = 0.0;
            double avar    = 0.0;
            double aiqr    = 0.0;

            double min        = std::numeric_limits<double>::max();
            double max        = 0.0;
            double min_mean   = std::numeric_limits<double>::max();
            double max_mean   = 0.0;
            double min_hmean  = std::numeric_limits<double>::max();
            double max_hmean  = 0.0;
            double min_median = std::numeric_limits<double>::max();
            double max_median = 0.0;
            double min_fq     = std::numeric_limits<double>::max();
            double max_fq     = 0.0;
            double min_tq     = std::numeric_limits<double>::max();
            double max_tq     = 0.0;
            double min_var    = std::numeric_limits<double>::max();
            double max_var    = 0.0;

            for (i = 0; i < tcnt; i++) {
                if (terms[i].be_max_score < min)
                    min = terms[i].be_max_score;
                if (terms[i].be_max_score > max)
                    max = terms[i].be_max_score;
                if (terms[i].be_mean_score < min_mean)
                    min_mean = terms[i].be_mean_score;
                if (terms[i].be_mean_score > max_mean)
                    max_mean = terms[i].be_mean_score;
                if (terms[i].be_score_harmonic_mean < min_hmean)
                    min_hmean = terms[i].be_score_harmonic_mean;
                if (terms[i].be_score_harmonic_mean > max_hmean)
                    max_hmean = terms[i].be_score_harmonic_mean;
                if (terms[i].be_median_score < min_median)
                    min_median = terms[i].be_median_score;
                if (terms[i].be_median_score > max_median)
                    max_median = terms[i].be_median_score;
                if (terms[i].be_firstq_score < min_fq)
                    min_fq = terms[i].be_firstq_score;
                if (terms[i].be_firstq_score > max_fq)
                    max_fq = terms[i].be_firstq_score;
                if (terms[i].be_thirdq_score < min_tq)
                    min_tq = terms[i].be_thirdq_score;
                if (terms[i].be_thirdq_score > max_tq)
                    max_tq = terms[i].be_thirdq_score;
                if (terms[i].be_score_variance < min_var)
                    min_var = terms[i].be_score_variance;
                if (terms[i].be_score_variance > max_var)
                    max_var = terms[i].be_score_variance;

                aimpact += terms[i].be_max_score;
                amean += terms[i].be_mean_score;
                ahmean += terms[i].be_score_harmonic_mean;
                amedian += terms[i].be_median_score;
                avar += terms[i].be_score_variance;
                aiqr += (terms[i].be_firstq_score - terms[i].be_thirdq_score);
            }
            ffmt(buf, aimpact / tcnt);
            ffmt(buf, amean / tcnt);
            ffmt(buf, ahmean / tcnt);
            ffmt(buf, amedian / tcnt);
            ffmt(buf, aiqr / tcnt);
            ffmt(buf, avar / tcnt);

            ffmt(buf, min);
            ffmt(buf, max);
            ffmt(buf, min_mean);
            ffmt(buf, max_mean);
            ffmt(buf, min_median);
            ffmt(buf, max_median);
            ffmt(buf, min_hmean);
            ffmt(buf, max_hmean);
            ffmt(buf, min_var);
            ffmt(buf, max_var);
            ffmt(buf, min_fq);
            ffmt(buf, max_fq);
            ffmt(buf, min_tq);
            ffmt(buf, max_tq);
        }
        /* Do this for each metric - DPH*/
        {
            double aimpact = 0.0;
            double amean   = 0.0;
            double amedian = 0.0;
            double ahmean  = 0.0;
            double avar    = 0.0;
            double aiqr    = 0.0;

            double min        = std::numeric_limits<double>::max();
            double max        = 0.0;
            double min_mean   = std::numeric_limits<double>::max();
            double max_mean   = 0.0;
            double min_hmean  = std::numeric_limits<double>::max();
            double max_hmean  = 0.0;
            double min_median = std::numeric_limits<double>::max();
            double max_median = 0.0;
            double min_fq     = std::numeric_limits<double>::max();
            double max_fq     = 0.0;
            double min_tq     = std::numeric_limits<double>::max();
            double max_tq     = 0.0;
            double min_var    = std::numeric_limits<double>::max();
            double max_var    = 0.0;

            for (i = 0; i < tcnt; i++) {
                if (terms[i].dph_max_score < min)
                    min = terms[i].dph_max_score;
                if (terms[i].dph_max_score > max)
                    max = terms[i].dph_max_score;
                if (terms[i].dph_mean_score < min_mean)
                    min_mean = terms[i].dph_mean_score;
                if (terms[i].dph_mean_score > max_mean)
                    max_mean = terms[i].dph_mean_score;
                if (terms[i].dph_score_harmonic_mean < min_hmean)
                    min_hmean = terms[i].dph_score_harmonic_mean;
                if (terms[i].dph_score_harmonic_mean > max_hmean)
                    max_hmean = terms[i].dph_score_harmonic_mean;
                if (terms[i].dph_median_score < min_median)
                    min_median = terms[i].dph_median_score;
                if (terms[i].dph_median_score > max_median)
                    max_median = terms[i].dph_median_score;
                if (terms[i].dph_firstq_score < min_fq)
                    min_fq = terms[i].dph_firstq_score;
                if (terms[i].dph_firstq_score > max_fq)
                    max_fq = terms[i].dph_firstq_score;
                if (terms[i].dph_thirdq_score < min_tq)
                    min_tq = terms[i].dph_thirdq_score;
                if (terms[i].dph_thirdq_score > max_tq)
                    max_tq = terms[i].dph_thirdq_score;
                if (terms[i].dph_score_variance < min_var)
                    min_var = terms[i].dph_score_variance;
                if (terms[i].dph_score_variance > max_var)
                    max_var = terms[i].dph_score_variance;

                aimpact += terms[i].dph_max_score;
                amean += terms[i].dph_mean_score;
                ahmean += terms[i].dph_score_harmonic_mean;
                amedian += terms[i].dph_median_score;
                avar += terms[i].dph_score_variance;
                aiqr += (terms[i].dph_firstq_score - terms[i].dph_thirdq_score);
            }
            ffmt(buf, aimpact / tcnt);
            ffmt(buf, amean / tcnt);
            ffmt(buf, ahmean / tcnt);
            ffmt(buf, amedian / tcnt);
            ffmt(buf, aiqr / tcnt);
            ffmt(buf, avar / tcnt);

            ffmt(buf, min);
            ffmt(buf, max);
            ffmt(buf, 0); //
            ffmt(buf, max_mean);
            ffmt(buf, min_median);
            ffmt(buf, max_median);
            ffmt(buf, 0); //
            ffmt(buf, max_hmean);
            ffmt(buf, 0); //
            ffmt(buf, max_var);
            ffmt(buf, min_fq);
            ffmt(buf, max_fq);
            ffmt(buf, min_tq);
            ffmt(buf, max_tq);
        }
        /* Do this for each metric - DFR*/
        {
            double aimpact = 0.0;
            double amean   = 0.0;
            double amedian = 0.0;
            double ahmean  = 0.0;
            double avar    = 0.0;
            double aiqr    = 0.0;

            double min        = std::numeric_limits<double>::max();
            double max        = 0.0;
            double min_mean   = std::numeric_limits<double>::max();
            double max_mean   = 0.0;
            double min_hmean  = std::numeric_limits<double>::max();
            double max_hmean  = 0.0;
            double min_median = std::numeric_limits<double>::max();
            double max_median = 0.0;
            double min_fq     = std::numeric_limits<double>::max();
            double max_fq     = 0.0;
            double min_tq     = std::numeric_limits<double>::max();
            double max_tq     = 0.0;
            double min_var    = std::numeric_limits<double>::max();
            double max_var    = 0.0;

            for (i = 0; i < tcnt; i++) {
                if (terms[i].dfr_max_score < min)
                    min = terms[i].dfr_max_score;
                if (terms[i].dfr_max_score > max)
                    max = terms[i].dfr_max_score;
                if (terms[i].dfr_mean_score < min_mean)
                    min_mean = terms[i].dfr_mean_score;
                if (terms[i].dfr_mean_score > max_mean)
                    max_mean = terms[i].dfr_mean_score;
                if (terms[i].dfr_score_harmonic_mean < min_hmean)
                    min_hmean = terms[i].dfr_score_harmonic_mean;
                if (terms[i].dfr_score_harmonic_mean > max_hmean)
                    max_hmean = terms[i].dfr_score_harmonic_mean;
                if (terms[i].dfr_median_score < min_median)
                    min_median = terms[i].dfr_median_score;
                if (terms[i].dfr_median_score > max_median)
                    max_median = terms[i].dfr_median_score;
                if (terms[i].dfr_firstq_score < min_fq)
                    min_fq = terms[i].dfr_firstq_score;
                if (terms[i].dfr_firstq_score > max_fq)
                    max_fq = terms[i].dfr_firstq_score;
                if (terms[i].dfr_thirdq_score < min_tq)
                    min_tq = terms[i].dfr_thirdq_score;
                if (terms[i].dfr_thirdq_score > max_tq)
                    max_tq = terms[i].dfr_thirdq_score;
                if (terms[i].dfr_score_variance < min_var)
                    min_var = terms[i].dfr_score_variance;
                if (terms[i].dfr_score_variance > max_var)
                    max_var = terms[i].dfr_score_variance;

                aimpact += terms[i].dfr_max_score;
                amean += terms[i].dfr_mean_score;
                ahmean += terms[i].dfr_score_harmonic_mean;
                amedian += terms[i].dfr_median_score;
                avar += terms[i].dfr_score_variance;
                aiqr += (terms[i].dfr_firstq_score - terms[i].dfr_thirdq_score);
            }
            ffmt(buf, aimpact / tcnt);
            ffmt(buf, amean / tcnt);
            ffmt(buf, ahmean / tcnt);
            ffmt(buf, amedian / tcnt);
            ffmt(buf, aiqr / tcnt);
            ffmt(buf, avar / tcnt);

            ffmt(buf, min);
            ffmt(buf, max);
            ffmt(buf, min_mean);
            ffmt(buf, max_mean);
            ffmt(buf, min_median);
            ffmt(buf, max_median);
            ffmt(buf, min_hmean);
            ffmt(buf, max_hmean);
            ffmt(buf, min_var);
            ffmt(buf, max_var);
            ffmt(buf, min_fq);
            ffmt(buf, max_fq);
            ffmt(buf, min_tq);
            ffmt(buf, max_tq);
        }

        /* pre-retrieval query features */
        ffmt(buf, query.len_stopped);
        ffmt(buf, query.scs_score);
        ffmt(buf, query.scope_score);
        ffmt(buf, query.tfidf_avg);
        ffmt(buf, query.tfidf_variance);
        ffmt(buf, query.tfidf_std_dev);
        ffmt(buf, query.tfidf_confidence);
        ffmt(buf, query.tfidf_gamma2);
        ffmt(buf, query.avidf);
        ffmt(buf, query.avidf_full);
        ffmt(buf, query.avictf);
        ffmt(buf, query.avictf_full);
    }

    if (!count_done) {
        count_done = true;
    }

    return buf.str();
}
