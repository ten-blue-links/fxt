/*
 * Copyright 2018 The Tesserae authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#pragma once

#include "doc_entry.hpp"
#include "statdoc_entry.hpp"

/*
 * Display features that are enabled.
 */
class FeaturePresenter {
    doc_entry          dentry;
    doc_entry_flag     dentry_flag;
    statdoc_entry      sdentry;
    statdoc_entry_flag sdentry_flag;

   public:
    FeaturePresenter(const doc_entry &         de,
                     const doc_entry_flag &    def,
                     const statdoc_entry &     sde,
                     const statdoc_entry_flag &sdef)
        : dentry(de), dentry_flag(def), sdentry(sde), sdentry_flag(sdef) {}

    friend std::ostream &operator<<(std::ostream &os, const FeaturePresenter &fp);
};

std::ostream &operator<<(std::ostream &os, const FeaturePresenter &fp) {
    if (fp.dentry_flag.f_stage0_score) {
        os << "," << fp.dentry.stage0_score;
    }
    if (fp.dentry_flag.f_bm25_atire) {
        os << "," << fp.dentry.bm25_atire;
    }
    if (fp.dentry_flag.f_bm25_atire_body) {
        os << "," << fp.dentry.bm25_atire_body;
    }
    if (fp.dentry_flag.f_bm25_atire_title) {
        os << "," << fp.dentry.bm25_atire_title;
    }
    if (fp.dentry_flag.f_bm25_atire_heading) {
        os << "," << fp.dentry.bm25_atire_heading;
    }
    if (fp.dentry_flag.f_bm25_atire_inlink) {
        os << "," << fp.dentry.bm25_atire_inlink;
    }
    if (fp.dentry_flag.f_bm25_atire_a) {
        os << "," << fp.dentry.bm25_atire_a;
    }
    if (fp.dentry_flag.f_bm25_trec3) {
        os << "," << fp.dentry.bm25_trec3;
    }
    if (fp.dentry_flag.f_bm25_trec3_body) {
        os << "," << fp.dentry.bm25_trec3_body;
    }
    if (fp.dentry_flag.f_bm25_trec3_title) {
        os << "," << fp.dentry.bm25_trec3_title;
    }
    if (fp.dentry_flag.f_bm25_trec3_heading) {
        os << "," << fp.dentry.bm25_trec3_heading;
    }
    if (fp.dentry_flag.f_bm25_trec3_inlink) {
        os << "," << fp.dentry.bm25_trec3_inlink;
    }
    if (fp.dentry_flag.f_bm25_trec3_a) {
        os << "," << fp.dentry.bm25_trec3_a;
    }
    if (fp.dentry_flag.f_bm25_trec3_kmax) {
        os << "," << fp.dentry.bm25_trec3_kmax;
    }
    if (fp.dentry_flag.f_bm25_trec3_kmax_body) {
        os << "," << fp.dentry.bm25_trec3_kmax_body;
    }
    if (fp.dentry_flag.f_bm25_trec3_kmax_title) {
        os << "," << fp.dentry.bm25_trec3_kmax_title;
    }
    if (fp.dentry_flag.f_bm25_trec3_kmax_heading) {
        os << "," << fp.dentry.bm25_trec3_kmax_heading;
    }
    if (fp.dentry_flag.f_bm25_trec3_kmax_inlink) {
        os << "," << fp.dentry.bm25_trec3_kmax_inlink;
    }
    if (fp.dentry_flag.f_bm25_trec3_kmax_a) {
        os << "," << fp.dentry.bm25_trec3_kmax_a;
    }
    if (fp.dentry_flag.f_bm25_bigram_u8) {
        os << "," << fp.dentry.bm25_bigram_u8;
    }
    if (fp.dentry_flag.f_bm25_tp_dist_w100) {
        os << "," << fp.dentry.bm25_tp_dist_w100;
    }
    if (fp.dentry_flag.f_tpscore) {
        os << "," << fp.dentry.tpscore;
    }
    if (fp.dentry_flag.f_lm_dir_2500) {
        os << "," << fp.dentry.lm_dir_2500;
    }
    if (fp.dentry_flag.f_lm_dir_2500_body) {
        os << "," << fp.dentry.lm_dir_2500_body;
    }
    if (fp.dentry_flag.f_lm_dir_2500_title) {
        os << "," << fp.dentry.lm_dir_2500_title;
    }
    if (fp.dentry_flag.f_lm_dir_2500_heading) {
        os << "," << fp.dentry.lm_dir_2500_heading;
    }
    if (fp.dentry_flag.f_lm_dir_2500_inlink) {
        os << "," << fp.dentry.lm_dir_2500_inlink;
    }
    if (fp.dentry_flag.f_lm_dir_2500_a) {
        os << "," << fp.dentry.lm_dir_2500_a;
    }
    if (fp.dentry_flag.f_lm_dir_1500) {
        os << "," << fp.dentry.lm_dir_1500;
    }
    if (fp.dentry_flag.f_lm_dir_1500_body) {
        os << "," << fp.dentry.lm_dir_1500_body;
    }
    if (fp.dentry_flag.f_lm_dir_1500_title) {
        os << "," << fp.dentry.lm_dir_1500_title;
    }
    if (fp.dentry_flag.f_lm_dir_1500_heading) {
        os << "," << fp.dentry.lm_dir_1500_heading;
    }
    if (fp.dentry_flag.f_lm_dir_1500_inlink) {
        os << "," << fp.dentry.lm_dir_1500_inlink;
    }
    if (fp.dentry_flag.f_lm_dir_1500_a) {
        os << "," << fp.dentry.lm_dir_1500_a;
    }
    if (fp.dentry_flag.f_lm_dir_1000) {
        os << "," << fp.dentry.lm_dir_1000;
    }
    if (fp.dentry_flag.f_lm_dir_1000_body) {
        os << "," << fp.dentry.lm_dir_1000_body;
    }
    if (fp.dentry_flag.f_lm_dir_1000_title) {
        os << "," << fp.dentry.lm_dir_1000_title;
    }
    if (fp.dentry_flag.f_lm_dir_1000_heading) {
        os << "," << fp.dentry.lm_dir_1000_heading;
    }
    if (fp.dentry_flag.f_lm_dir_1000_inlink) {
        os << "," << fp.dentry.lm_dir_1000_inlink;
    }
    if (fp.dentry_flag.f_lm_dir_1000_a) {
        os << "," << fp.dentry.lm_dir_1000_a;
    }
    if (fp.dentry_flag.f_tfidf) {
        os << "," << fp.dentry.tfidf;
    }
    if (fp.dentry_flag.f_tfidf_body) {
        os << "," << fp.dentry.tfidf_body;
    }
    if (fp.dentry_flag.f_tfidf_title) {
        os << "," << fp.dentry.tfidf_title;
    }
    if (fp.dentry_flag.f_tfidf_heading) {
        os << "," << fp.dentry.tfidf_heading;
    }
    if (fp.dentry_flag.f_tfidf_inlink) {
        os << "," << fp.dentry.tfidf_inlink;
    }
    if (fp.dentry_flag.f_tfidf_a) {
        os << "," << fp.dentry.tfidf_a;
    }
    if (fp.dentry_flag.f_prob) {
        os << "," << fp.dentry.prob;
    }
    if (fp.dentry_flag.f_prob_body) {
        os << "," << fp.dentry.prob_body;
    }
    if (fp.dentry_flag.f_prob_title) {
        os << "," << fp.dentry.prob_title;
    }
    if (fp.dentry_flag.f_prob_heading) {
        os << "," << fp.dentry.prob_heading;
    }
    if (fp.dentry_flag.f_prob_inlink) {
        os << "," << fp.dentry.prob_inlink;
    }
    if (fp.dentry_flag.f_prob_a) {
        os << "," << fp.dentry.prob_a;
    }
    if (fp.dentry_flag.f_be) {
        os << "," << fp.dentry.be;
    }
    if (fp.dentry_flag.f_be_body) {
        os << "," << fp.dentry.be_body;
    }
    if (fp.dentry_flag.f_be_title) {
        os << "," << fp.dentry.be_title;
    }
    if (fp.dentry_flag.f_be_heading) {
        os << "," << fp.dentry.be_heading;
    }
    if (fp.dentry_flag.f_be_inlink) {
        os << "," << fp.dentry.be_inlink;
    }
    if (fp.dentry_flag.f_be_a) {
        os << "," << fp.dentry.be_a;
    }
    if (fp.dentry_flag.f_dph) {
        os << "," << fp.dentry.dph;
    }
    if (fp.dentry_flag.f_dph_body) {
        os << "," << fp.dentry.dph_body;
    }
    if (fp.dentry_flag.f_dph_title) {
        os << "," << fp.dentry.dph_title;
    }
    if (fp.dentry_flag.f_dph_heading) {
        os << "," << fp.dentry.dph_heading;
    }
    if (fp.dentry_flag.f_dph_inlink) {
        os << "," << fp.dentry.dph_inlink;
    }
    if (fp.dentry_flag.f_dph_a) {
        os << "," << fp.dentry.dph_a;
    }
    if (fp.dentry_flag.f_dfr) {
        os << "," << fp.dentry.dfr;
    }
    if (fp.dentry_flag.f_dfr_body) {
        os << "," << fp.dentry.dfr_body;
    }
    if (fp.dentry_flag.f_dfr_title) {
        os << "," << fp.dentry.dfr_title;
    }
    if (fp.dentry_flag.f_dfr_heading) {
        os << "," << fp.dentry.dfr_heading;
    }
    if (fp.dentry_flag.f_dfr_inlink) {
        os << "," << fp.dentry.dfr_inlink;
    }
    if (fp.dentry_flag.f_dfr_a) {
        os << "," << fp.dentry.dfr_a;
    }
    if (fp.dentry_flag.f_stream_len) {
        os << "," << fp.dentry.stream_len;
    }
    if (fp.dentry_flag.f_stream_len_body) {
        os << "," << fp.dentry.stream_len_body;
    }
    if (fp.dentry_flag.f_stream_len_title) {
        os << "," << fp.dentry.stream_len_title;
    }
    if (fp.dentry_flag.f_stream_len_heading) {
        os << "," << fp.dentry.stream_len_heading;
    }
    if (fp.dentry_flag.f_stream_len_inlink) {
        os << "," << fp.dentry.stream_len_inlink;
    }
    if (fp.dentry_flag.f_stream_len_a) {
        os << "," << fp.dentry.stream_len_a;
    }
    if (fp.dentry_flag.f_sum_stream_len) {
        os << "," << fp.dentry.sum_stream_len;
    }
    if (fp.dentry_flag.f_sum_stream_len_body) {
        os << "," << fp.dentry.sum_stream_len_body;
    }
    if (fp.dentry_flag.f_sum_stream_len_title) {
        os << "," << fp.dentry.sum_stream_len_title;
    }
    if (fp.dentry_flag.f_sum_stream_len_heading) {
        os << "," << fp.dentry.sum_stream_len_heading;
    }
    if (fp.dentry_flag.f_sum_stream_len_inlink) {
        os << "," << fp.dentry.sum_stream_len_inlink;
    }
    if (fp.dentry_flag.f_sum_stream_len_a) {
        os << "," << fp.dentry.sum_stream_len_a;
    }
    if (fp.dentry_flag.f_min_stream_len) {
        os << "," << fp.dentry.min_stream_len;
    }
    if (fp.dentry_flag.f_min_stream_len_body) {
        os << "," << fp.dentry.min_stream_len_body;
    }
    if (fp.dentry_flag.f_min_stream_len_title) {
        os << "," << fp.dentry.min_stream_len_title;
    }
    if (fp.dentry_flag.f_min_stream_len_heading) {
        os << "," << fp.dentry.min_stream_len_heading;
    }
    if (fp.dentry_flag.f_min_stream_len_inlink) {
        os << "," << fp.dentry.min_stream_len_inlink;
    }
    if (fp.dentry_flag.f_min_stream_len_a) {
        os << "," << fp.dentry.min_stream_len_a;
    }
    if (fp.dentry_flag.f_max_stream_len) {
        os << "," << fp.dentry.max_stream_len;
    }
    if (fp.dentry_flag.f_max_stream_len_body) {
        os << "," << fp.dentry.max_stream_len_body;
    }
    if (fp.dentry_flag.f_max_stream_len_title) {
        os << "," << fp.dentry.max_stream_len_title;
    }
    if (fp.dentry_flag.f_max_stream_len_heading) {
        os << "," << fp.dentry.max_stream_len_heading;
    }
    if (fp.dentry_flag.f_max_stream_len_inlink) {
        os << "," << fp.dentry.max_stream_len_inlink;
    }
    if (fp.dentry_flag.f_max_stream_len_a) {
        os << "," << fp.dentry.max_stream_len_a;
    }
    if (fp.dentry_flag.f_mean_stream_len) {
        os << "," << fp.dentry.mean_stream_len;
    }
    if (fp.dentry_flag.f_mean_stream_len_body) {
        os << "," << fp.dentry.mean_stream_len_body;
    }
    if (fp.dentry_flag.f_mean_stream_len_title) {
        os << "," << fp.dentry.mean_stream_len_title;
    }
    if (fp.dentry_flag.f_mean_stream_len_heading) {
        os << "," << fp.dentry.mean_stream_len_heading;
    }
    if (fp.dentry_flag.f_mean_stream_len_inlink) {
        os << "," << fp.dentry.mean_stream_len_inlink;
    }
    if (fp.dentry_flag.f_mean_stream_len_a) {
        os << "," << fp.dentry.mean_stream_len_a;
    }
    if (fp.dentry_flag.f_variance_stream_len) {
        os << "," << fp.dentry.variance_stream_len;
    }
    if (fp.dentry_flag.f_variance_stream_len_body) {
        os << "," << fp.dentry.variance_stream_len_body;
    }
    if (fp.dentry_flag.f_variance_stream_len_title) {
        os << "," << fp.dentry.variance_stream_len_title;
    }
    if (fp.dentry_flag.f_variance_stream_len_heading) {
        os << "," << fp.dentry.variance_stream_len_heading;
    }
    if (fp.dentry_flag.f_variance_stream_len_inlink) {
        os << "," << fp.dentry.variance_stream_len_inlink;
    }
    if (fp.dentry_flag.f_variance_stream_len_a) {
        os << "," << fp.dentry.variance_stream_len_a;
    }

    if (fp.dentry_flag.f_tag_title_qry_count) {
        os << "," << static_cast<double>(fp.dentry.tag_title_qry_count);
    }
    if (fp.dentry_flag.f_tag_heading_qry_count) {
        os << "," << static_cast<double>(fp.dentry.tag_heading_qry_count);
    }
    if (fp.dentry_flag.f_tag_mainbody_qry_count) {
        os << "," << static_cast<double>(fp.dentry.tag_mainbody_qry_count);
    }
    if (fp.dentry_flag.f_tag_inlink_qry_count) {
        os << "," << static_cast<double>(fp.dentry.tag_inlink_qry_count);
    }

    if (fp.dentry_flag.f_tag_title_count) {
        os << "," << static_cast<double>(fp.dentry.tag_title_count);
    }
    if (fp.dentry_flag.f_tag_heading_count) {
        os << "," << static_cast<double>(fp.dentry.tag_heading_count);
    }
    if (fp.dentry_flag.f_tag_inlink_count) {
        os << "," << static_cast<double>(fp.dentry.tag_inlink_count);
    }
    if (fp.dentry_flag.f_tag_applet_count) {
        os << "," << static_cast<double>(fp.dentry.tag_applet_count);
    }
    if (fp.dentry_flag.f_tag_object_count) {
        os << "," << static_cast<double>(fp.dentry.tag_object_count);
    }
    if (fp.dentry_flag.f_tag_embed_count) {
        os << "," << static_cast<double>(fp.dentry.tag_embed_count);
    }

    if (fp.dentry_flag.f_url_slash_count) {
        os << "," << static_cast<double>(fp.dentry.url_slash_count);
    }
    if (fp.dentry_flag.f_url_length) {
        os << "," << static_cast<double>(fp.dentry.url_length);
    }

    if (fp.sdentry_flag.f_len) {
        os << "," << static_cast<double>(fp.sdentry.len);
    }
    if (fp.sdentry_flag.f_title_len) {
        os << "," << static_cast<double>(fp.sdentry.title_len);
    }
    if (fp.sdentry_flag.f_visterm_len) {
        os << "," << static_cast<double>(fp.sdentry.visterm_len);
    }
    if (fp.sdentry_flag.f_url_len) {
        os << "," << static_cast<double>(fp.sdentry.url_len);
    }
    if (fp.sdentry_flag.f_url_depth) {
        os << "," << static_cast<double>(fp.sdentry.url_depth);
    }
    if (fp.sdentry_flag.f_avg_term_len) {
        os << "," << fp.sdentry.avg_term_len;
    }
    if (fp.sdentry_flag.f_entropy) {
        os << "," << fp.sdentry.entropy;
    }
    if (fp.sdentry_flag.f_stop_cover) {
        os << "," << fp.sdentry.stop_cover;
    }
    if (fp.sdentry_flag.f_frac_stop) {
        os << "," << fp.sdentry.frac_stop;
    }
    if (fp.sdentry_flag.f_frac_anchor_text) {
        os << "," << fp.sdentry.frac_anchor_text;
    }
    if (fp.sdentry_flag.f_frac_vis_text) {
        os << "," << fp.sdentry.frac_vis_text;
    }
    if (fp.sdentry_flag.f_frac_table_text) {
        os << "," << fp.sdentry.frac_table_text;
    }
    if (fp.sdentry_flag.f_frac_td_text) {
        os << "," << fp.sdentry.frac_td_text;
    }

    return os;
}
