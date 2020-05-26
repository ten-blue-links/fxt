/*
 * Copyright 2018 The Tesserae authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#pragma once

#include <cstdint>
#include <vector>

#include "doc_entry_flag.hpp"
#include "features/features.hpp"
#include "query_train_file.hpp"
#include "statdoc_entry_flag.hpp"

/*
 * Determine which query-document features to compute.
 *
 * Coarse grained at the moment. For example, the document feature
 * `f_bm25_atire` will compute all 6 features (assuming the fields exist) that
 * are contained within.
 */
class FeatureExtractor {
  Lexicon &lexicon;
  FieldIdMap &fid_map;
  doc_entry_flag &qd_flags;
  statdoc_entry_flag &sd_flags;

  document_features features;
  doc_bm25_atire_feature f_bm25_atire;
  doc_bm25_trec3_feature f_bm25_trec3;
  doc_bm25_trec3_kmax_feature f_bm25_trec3_kmax;
  doc_proximity_feature prox_feature;
  doc_lm_dir_2500_feature f_lmds_2500;
  doc_lm_dir_1500_feature f_lmds_1500;
  doc_lm_dir_1000_feature f_lmds_1000;
  doc_tfidf_feature tfidf_feature;
  doc_prob_feature prob_feature;
  doc_be_feature be_feature;
  doc_dph_feature dph_feature;
  doc_dfr_feature dfr_feature;
  doc_stream_feature f_stream;
  doc_tpscore_feature f_tpscore;

 public:
  FeatureExtractor(Lexicon &lex, FieldIdMap &fid, doc_entry_flag &qdf,
                   statdoc_entry_flag &sdf)
      : lexicon(lex),
        fid_map(fid),
        qd_flags(qdf),
        sd_flags(sdf),
        f_bm25_atire(lexicon),
        f_bm25_trec3(lexicon),
        f_bm25_trec3_kmax(lexicon),
        prox_feature(lexicon),
        f_lmds_2500(lexicon),
        f_lmds_1500(lexicon),
        f_lmds_1000(lexicon),
        tfidf_feature(lexicon),
        prob_feature(lexicon),
        be_feature(lexicon),
        dph_feature(lexicon),
        dfr_feature(lexicon),
        f_tpscore(lexicon) {}

  void extract(query_train &qry, doc_entry &de, Document &doc,
               std::unordered_map<uint32_t, std::vector<uint32_t>> &positions) {
    if (has_bm25_atire()) {
      f_bm25_atire.compute(qry, de, doc, fid_map);
    }
    if (has_bm25_trec3()) {
      f_bm25_trec3.compute(qry, de, doc, fid_map);
    }
    if (has_bm25_trec3_kmax()) {
      f_bm25_trec3_kmax.compute(qry, de, doc, fid_map);
    }
    if (has_lm_dir_2500()) {
      f_lmds_2500.compute(qry, de, doc, fid_map);
    }
    if (has_lm_dir_1500()) {
      f_lmds_1500.compute(qry, de, doc, fid_map);
    }
    if (has_lm_dir_1000()) {
      f_lmds_1000.compute(qry, de, doc, fid_map);
    }
    if (has_tfidf()) {
      tfidf_feature.compute(qry, de, doc, fid_map);
    }
    if (has_prob()) {
      prob_feature.compute(qry, de, doc, fid_map);
    }
    if (has_be()) {
      be_feature.compute(qry, de, doc, fid_map);
    }
    if (has_dph()) {
      dph_feature.compute(qry, de, doc, fid_map);
    }
    if (has_dfr()) {
      dfr_feature.compute(qry, de, doc, fid_map);
    }
    if (has_stream()) {
      f_stream.compute(qry, de, doc, fid_map);
    }
    if (has_tag_count()) {
      features.compute(qry, de, doc, fid_map);
    }
    /* lgr: fixup #XXX */
    if (has_proximity()) {
      prox_feature.compute(qry, de, doc, positions);
    }
    if (has_tpscore()) {
      f_tpscore.compute(qry, de, doc, fid_map);
    }
  }

  inline bool has_bm25_atire() {
    return qd_flags.f_bm25_atire || qd_flags.f_bm25_atire_body ||
           qd_flags.f_bm25_atire_title || qd_flags.f_bm25_atire_heading ||
           qd_flags.f_bm25_atire_inlink || qd_flags.f_bm25_atire_a;
  }

  inline bool has_bm25_trec3() {
    return qd_flags.f_bm25_trec3 || qd_flags.f_bm25_trec3_body ||
           qd_flags.f_bm25_trec3_title || qd_flags.f_bm25_trec3_heading ||
           qd_flags.f_bm25_trec3_inlink || qd_flags.f_bm25_trec3_a;
  }

  inline bool has_bm25_trec3_kmax() {
    return qd_flags.f_bm25_trec3_kmax || qd_flags.f_bm25_trec3_kmax_body ||
           qd_flags.f_bm25_trec3_kmax_title ||
           qd_flags.f_bm25_trec3_kmax_heading ||
           qd_flags.f_bm25_trec3_kmax_inlink || qd_flags.f_bm25_trec3_kmax_a;
  }

  inline bool has_lm_dir_2500() {
    return qd_flags.f_lm_dir_2500 || qd_flags.f_lm_dir_2500_body ||
           qd_flags.f_lm_dir_2500_title || qd_flags.f_lm_dir_2500_heading ||
           qd_flags.f_lm_dir_2500_inlink || qd_flags.f_lm_dir_2500_a;
  }

  inline bool has_lm_dir_1500() {
    return qd_flags.f_lm_dir_1500 || qd_flags.f_lm_dir_1500_body ||
           qd_flags.f_lm_dir_1500_title || qd_flags.f_lm_dir_1500_heading ||
           qd_flags.f_lm_dir_1500_inlink || qd_flags.f_lm_dir_1500_a;
  }

  inline bool has_lm_dir_1000() {
    return qd_flags.f_lm_dir_1000 || qd_flags.f_lm_dir_1000_body ||
           qd_flags.f_lm_dir_1000_title || qd_flags.f_lm_dir_1000_heading ||
           qd_flags.f_lm_dir_1000_inlink || qd_flags.f_lm_dir_1000_a;
  }

  inline bool has_tfidf() {
    return qd_flags.f_tfidf || qd_flags.f_tfidf_body ||
           qd_flags.f_tfidf_title || qd_flags.f_tfidf_heading ||
           qd_flags.f_tfidf_inlink || qd_flags.f_tfidf_a;
  }

  inline bool has_prob() {
    return qd_flags.f_prob || qd_flags.f_prob_body || qd_flags.f_prob_title ||
           qd_flags.f_prob_heading || qd_flags.f_prob_inlink ||
           qd_flags.f_prob_a;
  }

  inline bool has_be() {
    return qd_flags.f_be || qd_flags.f_be_body || qd_flags.f_be_title ||
           qd_flags.f_be_heading || qd_flags.f_be_inlink || qd_flags.f_be_a;
  }

  inline bool has_dph() {
    return qd_flags.f_dph || qd_flags.f_dph_body || qd_flags.f_dph_title ||
           qd_flags.f_dph_heading || qd_flags.f_dph_inlink || qd_flags.f_dph_a;
  }

  inline bool has_dfr() {
    return qd_flags.f_dfr || qd_flags.f_dfr_body || qd_flags.f_dfr_title ||
           qd_flags.f_dfr_heading || qd_flags.f_dfr_inlink || qd_flags.f_dfr_a;
  }

  /* currently all stream features are grouped */
  inline bool has_stream() {
    return has_stream_len() || has_sum_stream_len() || has_min_stream_len() ||
           has_max_stream_len() || has_mean_stream_len() ||
           has_variance_stream_len();
  }

  inline bool has_stream_len() {
    return qd_flags.f_stream_len || qd_flags.f_stream_len_body ||
           qd_flags.f_stream_len_title || qd_flags.f_stream_len_heading ||
           qd_flags.f_stream_len_inlink || qd_flags.f_stream_len_a;
  }

  inline bool has_sum_stream_len() {
    return qd_flags.f_sum_stream_len || qd_flags.f_sum_stream_len_body ||
           qd_flags.f_sum_stream_len_title ||
           qd_flags.f_sum_stream_len_heading ||
           qd_flags.f_sum_stream_len_inlink || qd_flags.f_sum_stream_len_a;
  }

  inline bool has_min_stream_len() {
    return qd_flags.f_min_stream_len || qd_flags.f_min_stream_len_body ||
           qd_flags.f_min_stream_len_title ||
           qd_flags.f_min_stream_len_heading ||
           qd_flags.f_min_stream_len_inlink || qd_flags.f_min_stream_len_a;
  }

  inline bool has_max_stream_len() {
    return qd_flags.f_max_stream_len || qd_flags.f_max_stream_len_body ||
           qd_flags.f_max_stream_len_title ||
           qd_flags.f_max_stream_len_heading ||
           qd_flags.f_max_stream_len_inlink || qd_flags.f_max_stream_len_a;
  }

  inline bool has_mean_stream_len() {
    return qd_flags.f_mean_stream_len || qd_flags.f_mean_stream_len_body ||
           qd_flags.f_mean_stream_len_title ||
           qd_flags.f_mean_stream_len_heading ||
           qd_flags.f_mean_stream_len_inlink || qd_flags.f_mean_stream_len_a;
  }

  inline bool has_variance_stream_len() {
    return qd_flags.f_variance_stream_len ||
           qd_flags.f_variance_stream_len_body ||
           qd_flags.f_variance_stream_len_title ||
           qd_flags.f_variance_stream_len_heading ||
           qd_flags.f_variance_stream_len_inlink ||
           qd_flags.f_variance_stream_len_a;
  }

  inline bool has_tpscore() { return qd_flags.f_tpscore; }

  /* lgr: fixup #XXX */
  inline bool has_proximity() {
    return qd_flags.f_bm25_bigram_u8 || qd_flags.f_bm25_tp_dist_w100;
  }

  /* lgr: to be moved see #4 */
  inline bool has_tag_count() {
    return qd_flags.f_tag_title_count || qd_flags.f_tag_heading_count ||
           qd_flags.f_tag_inlink_count || qd_flags.f_tag_applet_count ||
           qd_flags.f_tag_object_count || qd_flags.f_tag_embed_count;
  }
};
