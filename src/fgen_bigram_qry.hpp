#pragma once

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "fgen_term_qry.hpp"

static bool count_done    = false;
static int  feature_count = 0;
static void ffmt(std::stringstream &buf, long double val) {
    if (!count_done) {
        ++feature_count;
    }
    buf << "," << std::fixed << std::setprecision(5) << val;
}

std::string fgen_bigram_qry_main(std::unordered_map<std::string, term_t> &bigrammap,
                                 int                                      qnum,
                                 char **                                  termv,
                                 size_t                                   termc) {
    int               tcnt = 0, i = 0;
    int               num_bigrams = termc * termc - termc;
    std::stringstream buf;

    if (MAXTERM < num_bigrams) {
        fprintf(stderr, "Too many bigrams: %d\n", num_bigrams);
        exit(EXIT_FAILURE);
    }

    std::vector<term_t> terms(MAXTERM);

    for (size_t j = 0; j < termc; ++j) {
        for (size_t k = 0; k < termc; ++k) {
            if (j == k)
                continue;
            std::string bigram = std::string(termv[j]) + "," + std::string(termv[k]);
            auto        ct     = bigrammap.find(bigram);
            if (ct != bigrammap.end()) {
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
    }

    if (tcnt == 0) {
        fprintf(stderr, "WARN: No bigrams for Query %d\n in collection.\n", qnum);
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
    }

    if (!count_done) {
        count_done = true;
    }

    return buf.str();
}
