/*
 * Pre-retrieval query features.
 */

#ifndef QUERY_FEATURES_H
#define QUERY_FEATURES_H
#include "fgen_term_qry.hpp"
#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    char *term;
} stopword_t;

typedef struct {
    uint32_t     buckets;
    uint32_t     items;
    stopword_t **array;
} stophash_t;

typedef struct {
    char *term;
    int   count;
} queryterm_t;

typedef struct {
    uint32_t      buckets;
    uint32_t      items;
    queryterm_t **array;
} queryhash_t;

typedef struct {
    char * qry;
    char **terms;
    size_t len;
    size_t len_stopped;
    double scs_score;
    double scope_score;
    double tfidf_avg;
    double tfidf_variance;
    double tfidf_std_dev;
    double tfidf_confidence;
    double tfidf_gamma2;
    double avidf;
    double avidf_full;
    double avictf;
    double avictf_full;
} query_t;

void query_features_init(uint64_t num_docs, uint64_t num_terms);

int q_stopped_len(stophash_t *map, query_t *query);

double scs_score(query_t *q, queryhash_t *qmap, std::unordered_map<std::string, term_t> &termmap, stophash_t *stopmap);

double query_scope(query_t *q, std::unordered_map<std::string, term_t> &termmap, stophash_t *stopmap);

void gamma1(query_t *q, std::unordered_map<std::string, term_t> &termmap, stophash_t *stopmap);

double gamma2(query_t *q, std::unordered_map<std::string, term_t> &termmap, stophash_t *stopmap);

void avidf(query_t *q, std::unordered_map<std::string, term_t> &termmap, stophash_t *stopmap);

void avictf(query_t *q, std::unordered_map<std::string, term_t> &termmap, stophash_t *stopmap);

#ifdef __cplusplus
}
#endif

#endif
