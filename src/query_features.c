/*
 * Pre-retrieval query features:
 *
 *   * Query length of non-stop words in the query
 *   * Simplified clarity score
 *   * Std deviation of the IDF of the terms in query
 *   * Gamma2: IDF max / IDF min
 *   * Query scope
 *   * AvIDF on full query
 *   * AvIDF on non-stopwords in the query
 *   * AvICTF on full query
 *   * AvICTF on non-stopwords in the query
 */

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fgen_term_qry.h"
#include "query_features.h"

#define ZETA 1.960

stopword_t *find_stopword(stophash_t *termmap, const char *buf);

queryterm_t *find_queryterm(queryhash_t *termmap, const char *buf);

static int is_stopword(stophash_t *map, const char *term) {
    int         ret = 0;
    stopword_t *w   = find_stopword(map, term);
    if (w) {
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
int q_stopped_len(stophash_t *map, query_t *query) {
    int qlen = 0;

    for (size_t i = 0; i < query->len; ++i) {
        stopword_t *w = find_stopword(map, query->terms[i]);
        if (NULL == w) {
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
void gamma1(query_t *q, termhash_t *termmap, stophash_t *stopmap) {
    size_t i;
    double avg = 0.0, sum = 0.0, sum_sqrs = 0.0, variance = 0.0;
    double std_dev = 0.0, idf = 0.0;

    for (i = 0; i < q->len; i++) {
        char *  term = q->terms[i];
        term_t *ct   = find_term(termmap, term);
        if (!ct) {
            continue;
        }
        if (is_stopword(stopmap, term)) {
            continue;
        }

        idf = (log2(total_docs + 0.5) / ct->cdf) / log2(total_docs + 1);
        sum += idf;
        sum_sqrs += idf * idf;
    }

    if (q->len_stopped) {
        avg      = sum / q->len_stopped;
        variance = sum_sqrs / q->len_stopped - avg * avg;
        std_dev  = sqrt(variance);

        q->tfidf_avg        = avg;
        q->tfidf_variance   = variance;
        q->tfidf_std_dev    = std_dev;
        q->tfidf_confidence = ZETA * (q->tfidf_std_dev / (sqrt(q->len_stopped)));
    }
}

/*
 * The maximum and minimum IDF among the terms in query respectively.
 *
 * He and Ounis. Inferring Query Performance Using Pre-retrieval Predictors,
 * SPIRE 2004.
 */
double gamma2(query_t *q, termhash_t *termmap, stophash_t *stopmap) {
    size_t i;
    double min = DBL_MAX, max = 0.0;

    for (i = 0; i < q->len; i++) {
        char *  term = q->terms[i];
        term_t *ct   = find_term(termmap, term);
        if (!ct) {
            continue;
        }
        if (is_stopword(stopmap, term)) {
            continue;
        }

        if (ct->tf_min_score < min) {
            min = ct->tf_min_score;
        }
        if (ct->tf_max_score > max) {
            max = ct->tf_max_score;
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
double scs_score(query_t *q, queryhash_t *qmap, termhash_t *termmap, stophash_t *stopmap) {
    size_t i;
    double score = 0.0;
    double p_ml  = 0.0;

    if (q->len_stopped) {
        return score;
    }

    for (i = 0; i < q->len; i++) {
        char *       term = q->terms[i];
        queryterm_t *qt   = find_queryterm(qmap, term);
        if (!qt) {
            continue;
        }
        if (is_stopword(stopmap, term)) {
            continue;
        }
        term_t *ct = find_term(termmap, term);
        if (!ct) {
            continue;
        }

        p_ml = (double)qt->count / q->len_stopped;
        score += p_ml * log2(p_ml / ((double)ct->cf / total_terms));
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
double query_scope(query_t *q, termhash_t *termmap, stophash_t *stopmap) {
    size_t   i;
    uint64_t sum_cdf = 0;

    for (i = 0; i < q->len; i++) {
        char *  term = q->terms[i];
        term_t *ct   = find_term(termmap, term);
        if (!ct) {
            continue;
        }
        if (is_stopword(stopmap, term)) {
            continue;
        }

        sum_cdf += ct->cdf;
    }

    return (double)sum_cdf / total_docs;
}

/*
 * Compute AvIDF for the non-stopwords of the query and the full query.
 */
void avidf(query_t *q, termhash_t *termmap, stophash_t *stopmap) {
    size_t i;
    double idf = 0.0, idf_full = 0.0;

    for (i = 0; i < q->len; i++) {
        char *  term = q->terms[i];
        term_t *ct   = find_term(termmap, term);
        if (!ct) {
            continue;
        }
        if (is_stopword(stopmap, term)) {
            idf_full += (log2(total_docs + 0.5) / ct->cdf) / log2(total_docs + 1);
            continue;
        }

        idf += (log2(total_docs + 0.5) / ct->cdf) / log2(total_docs + 1);
    }

    if (q->len_stopped) {
        q->avidf = idf / q->len_stopped;
    }
    q->avidf_full = idf_full / q->len;
}

/*
 * Compute AvICTF for the non-stopwords of the query and the full query.
 */
void avictf(query_t *q, termhash_t *termmap, stophash_t *stopmap) {
    size_t i;
    double ictf = 0.0, ictf_full = 0.0;

    for (i = 0; i < q->len; i++) {
        char *  term = q->terms[i];
        term_t *ct   = find_term(termmap, term);
        if (!ct) {
            continue;
        }
        if (is_stopword(stopmap, term)) {
            ictf_full += (log2(total_terms + 0.5) / ct->cf) / log2(total_terms + 1);
            continue;
        }

        ictf += (log2(total_terms + 0.5) / ct->cf) / log2(total_terms + 1);
    }

    if (q->len_stopped) {
        q->avictf = ictf / q->len_stopped;
    }
    q->avictf_full = ictf_full / q->len;
}
