#pragma once
#include <set>

// typedef struct {
//     std::string term;
//     int   count;
// } queryterm_t;

// typedef struct {
//     uint32_t      buckets;
//     uint32_t      items;
//     queryterm_t **array;
// } queryhash_t;

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

int q_stopped_len(std::set<std::string> &set, query_t *query);

double scs_score(query_t *q, std::unordered_map<std::string, size_t> &qmap, std::unordered_map<std::string, term_t> &termmap, std::set<std::string> &set);

double query_scope(query_t *q, std::unordered_map<std::string, term_t> &termmap, std::set<std::string> &set);

void gamma1(query_t *q, std::unordered_map<std::string, term_t> &termmap, std::set<std::string> &set);

double gamma2(query_t *q, std::unordered_map<std::string, term_t> &termmap, std::set<std::string> &set);

void avidf(query_t *q, std::unordered_map<std::string, term_t> &termmap, std::set<std::string> &set);

void avictf(query_t *q, std::unordered_map<std::string, term_t> &termmap, std::set<std::string> &set);


