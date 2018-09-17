#pragma once
#include <set>
#include <vector>

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
    std::string qry;
    std::vector<std::string> terms;
    size_t len = 0;
    size_t len_stopped = 0;
    double scs_score = 0.0;
    double scope_score = 0.0;
    double tfidf_avg = 0.0;
    double tfidf_variance = 0.0;
    double tfidf_std_dev = 0.0;
    double tfidf_confidence = 0.0;
    double tfidf_gamma2 = 0.0;
    double avidf = 0.0;
    double avidf_full = 0.0;
    double avictf = 0.0;
    double avictf_full = 0.0;
} query_t;

void query_features_init(uint64_t num_docs, uint64_t num_terms);

int q_stopped_len(std::set<std::string> &set, query_t &query);

double scs_score(query_t &q, std::unordered_map<std::string, size_t> &qmap, std::unordered_map<std::string, term_t> &termmap, std::set<std::string> &set);

double query_scope(query_t &q, std::unordered_map<std::string, term_t> &termmap, std::set<std::string> &set);

void gamma1(query_t &q, std::unordered_map<std::string, term_t> &termmap, std::set<std::string> &set);

double gamma2(query_t &q, std::unordered_map<std::string, term_t> &termmap, std::set<std::string> &set);

void avidf(query_t &q, std::unordered_map<std::string, term_t> &termmap, std::set<std::string> &set);

void avictf(query_t &q, std::unordered_map<std::string, term_t> &termmap, std::set<std::string> &set);


