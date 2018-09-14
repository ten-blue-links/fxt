#pragma once

#include <algorithm>
#include <chrono>
#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <utility>
#include <vector>

struct doc_entry {

    // doc id for convenience
    int id = 0;

    size_t length = 0;

    double pagerank = 0;
    // Score from training trec run file
    double stage0_score = 0;
    // BM25 Atire
    double bm25_atire         = 0;
    double bm25_atire_body    = 0;
    double bm25_atire_title   = 0;
    double bm25_atire_heading = 0;
    double bm25_atire_inlink  = 0;
    double bm25_atire_a       = 0;
    // BM25 TREC3 k = 1.2, b = 0.75
    double bm25_trec3         = 0;
    double bm25_trec3_body    = 0;
    double bm25_trec3_title   = 0;
    double bm25_trec3_heading = 0;
    double bm25_trec3_inlink  = 0;
    double bm25_trec3_a       = 0;
    // BM25 TREC3 k = 2.0, b = 0.75
    double bm25_trec3_kmax         = 0;
    double bm25_trec3_kmax_body    = 0;
    double bm25_trec3_kmax_title   = 0;
    double bm25_trec3_kmax_heading = 0;
    double bm25_trec3_kmax_inlink  = 0;
    double bm25_trec3_kmax_a       = 0;
    // QL mu = 2500
    double lm_dir_2500         = 0;
    double lm_dir_2500_body    = 0;
    double lm_dir_2500_title   = 0;
    double lm_dir_2500_heading = 0;
    double lm_dir_2500_inlink  = 0;
    double lm_dir_2500_a       = 0;
    // QL mu = 1500
    double lm_dir_1500         = 0;
    double lm_dir_1500_body    = 0;
    double lm_dir_1500_title   = 0;
    double lm_dir_1500_heading = 0;
    double lm_dir_1500_inlink  = 0;
    double lm_dir_1500_a       = 0;
    // QL mu = 1000
    double lm_dir_1000         = 0;
    double lm_dir_1000_body    = 0;
    double lm_dir_1000_title   = 0;
    double lm_dir_1000_heading = 0;
    double lm_dir_1000_inlink  = 0;
    double lm_dir_1000_a       = 0;
    // tfidf
    double tfidf         = 0;
    double tfidf_body    = 0;
    double tfidf_title   = 0;
    double tfidf_heading = 0;
    double tfidf_inlink  = 0;
    double tfidf_a       = 0;
    // Probability
    double prob         = 0;
    double prob_body    = 0;
    double prob_title   = 0;
    double prob_heading = 0;
    double prob_inlink  = 0;
    double prob_a       = 0;
    // DFR: Bose-Einstien
    double be         = 0;
    double be_body    = 0;
    double be_title   = 0;
    double be_heading = 0;
    double be_inlink  = 0;
    double be_a       = 0;
    // DFR: DPH
    double dph         = 0;
    double dph_body    = 0;
    double dph_title   = 0;
    double dph_heading = 0;
    double dph_inlink  = 0;
    double dph_a       = 0;
    // DFR: BB2
    double dfr         = 0;
    double dfr_body    = 0;
    double dfr_title   = 0;
    double dfr_heading = 0;
    double dfr_inlink  = 0;
    double dfr_a       = 0;
    // Stream
    double stream_len         = 0;
    double stream_len_body    = 0;
    double stream_len_title   = 0;
    double stream_len_heading = 0;
    double stream_len_inlink  = 0;
    double stream_len_a       = 0;
    // Stream sum normalised by tf
    double sum_stream_len         = 0;
    double sum_stream_len_body    = 0;
    double sum_stream_len_title   = 0;
    double sum_stream_len_heading = 0;
    double sum_stream_len_inlink  = 0;
    double sum_stream_len_a       = 0;
    // Stream min normalised by tf
    double min_stream_len         = 0;
    double min_stream_len_body    = 0;
    double min_stream_len_title   = 0;
    double min_stream_len_heading = 0;
    double min_stream_len_inlink  = 0;
    double min_stream_len_a       = 0;
    // Stream max normalised by tf
    double max_stream_len         = 0;
    double max_stream_len_body    = 0;
    double max_stream_len_title   = 0;
    double max_stream_len_heading = 0;
    double max_stream_len_inlink  = 0;
    double max_stream_len_a       = 0;
    // Stream mean normalised by tf
    double mean_stream_len         = 0;
    double mean_stream_len_body    = 0;
    double mean_stream_len_title   = 0;
    double mean_stream_len_heading = 0;
    double mean_stream_len_inlink  = 0;
    double mean_stream_len_a       = 0;
    // Stream variance normalised by tf
    double variance_stream_len         = 0;
    double variance_stream_len_body    = 0;
    double variance_stream_len_title   = 0;
    double variance_stream_len_heading = 0;
    double variance_stream_len_inlink  = 0;
    double variance_stream_len_a       = 0;

    // TP-Score
    double tpscore = 0;

    // BM25 bigram unordered window score (sum of unigram scores)
    double bm25_bigram_u8 = 0;
    // BM25 score of bigram intervals in window (Lu, et al.)
    double bm25_tp_dist_w100 = 0;

    // The frequency of query terms within the <title> tag
    size_t tag_title_qry_count = 0;
    // The frequency of query terms within the <heading> tag
    size_t tag_heading_qry_count = 0;
    // The frequency of query terms within the <mainbody> tag
    size_t tag_mainbody_qry_count = 0;
    // The frequency of query terms within the inlinks
    size_t tag_inlink_qry_count = 0;

    // The number of times the <title> tag appears in the document
    int tag_title_count = 0;
    // The number of times the <heading> tag appears in the document
    int tag_heading_count = 0; // Indri heading field includes tags h1-h4
    // The number of inlinks in the document
    int tag_inlink_count = 0;
    // The number of times the <applet> tag appears in the document
    int tag_applet_count = 0;
    // The number of times the <object> tag appears in the document
    int tag_object_count = 0;
    // The number of times the <embed> tag appears in the document
    int tag_embed_count = 0;

    // Number of slashes in URL
    int url_slash_count = 0;
    // URL length
    size_t url_length = 0;

    doc_entry(int i, double pr)
        : id(i), pagerank(pr) {}

    friend std::ostream &operator<<(std::ostream &os, const doc_entry &de);
};

std::ostream &operator<<(std::ostream &os, const doc_entry &de) {
    os << "," << de.pagerank;
    os << "," << de.stage0_score;
    os << "," << de.bm25_atire;
    os << "," << de.bm25_atire_body;
    os << "," << de.bm25_atire_title;
    os << "," << de.bm25_atire_heading;
    os << "," << de.bm25_atire_inlink;
    os << "," << de.bm25_atire_a;
    os << "," << de.bm25_trec3;
    os << "," << de.bm25_trec3_body;
    os << "," << de.bm25_trec3_title;
    os << "," << de.bm25_trec3_heading;
    os << "," << de.bm25_trec3_inlink;
    os << "," << de.bm25_trec3_a;
    os << "," << de.bm25_trec3_kmax;
    os << "," << de.bm25_trec3_kmax_body;
    os << "," << de.bm25_trec3_kmax_title;
    os << "," << de.bm25_trec3_kmax_heading;
    os << "," << de.bm25_trec3_kmax_inlink;
    os << "," << de.bm25_trec3_kmax_a;
    os << "," << de.bm25_bigram_u8;
    os << "," << de.bm25_tp_dist_w100;
    os << "," << de.tpscore;
    os << "," << de.lm_dir_2500;
    os << "," << de.lm_dir_2500_body;
    os << "," << de.lm_dir_2500_title;
    os << "," << de.lm_dir_2500_heading;
    os << "," << de.lm_dir_2500_inlink;
    os << "," << de.lm_dir_2500_a;
    os << "," << de.lm_dir_1500;
    os << "," << de.lm_dir_1500_body;
    os << "," << de.lm_dir_1500_title;
    os << "," << de.lm_dir_1500_heading;
    os << "," << de.lm_dir_1500_inlink;
    os << "," << de.lm_dir_1500_a;
    os << "," << de.lm_dir_1000;
    os << "," << de.lm_dir_1000_body;
    os << "," << de.lm_dir_1000_title;
    os << "," << de.lm_dir_1000_heading;
    os << "," << de.lm_dir_1000_inlink;
    os << "," << de.lm_dir_1000_a;
    os << "," << de.tfidf;
    os << "," << de.tfidf_body;
    os << "," << de.tfidf_title;
    os << "," << de.tfidf_heading;
    os << "," << de.tfidf_inlink;
    os << "," << de.tfidf_a;
    os << "," << de.prob;
    os << "," << de.prob_body;
    os << "," << de.prob_title;
    os << "," << de.prob_heading;
    os << "," << de.prob_inlink;
    os << "," << de.prob_a;
    os << "," << de.be;
    os << "," << de.be_body;
    os << "," << de.be_title;
    os << "," << de.be_heading;
    os << "," << de.be_inlink;
    os << "," << de.be_a;
    os << "," << de.dph;
    os << "," << de.dph_body;
    os << "," << de.dph_title;
    os << "," << de.dph_heading;
    os << "," << de.dph_inlink;
    os << "," << de.dph_a;
    os << "," << de.dfr;
    os << "," << de.dfr_body;
    os << "," << de.dfr_title;
    os << "," << de.dfr_heading;
    os << "," << de.dfr_inlink;
    os << "," << de.dfr_a;
    os << "," << de.stream_len;
    os << "," << de.stream_len_body;
    os << "," << de.stream_len_title;
    os << "," << de.stream_len_heading;
    os << "," << de.stream_len_inlink;
    os << "," << de.stream_len_a;
    os << "," << de.sum_stream_len;
    os << "," << de.sum_stream_len_body;
    os << "," << de.sum_stream_len_title;
    os << "," << de.sum_stream_len_heading;
    os << "," << de.sum_stream_len_inlink;
    os << "," << de.sum_stream_len_a;
    os << "," << de.min_stream_len;
    os << "," << de.min_stream_len_body;
    os << "," << de.min_stream_len_title;
    os << "," << de.min_stream_len_heading;
    os << "," << de.min_stream_len_inlink;
    os << "," << de.min_stream_len_a;
    os << "," << de.max_stream_len;
    os << "," << de.max_stream_len_body;
    os << "," << de.max_stream_len_title;
    os << "," << de.max_stream_len_heading;
    os << "," << de.max_stream_len_inlink;
    os << "," << de.max_stream_len_a;
    os << "," << de.mean_stream_len;
    os << "," << de.mean_stream_len_body;
    os << "," << de.mean_stream_len_title;
    os << "," << de.mean_stream_len_heading;
    os << "," << de.mean_stream_len_inlink;
    os << "," << de.mean_stream_len_a;
    os << "," << de.variance_stream_len;
    os << "," << de.variance_stream_len_body;
    os << "," << de.variance_stream_len_title;
    os << "," << de.variance_stream_len_heading;
    os << "," << de.variance_stream_len_inlink;
    os << "," << de.variance_stream_len_a;

    os << "," << static_cast<double>(de.tag_title_qry_count);
    os << "," << static_cast<double>(de.tag_heading_qry_count);
    os << "," << static_cast<double>(de.tag_mainbody_qry_count);
    os << "," << static_cast<double>(de.tag_inlink_qry_count);

    os << "," << static_cast<double>(de.tag_title_count);
    os << "," << static_cast<double>(de.tag_heading_count);
    os << "," << static_cast<double>(de.tag_inlink_count);
    os << "," << static_cast<double>(de.tag_applet_count);
    os << "," << static_cast<double>(de.tag_object_count);
    os << "," << static_cast<double>(de.tag_embed_count);

    os << "," << static_cast<double>(de.url_slash_count);
    os << "," << static_cast<double>(de.url_length);
    return os;
}
