/*
 * Copyright 2018 The Tesserae authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#include <iostream>
#include <string>
#include <vector>

#include "CLI/CLI.hpp"
#include "cereal/archives/binary.hpp"

#include "tesserae/doc_entry.hpp"
#include "tesserae/doc_entry_flag.hpp"
#include "tesserae/statdoc_entry.hpp"
#include "tesserae/statdoc_entry_flag.hpp"

#include "tesserae/feature_extractor.hpp"
#include "tesserae/feature_presenter.hpp"
#include "tesserae/features/features.hpp"
#include "tesserae/field_id.hpp"
#include "tesserae/forward_index.hpp"
#include "tesserae/lexicon.hpp"
#include "tesserae/query_environment_adapter.hpp"
#include "tesserae/query_train_file.hpp"
#include "tesserae/static_feature.hpp"
#include "tesserae/trec_run_file.hpp"

/*
 * Perform feature extraction.
 */
int main(int argc, char **argv) {
  std::string query_file;
  std::string trec_file;
  std::string output_file;

  std::string indri_index;
  std::string fwd_index_file;
  std::string lexicon_file;
  std::string static_doc_file;

  CLI::App app;
  app.add_option("query_file", query_file, "Query file")
      ->required()
      ->check(CLI::ExistingFile);
  app.add_option("trec_file", trec_file, "TREC run file")
      ->required()
      ->check(CLI::ExistingFile);
  app.add_option("output_file", output_file, "Output file")->required();

  app.add_option("--indri_index", indri_index, "Path to an Indri index")
      ->required()
      ->check(CLI::ExistingDirectory);
  app.add_option("--forward_index", fwd_index_file,
                 "Path to a forward index file")
      ->required()
      ->check(CLI::ExistingFile);
  app.add_option("--lexicon", lexicon_file, "Path to a lexicon file")
      ->required()
      ->check(CLI::ExistingFile);
  app.add_option("--static_doc_file", static_doc_file,
                 "Path to a static document feature file")
      ->required()
      ->check(CLI::ExistingFile);

  /* The following flags for enabling features is automatically generated. */
  struct doc_entry_flag query_doc_flags;
  struct statdoc_entry_flag static_doc_flags;
  app.add_flag("--f_stage0_score", query_doc_flags.f_stage0_score,
               "Enable feature f_stage0_score")
      ->group("Query-document features");
  app.add_flag("--f_bm25_atire", query_doc_flags.f_bm25_atire,
               "Enable feature f_bm25_atire")
      ->group("Query-document features");
  app.add_flag("--f_bm25_atire_body", query_doc_flags.f_bm25_atire_body,
               "Enable feature f_bm25_atire_body")
      ->group("Query-document features");
  app.add_flag("--f_bm25_atire_title", query_doc_flags.f_bm25_atire_title,
               "Enable feature f_bm25_atire_title")
      ->group("Query-document features");
  app.add_flag("--f_bm25_atire_heading", query_doc_flags.f_bm25_atire_heading,
               "Enable feature f_bm25_atire_heading")
      ->group("Query-document features");
  app.add_flag("--f_bm25_atire_inlink", query_doc_flags.f_bm25_atire_inlink,
               "Enable feature f_bm25_atire_inlink")
      ->group("Query-document features");
  app.add_flag("--f_bm25_atire_a", query_doc_flags.f_bm25_atire_a,
               "Enable feature f_bm25_atire_a")
      ->group("Query-document features");
  app.add_flag("--f_bm25_trec3", query_doc_flags.f_bm25_trec3,
               "Enable feature f_bm25_trec3")
      ->group("Query-document features");
  app.add_flag("--f_bm25_trec3_body", query_doc_flags.f_bm25_trec3_body,
               "Enable feature f_bm25_trec3_body")
      ->group("Query-document features");
  app.add_flag("--f_bm25_trec3_title", query_doc_flags.f_bm25_trec3_title,
               "Enable feature f_bm25_trec3_title")
      ->group("Query-document features");
  app.add_flag("--f_bm25_trec3_heading", query_doc_flags.f_bm25_trec3_heading,
               "Enable feature f_bm25_trec3_heading")
      ->group("Query-document features");
  app.add_flag("--f_bm25_trec3_inlink", query_doc_flags.f_bm25_trec3_inlink,
               "Enable feature f_bm25_trec3_inlink")
      ->group("Query-document features");
  app.add_flag("--f_bm25_trec3_a", query_doc_flags.f_bm25_trec3_a,
               "Enable feature f_bm25_trec3_a")
      ->group("Query-document features");
  app.add_flag("--f_bm25_trec3_kmax", query_doc_flags.f_bm25_trec3_kmax,
               "Enable feature f_bm25_trec3_kmax")
      ->group("Query-document features");
  app.add_flag("--f_bm25_trec3_kmax_body",
               query_doc_flags.f_bm25_trec3_kmax_body,
               "Enable feature f_bm25_trec3_kmax_body")
      ->group("Query-document features");
  app.add_flag("--f_bm25_trec3_kmax_title",
               query_doc_flags.f_bm25_trec3_kmax_title,
               "Enable feature f_bm25_trec3_kmax_title")
      ->group("Query-document features");
  app.add_flag("--f_bm25_trec3_kmax_heading",
               query_doc_flags.f_bm25_trec3_kmax_heading,
               "Enable feature f_bm25_trec3_kmax_heading")
      ->group("Query-document features");
  app.add_flag("--f_bm25_trec3_kmax_inlink",
               query_doc_flags.f_bm25_trec3_kmax_inlink,
               "Enable feature f_bm25_trec3_kmax_inlink")
      ->group("Query-document features");
  app.add_flag("--f_bm25_trec3_kmax_a", query_doc_flags.f_bm25_trec3_kmax_a,
               "Enable feature f_bm25_trec3_kmax_a")
      ->group("Query-document features");
  app.add_flag("--f_lm_dir_2500", query_doc_flags.f_lm_dir_2500,
               "Enable feature f_lm_dir_2500")
      ->group("Query-document features");
  app.add_flag("--f_lm_dir_2500_body", query_doc_flags.f_lm_dir_2500_body,
               "Enable feature f_lm_dir_2500_body")
      ->group("Query-document features");
  app.add_flag("--f_lm_dir_2500_title", query_doc_flags.f_lm_dir_2500_title,
               "Enable feature f_lm_dir_2500_title")
      ->group("Query-document features");
  app.add_flag("--f_lm_dir_2500_heading", query_doc_flags.f_lm_dir_2500_heading,
               "Enable feature f_lm_dir_2500_heading")
      ->group("Query-document features");
  app.add_flag("--f_lm_dir_2500_inlink", query_doc_flags.f_lm_dir_2500_inlink,
               "Enable feature f_lm_dir_2500_inlink")
      ->group("Query-document features");
  app.add_flag("--f_lm_dir_2500_a", query_doc_flags.f_lm_dir_2500_a,
               "Enable feature f_lm_dir_2500_a")
      ->group("Query-document features");
  app.add_flag("--f_lm_dir_1500", query_doc_flags.f_lm_dir_1500,
               "Enable feature f_lm_dir_1500")
      ->group("Query-document features");
  app.add_flag("--f_lm_dir_1500_body", query_doc_flags.f_lm_dir_1500_body,
               "Enable feature f_lm_dir_1500_body")
      ->group("Query-document features");
  app.add_flag("--f_lm_dir_1500_title", query_doc_flags.f_lm_dir_1500_title,
               "Enable feature f_lm_dir_1500_title")
      ->group("Query-document features");
  app.add_flag("--f_lm_dir_1500_heading", query_doc_flags.f_lm_dir_1500_heading,
               "Enable feature f_lm_dir_1500_heading")
      ->group("Query-document features");
  app.add_flag("--f_lm_dir_1500_inlink", query_doc_flags.f_lm_dir_1500_inlink,
               "Enable feature f_lm_dir_1500_inlink")
      ->group("Query-document features");
  app.add_flag("--f_lm_dir_1500_a", query_doc_flags.f_lm_dir_1500_a,
               "Enable feature f_lm_dir_1500_a")
      ->group("Query-document features");
  app.add_flag("--f_lm_dir_1000", query_doc_flags.f_lm_dir_1000,
               "Enable feature f_lm_dir_1000")
      ->group("Query-document features");
  app.add_flag("--f_lm_dir_1000_body", query_doc_flags.f_lm_dir_1000_body,
               "Enable feature f_lm_dir_1000_body")
      ->group("Query-document features");
  app.add_flag("--f_lm_dir_1000_title", query_doc_flags.f_lm_dir_1000_title,
               "Enable feature f_lm_dir_1000_title")
      ->group("Query-document features");
  app.add_flag("--f_lm_dir_1000_heading", query_doc_flags.f_lm_dir_1000_heading,
               "Enable feature f_lm_dir_1000_heading")
      ->group("Query-document features");
  app.add_flag("--f_lm_dir_1000_inlink", query_doc_flags.f_lm_dir_1000_inlink,
               "Enable feature f_lm_dir_1000_inlink")
      ->group("Query-document features");
  app.add_flag("--f_lm_dir_1000_a", query_doc_flags.f_lm_dir_1000_a,
               "Enable feature f_lm_dir_1000_a")
      ->group("Query-document features");
  app.add_flag("--f_tfidf", query_doc_flags.f_tfidf, "Enable feature f_tfidf")
      ->group("Query-document features");
  app.add_flag("--f_tfidf_body", query_doc_flags.f_tfidf_body,
               "Enable feature f_tfidf_body")
      ->group("Query-document features");
  app.add_flag("--f_tfidf_title", query_doc_flags.f_tfidf_title,
               "Enable feature f_tfidf_title")
      ->group("Query-document features");
  app.add_flag("--f_tfidf_heading", query_doc_flags.f_tfidf_heading,
               "Enable feature f_tfidf_heading")
      ->group("Query-document features");
  app.add_flag("--f_tfidf_inlink", query_doc_flags.f_tfidf_inlink,
               "Enable feature f_tfidf_inlink")
      ->group("Query-document features");
  app.add_flag("--f_tfidf_a", query_doc_flags.f_tfidf_a,
               "Enable feature f_tfidf_a")
      ->group("Query-document features");
  app.add_flag("--f_prob", query_doc_flags.f_prob, "Enable feature f_prob")
      ->group("Query-document features");
  app.add_flag("--f_prob_body", query_doc_flags.f_prob_body,
               "Enable feature f_prob_body")
      ->group("Query-document features");
  app.add_flag("--f_prob_title", query_doc_flags.f_prob_title,
               "Enable feature f_prob_title")
      ->group("Query-document features");
  app.add_flag("--f_prob_heading", query_doc_flags.f_prob_heading,
               "Enable feature f_prob_heading")
      ->group("Query-document features");
  app.add_flag("--f_prob_inlink", query_doc_flags.f_prob_inlink,
               "Enable feature f_prob_inlink")
      ->group("Query-document features");
  app.add_flag("--f_prob_a", query_doc_flags.f_prob_a,
               "Enable feature f_prob_a")
      ->group("Query-document features");
  app.add_flag("--f_be", query_doc_flags.f_be, "Enable feature f_be")
      ->group("Query-document features");
  app.add_flag("--f_be_body", query_doc_flags.f_be_body,
               "Enable feature f_be_body")
      ->group("Query-document features");
  app.add_flag("--f_be_title", query_doc_flags.f_be_title,
               "Enable feature f_be_title")
      ->group("Query-document features");
  app.add_flag("--f_be_heading", query_doc_flags.f_be_heading,
               "Enable feature f_be_heading")
      ->group("Query-document features");
  app.add_flag("--f_be_inlink", query_doc_flags.f_be_inlink,
               "Enable feature f_be_inlink")
      ->group("Query-document features");
  app.add_flag("--f_be_a", query_doc_flags.f_be_a, "Enable feature f_be_a")
      ->group("Query-document features");
  app.add_flag("--f_dph", query_doc_flags.f_dph, "Enable feature f_dph")
      ->group("Query-document features");
  app.add_flag("--f_dph_body", query_doc_flags.f_dph_body,
               "Enable feature f_dph_body")
      ->group("Query-document features");
  app.add_flag("--f_dph_title", query_doc_flags.f_dph_title,
               "Enable feature f_dph_title")
      ->group("Query-document features");
  app.add_flag("--f_dph_heading", query_doc_flags.f_dph_heading,
               "Enable feature f_dph_heading")
      ->group("Query-document features");
  app.add_flag("--f_dph_inlink", query_doc_flags.f_dph_inlink,
               "Enable feature f_dph_inlink")
      ->group("Query-document features");
  app.add_flag("--f_dph_a", query_doc_flags.f_dph_a, "Enable feature f_dph_a")
      ->group("Query-document features");
  app.add_flag("--f_dfr", query_doc_flags.f_dfr, "Enable feature f_dfr")
      ->group("Query-document features");
  app.add_flag("--f_dfr_body", query_doc_flags.f_dfr_body,
               "Enable feature f_dfr_body")
      ->group("Query-document features");
  app.add_flag("--f_dfr_title", query_doc_flags.f_dfr_title,
               "Enable feature f_dfr_title")
      ->group("Query-document features");
  app.add_flag("--f_dfr_heading", query_doc_flags.f_dfr_heading,
               "Enable feature f_dfr_heading")
      ->group("Query-document features");
  app.add_flag("--f_dfr_inlink", query_doc_flags.f_dfr_inlink,
               "Enable feature f_dfr_inlink")
      ->group("Query-document features");
  app.add_flag("--f_dfr_a", query_doc_flags.f_dfr_a, "Enable feature f_dfr_a")
      ->group("Query-document features");
  app.add_flag("--f_stream_len", query_doc_flags.f_stream_len,
               "Enable feature f_stream_len")
      ->group("Query-document features");
  app.add_flag("--f_stream_len_body", query_doc_flags.f_stream_len_body,
               "Enable feature f_stream_len_body")
      ->group("Query-document features");
  app.add_flag("--f_stream_len_title", query_doc_flags.f_stream_len_title,
               "Enable feature f_stream_len_title")
      ->group("Query-document features");
  app.add_flag("--f_stream_len_heading", query_doc_flags.f_stream_len_heading,
               "Enable feature f_stream_len_heading")
      ->group("Query-document features");
  app.add_flag("--f_stream_len_inlink", query_doc_flags.f_stream_len_inlink,
               "Enable feature f_stream_len_inlink")
      ->group("Query-document features");
  app.add_flag("--f_stream_len_a", query_doc_flags.f_stream_len_a,
               "Enable feature f_stream_len_a")
      ->group("Query-document features");
  app.add_flag("--f_sum_stream_len", query_doc_flags.f_sum_stream_len,
               "Enable feature f_sum_stream_len")
      ->group("Query-document features");
  app.add_flag("--f_sum_stream_len_body", query_doc_flags.f_sum_stream_len_body,
               "Enable feature f_sum_stream_len_body")
      ->group("Query-document features");
  app.add_flag("--f_sum_stream_len_title",
               query_doc_flags.f_sum_stream_len_title,
               "Enable feature f_sum_stream_len_title")
      ->group("Query-document features");
  app.add_flag("--f_sum_stream_len_heading",
               query_doc_flags.f_sum_stream_len_heading,
               "Enable feature f_sum_stream_len_heading")
      ->group("Query-document features");
  app.add_flag("--f_sum_stream_len_inlink",
               query_doc_flags.f_sum_stream_len_inlink,
               "Enable feature f_sum_stream_len_inlink")
      ->group("Query-document features");
  app.add_flag("--f_sum_stream_len_a", query_doc_flags.f_sum_stream_len_a,
               "Enable feature f_sum_stream_len_a")
      ->group("Query-document features");
  app.add_flag("--f_min_stream_len", query_doc_flags.f_min_stream_len,
               "Enable feature f_min_stream_len")
      ->group("Query-document features");
  app.add_flag("--f_min_stream_len_body", query_doc_flags.f_min_stream_len_body,
               "Enable feature f_min_stream_len_body")
      ->group("Query-document features");
  app.add_flag("--f_min_stream_len_title",
               query_doc_flags.f_min_stream_len_title,
               "Enable feature f_min_stream_len_title")
      ->group("Query-document features");
  app.add_flag("--f_min_stream_len_heading",
               query_doc_flags.f_min_stream_len_heading,
               "Enable feature f_min_stream_len_heading")
      ->group("Query-document features");
  app.add_flag("--f_min_stream_len_inlink",
               query_doc_flags.f_min_stream_len_inlink,
               "Enable feature f_min_stream_len_inlink")
      ->group("Query-document features");
  app.add_flag("--f_min_stream_len_a", query_doc_flags.f_min_stream_len_a,
               "Enable feature f_min_stream_len_a")
      ->group("Query-document features");
  app.add_flag("--f_max_stream_len", query_doc_flags.f_max_stream_len,
               "Enable feature f_max_stream_len")
      ->group("Query-document features");
  app.add_flag("--f_max_stream_len_body", query_doc_flags.f_max_stream_len_body,
               "Enable feature f_max_stream_len_body")
      ->group("Query-document features");
  app.add_flag("--f_max_stream_len_title",
               query_doc_flags.f_max_stream_len_title,
               "Enable feature f_max_stream_len_title")
      ->group("Query-document features");
  app.add_flag("--f_max_stream_len_heading",
               query_doc_flags.f_max_stream_len_heading,
               "Enable feature f_max_stream_len_heading")
      ->group("Query-document features");
  app.add_flag("--f_max_stream_len_inlink",
               query_doc_flags.f_max_stream_len_inlink,
               "Enable feature f_max_stream_len_inlink")
      ->group("Query-document features");
  app.add_flag("--f_max_stream_len_a", query_doc_flags.f_max_stream_len_a,
               "Enable feature f_max_stream_len_a")
      ->group("Query-document features");
  app.add_flag("--f_mean_stream_len", query_doc_flags.f_mean_stream_len,
               "Enable feature f_mean_stream_len")
      ->group("Query-document features");
  app.add_flag("--f_mean_stream_len_body",
               query_doc_flags.f_mean_stream_len_body,
               "Enable feature f_mean_stream_len_body")
      ->group("Query-document features");
  app.add_flag("--f_mean_stream_len_title",
               query_doc_flags.f_mean_stream_len_title,
               "Enable feature f_mean_stream_len_title")
      ->group("Query-document features");
  app.add_flag("--f_mean_stream_len_heading",
               query_doc_flags.f_mean_stream_len_heading,
               "Enable feature f_mean_stream_len_heading")
      ->group("Query-document features");
  app.add_flag("--f_mean_stream_len_inlink",
               query_doc_flags.f_mean_stream_len_inlink,
               "Enable feature f_mean_stream_len_inlink")
      ->group("Query-document features");
  app.add_flag("--f_mean_stream_len_a", query_doc_flags.f_mean_stream_len_a,
               "Enable feature f_mean_stream_len_a")
      ->group("Query-document features");
  app.add_flag("--f_variance_stream_len", query_doc_flags.f_variance_stream_len,
               "Enable feature f_variance_stream_len")
      ->group("Query-document features");
  app.add_flag("--f_variance_stream_len_body",
               query_doc_flags.f_variance_stream_len_body,
               "Enable feature f_variance_stream_len_body")
      ->group("Query-document features");
  app.add_flag("--f_variance_stream_len_title",
               query_doc_flags.f_variance_stream_len_title,
               "Enable feature f_variance_stream_len_title")
      ->group("Query-document features");
  app.add_flag("--f_variance_stream_len_heading",
               query_doc_flags.f_variance_stream_len_heading,
               "Enable feature f_variance_stream_len_heading")
      ->group("Query-document features");
  app.add_flag("--f_variance_stream_len_inlink",
               query_doc_flags.f_variance_stream_len_inlink,
               "Enable feature f_variance_stream_len_inlink")
      ->group("Query-document features");
  app.add_flag("--f_variance_stream_len_a",
               query_doc_flags.f_variance_stream_len_a,
               "Enable feature f_variance_stream_len_a")
      ->group("Query-document features");
  app.add_flag("--f_tpscore", query_doc_flags.f_tpscore,
               "Enable feature f_tpscore")
      ->group("Query-document features");
  app.add_flag("--f_bm25_bigram_u8", query_doc_flags.f_bm25_bigram_u8,
               "Enable feature f_bm25_bigram_u8")
      ->group("Query-document features");
  app.add_flag("--f_bm25_tp_dist_w100", query_doc_flags.f_bm25_tp_dist_w100,
               "Enable feature f_bm25_tp_dist_w100")
      ->group("Query-document features");
  app.add_flag("--f_tag_title_qry_count", query_doc_flags.f_tag_title_qry_count,
               "Enable feature f_tag_title_qry_count")
      ->group("Query-document features");
  app.add_flag("--f_tag_heading_qry_count",
               query_doc_flags.f_tag_heading_qry_count,
               "Enable feature f_tag_heading_qry_count")
      ->group("Query-document features");
  app.add_flag("--f_tag_mainbody_qry_count",
               query_doc_flags.f_tag_mainbody_qry_count,
               "Enable feature f_tag_mainbody_qry_count")
      ->group("Query-document features");
  app.add_flag("--f_tag_inlink_qry_count",
               query_doc_flags.f_tag_inlink_qry_count,
               "Enable feature f_tag_inlink_qry_count")
      ->group("Query-document features");
  app.add_flag("--f_tag_title_count", query_doc_flags.f_tag_title_count,
               "Enable feature f_tag_title_count")
      ->group("Query-document features");
  app.add_flag("--f_tag_heading_count", query_doc_flags.f_tag_heading_count,
               "Enable feature f_tag_heading_count")
      ->group("Query-document features");
  app.add_flag("--f_tag_inlink_count", query_doc_flags.f_tag_inlink_count,
               "Enable feature f_tag_inlink_count")
      ->group("Query-document features");
  app.add_flag("--f_tag_applet_count", query_doc_flags.f_tag_applet_count,
               "Enable feature f_tag_applet_count")
      ->group("Query-document features");
  app.add_flag("--f_tag_object_count", query_doc_flags.f_tag_object_count,
               "Enable feature f_tag_object_count")
      ->group("Query-document features");
  app.add_flag("--f_tag_embed_count", query_doc_flags.f_tag_embed_count,
               "Enable feature f_tag_embed_count")
      ->group("Query-document features");
  app.add_flag("--f_len", static_doc_flags.f_len, "Enable feature f_len")
      ->group("Static document features");
  app.add_flag("--f_title_len", static_doc_flags.f_title_len,
               "Enable feature f_title_len")
      ->group("Static document features");
  app.add_flag("--f_visterm_len", static_doc_flags.f_visterm_len,
               "Enable feature f_visterm_len")
      ->group("Static document features");
  app.add_flag("--f_url_len", static_doc_flags.f_url_len,
               "Enable feature f_url_len")
      ->group("Static document features");
  app.add_flag("--f_url_depth", static_doc_flags.f_url_depth,
               "Enable feature f_url_depth")
      ->group("Static document features");
  app.add_flag("--f_avg_term_len", static_doc_flags.f_avg_term_len,
               "Enable feature f_avg_term_len")
      ->group("Static document features");
  app.add_flag("--f_entropy", static_doc_flags.f_entropy,
               "Enable feature f_entropy")
      ->group("Static document features");
  app.add_flag("--f_stop_cover", static_doc_flags.f_stop_cover,
               "Enable feature f_stop_cover")
      ->group("Static document features");
  app.add_flag("--f_frac_stop", static_doc_flags.f_frac_stop,
               "Enable feature f_frac_stop")
      ->group("Static document features");
  app.add_flag("--f_frac_anchor_text", static_doc_flags.f_frac_anchor_text,
               "Enable feature f_frac_anchor_text")
      ->group("Static document features");
  app.add_flag("--f_frac_vis_text", static_doc_flags.f_frac_vis_text,
               "Enable feature f_frac_vis_text")
      ->group("Static document features");
  app.add_flag("--f_frac_table_text", static_doc_flags.f_frac_table_text,
               "Enable feature f_frac_table_text")
      ->group("Static document features");
  app.add_flag("--f_frac_td_text", static_doc_flags.f_frac_td_text,
               "Enable feature f_frac_td_text")
      ->group("Static document features");
  app.add_flag("--f_is_wikipedia", static_doc_flags.f_is_wikipedia,
               "Enable feature f_is_wikipedia")
      ->group("Static document features");

  app.set_config("-c,--config", "", "Read configuration from file", false);
  CLI11_PARSE(app, argc, argv);

  std::ofstream outfile(output_file, std::ofstream::out);
  outfile << std::fixed << std::setprecision(5);

  query_environment indri_env;
  query_environment_adapter qry_env(&indri_env);
  qry_env.add_index(indri_index);

  indri::collection::Repository repo;
  repo.openRead(indri_index);
  auto index = (*repo.indexes())[0];

  using clock = std::chrono::high_resolution_clock;

  // load fwd_idx
  std::cerr << "Loading " << fwd_index_file << "..." << std::endl;
  auto start = clock::now();
  std::ifstream ifs_fwd(fwd_index_file);
  cereal::BinaryInputArchive iarchive_fwd(ifs_fwd);
  ForwardIndex fwd_idx;
  iarchive_fwd(fwd_idx);

  auto stop = clock::now();
  auto load_time =
      std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
  std::cerr << "Loaded " << fwd_index_file << " in " << load_time.count()
            << " ms" << std::endl;

  // load lexicon
  std::cerr << "Loading " << lexicon_file << "..." << std::endl;
  start = clock::now();
  std::ifstream lexicon_f(lexicon_file);
  cereal::BinaryInputArchive iarchive_lex(lexicon_f);
  Lexicon lexicon;
  iarchive_lex(lexicon);

  stop = clock::now();
  load_time =
      std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
  std::cerr << "Loaded " << lexicon_file << " in " << load_time.count() << " ms"
            << std::endl;

  // load static doc list
  std::cerr << "Loading " << static_doc_file << "..." << std::endl;
  start = clock::now();
  std::ifstream static_doc_f(static_doc_file);
  cereal::BinaryInputArchive iarchive_statdoc(static_doc_f);
  StaticDocFeatureList statdoc_list;
  iarchive_statdoc(statdoc_list);

  stop = clock::now();
  load_time =
      std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
  std::cerr << "Loaded " << static_doc_file << " in " << load_time.count()
            << " ms" << std::endl;

  // load query file
  std::ifstream ifs(query_file);
  if (!ifs.is_open()) {
    std::cerr << "Could not open file: " << query_file << std::endl;
    exit(EXIT_FAILURE);
  }
  query_train_file qtfile(ifs, lexicon);
  ifs.close();
  ifs.clear();

  // load trec run file
  ifs.open(trec_file);
  trec_run_file trec_run(ifs);
  trec_run.parse();
  ifs.close();
  ifs.clear();

  FieldIdMap field_id_map;
  const std::vector<std::string> idx_fields = {
      "title", "heading", "mainbody", "inlink", "applet", "object", "embed"};
  for (const std::string &field_str : idx_fields) {
    int field_id = index->field(field_str);
    field_id_map.insert(std::make_pair(field_str, field_id));
  }

  FeatureExtractor fe(lexicon, field_id_map, query_doc_flags, static_doc_flags);

  auto queries = qtfile.get_queries();
  for (auto &qry : queries) {
    std::vector<double> stage0_scores = trec_run.get_scores(qry.id);
    std::vector<int> docno_labels = trec_run.get_labels(qry.id);
    std::vector<std::string> docnos = trec_run.get_result(qry.id);
    std::vector<docid_t> docids =
        qry_env.document_ids_from_metadata("docno", docnos);

    auto start = clock::now();

    for (size_t i = 0; i < docids.size(); ++i) {
      auto const docid = docids[i];
      auto const docno = docnos[i];
      auto const label = docno_labels[i];

      auto doc_idx = fwd_idx[docid];
      doc_idx.decompress();

      doc_entry doc_entry;
      statdoc_entry statdoc_entry;

      auto terms = doc_idx.terms();
      std::unordered_map<uint32_t, std::vector<uint32_t>> positions;
      for (size_t i = 0; i < terms.size(); i++) {
        positions[terms[i]].push_back(i);
      }

      // set original run score as a feature for training
      doc_entry.stage0_score = stage0_scores[i];

      // query-document features
      fe.extract(qry, doc_entry, doc_idx, positions);
      // static document features
      statdoc_entry = statdoc_list[docid].dentry;

      FeaturePresenter presenter(doc_entry, query_doc_flags, statdoc_entry,
                                 static_doc_flags);
      outfile << label << "," << qry.id << "," << docno << presenter
              << std::endl;
    }
    auto stop = clock::now();
    auto load_time =
        std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cerr << "qid: " << qry.id << ", " << docids.size() << " docs in "
              << load_time.count() << " ms" << std::endl;
  }
  return 0;
}
