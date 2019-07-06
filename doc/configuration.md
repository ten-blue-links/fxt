# Configuration

The feature extraction pipeline can be configured via the commandline or
through an INI configuration file.

## Configuration file

Below is an example configuration file using Gov2 as an example.

```
; path to an Indri index
indri_index = gov2

; path to the forward index file
forward_index = gov2.fwd

; path to the lexicon file
lexicon = gov2.lex

; path to the static document feature file
static_doc_file = gov2.static

; Enable/disable feature f_stage0_score
f_stage0_score = 1

; Enable/disable feature f_bm25_atire
f_bm25_atire = 1

; Enable/disable feature f_bm25_atire_body
f_bm25_atire_body = 1

; Enable/disable feature f_bm25_atire_title
f_bm25_atire_title = 1

; Enable/disable feature f_bm25_atire_heading
f_bm25_atire_heading = 1

; Enable/disable feature f_bm25_atire_inlink
f_bm25_atire_inlink = 1

; Enable/disable feature f_bm25_atire_a
f_bm25_atire_a = 1

; Enable/disable feature f_bm25_trec3
f_bm25_trec3 = 1

; Enable/disable feature f_bm25_trec3_body
f_bm25_trec3_body = 1

; Enable/disable feature f_bm25_trec3_title
f_bm25_trec3_title = 1

; Enable/disable feature f_bm25_trec3_heading
f_bm25_trec3_heading = 1

; Enable/disable feature f_bm25_trec3_inlink
f_bm25_trec3_inlink = 1

; Enable/disable feature f_bm25_trec3_a
f_bm25_trec3_a = 1

; Enable/disable feature f_bm25_trec3_kmax
f_bm25_trec3_kmax = 1

; Enable/disable feature f_bm25_trec3_kmax_body
f_bm25_trec3_kmax_body = 1

; Enable/disable feature f_bm25_trec3_kmax_title
f_bm25_trec3_kmax_title = 1

; Enable/disable feature f_bm25_trec3_kmax_heading
f_bm25_trec3_kmax_heading = 1

; Enable/disable feature f_bm25_trec3_kmax_inlink
f_bm25_trec3_kmax_inlink = 1

; Enable/disable feature f_bm25_trec3_kmax_a
f_bm25_trec3_kmax_a = 1

; Enable/disable feature f_lm_dir_2500
f_lm_dir_2500 = 1

; Enable/disable feature f_lm_dir_2500_body
f_lm_dir_2500_body = 1

; Enable/disable feature f_lm_dir_2500_title
f_lm_dir_2500_title = 1

; Enable/disable feature f_lm_dir_2500_heading
f_lm_dir_2500_heading = 1

; Enable/disable feature f_lm_dir_2500_inlink
f_lm_dir_2500_inlink = 1

; Enable/disable feature f_lm_dir_2500_a
f_lm_dir_2500_a = 1

; Enable/disable feature f_lm_dir_1500
f_lm_dir_1500 = 1

; Enable/disable feature f_lm_dir_1500_body
f_lm_dir_1500_body = 1

; Enable/disable feature f_lm_dir_1500_title
f_lm_dir_1500_title = 1

; Enable/disable feature f_lm_dir_1500_heading
f_lm_dir_1500_heading = 1

; Enable/disable feature f_lm_dir_1500_inlink
f_lm_dir_1500_inlink = 1

; Enable/disable feature f_lm_dir_1500_a
f_lm_dir_1500_a = 1

; Enable/disable feature f_lm_dir_1000
f_lm_dir_1000 = 1

; Enable/disable feature f_lm_dir_1000_body
f_lm_dir_1000_body = 1

; Enable/disable feature f_lm_dir_1000_title
f_lm_dir_1000_title = 1

; Enable/disable feature f_lm_dir_1000_heading
f_lm_dir_1000_heading = 1

; Enable/disable feature f_lm_dir_1000_inlink
f_lm_dir_1000_inlink = 1

; Enable/disable feature f_lm_dir_1000_a
f_lm_dir_1000_a = 1

; Enable/disable feature f_tfidf
f_tfidf = 1

; Enable/disable feature f_tfidf_body
f_tfidf_body = 1

; Enable/disable feature f_tfidf_title
f_tfidf_title = 1

; Enable/disable feature f_tfidf_heading
f_tfidf_heading = 1

; Enable/disable feature f_tfidf_inlink
f_tfidf_inlink = 1

; Enable/disable feature f_tfidf_a
f_tfidf_a = 1

; Enable/disable feature f_prob
f_prob = 1

; Enable/disable feature f_prob_body
f_prob_body = 1

; Enable/disable feature f_prob_title
f_prob_title = 1

; Enable/disable feature f_prob_heading
f_prob_heading = 1

; Enable/disable feature f_prob_inlink
f_prob_inlink = 1

; Enable/disable feature f_prob_a
f_prob_a = 1

; Enable/disable feature f_be
f_be = 1

; Enable/disable feature f_be_body
f_be_body = 1

; Enable/disable feature f_be_title
f_be_title = 1

; Enable/disable feature f_be_heading
f_be_heading = 1

; Enable/disable feature f_be_inlink
f_be_inlink = 1

; Enable/disable feature f_be_a
f_be_a = 1

; Enable/disable feature f_dph
f_dph = 1

; Enable/disable feature f_dph_body
f_dph_body = 1

; Enable/disable feature f_dph_title
f_dph_title = 1

; Enable/disable feature f_dph_heading
f_dph_heading = 1

; Enable/disable feature f_dph_inlink
f_dph_inlink = 1

; Enable/disable feature f_dph_a
f_dph_a = 1

; Enable/disable feature f_dfr
f_dfr = 1

; Enable/disable feature f_dfr_body
f_dfr_body = 1

; Enable/disable feature f_dfr_title
f_dfr_title = 1

; Enable/disable feature f_dfr_heading
f_dfr_heading = 1

; Enable/disable feature f_dfr_inlink
f_dfr_inlink = 1

; Enable/disable feature f_dfr_a
f_dfr_a = 1

; Enable/disable feature f_stream_len
f_stream_len = 1

; Enable/disable feature f_stream_len_body
f_stream_len_body = 1

; Enable/disable feature f_stream_len_title
f_stream_len_title = 1

; Enable/disable feature f_stream_len_heading
f_stream_len_heading = 1

; Enable/disable feature f_stream_len_inlink
f_stream_len_inlink = 1

; Enable/disable feature f_stream_len_a
f_stream_len_a = 1

; Enable/disable feature f_sum_stream_len
f_sum_stream_len = 1

; Enable/disable feature f_sum_stream_len_body
f_sum_stream_len_body = 1

; Enable/disable feature f_sum_stream_len_title
f_sum_stream_len_title = 1

; Enable/disable feature f_sum_stream_len_heading
f_sum_stream_len_heading = 1

; Enable/disable feature f_sum_stream_len_inlink
f_sum_stream_len_inlink = 1

; Enable/disable feature f_sum_stream_len_a
f_sum_stream_len_a = 1

; Enable/disable feature f_min_stream_len
f_min_stream_len = 1

; Enable/disable feature f_min_stream_len_body
f_min_stream_len_body = 1

; Enable/disable feature f_min_stream_len_title
f_min_stream_len_title = 1

; Enable/disable feature f_min_stream_len_heading
f_min_stream_len_heading = 1

; Enable/disable feature f_min_stream_len_inlink
f_min_stream_len_inlink = 1

; Enable/disable feature f_min_stream_len_a
f_min_stream_len_a = 1

; Enable/disable feature f_max_stream_len
f_max_stream_len = 1

; Enable/disable feature f_max_stream_len_body
f_max_stream_len_body = 1

; Enable/disable feature f_max_stream_len_title
f_max_stream_len_title = 1

; Enable/disable feature f_max_stream_len_heading
f_max_stream_len_heading = 1

; Enable/disable feature f_max_stream_len_inlink
f_max_stream_len_inlink = 1

; Enable/disable feature f_max_stream_len_a
f_max_stream_len_a = 1

; Enable/disable feature f_mean_stream_len
f_mean_stream_len = 1

; Enable/disable feature f_mean_stream_len_body
f_mean_stream_len_body = 1

; Enable/disable feature f_mean_stream_len_title
f_mean_stream_len_title = 1

; Enable/disable feature f_mean_stream_len_heading
f_mean_stream_len_heading = 1

; Enable/disable feature f_mean_stream_len_inlink
f_mean_stream_len_inlink = 1

; Enable/disable feature f_mean_stream_len_a
f_mean_stream_len_a = 1

; Enable/disable feature f_variance_stream_len
f_variance_stream_len = 1

; Enable/disable feature f_variance_stream_len_body
f_variance_stream_len_body = 1

; Enable/disable feature f_variance_stream_len_title
f_variance_stream_len_title = 1

; Enable/disable feature f_variance_stream_len_heading
f_variance_stream_len_heading = 1

; Enable/disable feature f_variance_stream_len_inlink
f_variance_stream_len_inlink = 1

; Enable/disable feature f_variance_stream_len_a
f_variance_stream_len_a = 1

; Enable/disable feature f_tpscore
f_tpscore = 1

; Enable/disable feature f_bm25_bigram_u8
f_bm25_bigram_u8 = 1

; Enable/disable feature f_bm25_tp_dist_w100
f_bm25_tp_dist_w100 = 1

; Enable/disable feature f_tag_title_count
f_tag_title_count = 1

; Enable/disable feature f_tag_heading_count
f_tag_heading_count = 1

; Enable/disable feature f_tag_inlink_count
f_tag_inlink_count = 1

; Enable/disable feature f_tag_applet_count
f_tag_applet_count = 1

; Enable/disable feature f_tag_object_count
f_tag_object_count = 1

; Enable/disable feature f_tag_embed_count
f_tag_embed_count = 1

; Enable/disable feature f_len
f_len = 1

; Enable/disable feature f_title_len
f_title_len = 1

; Enable/disable feature f_visterm_len
f_visterm_len = 1

; Enable/disable feature f_url_len
f_url_len = 1

; Enable/disable feature f_url_depth
f_url_depth = 1

; Enable/disable feature f_avg_term_len
f_avg_term_len = 1

; Enable/disable feature f_entropy
f_entropy = 1

; Enable/disable feature f_stop_cover
f_stop_cover = 1

; Enable/disable feature f_frac_stop
f_frac_stop = 1

; Enable/disable feature f_frac_anchor_text
f_frac_anchor_text = 1

; Enable/disable feature f_frac_vis_text
f_frac_vis_text = 1

; Enable/disable feature f_frac_table_text
f_frac_table_text = 1

; Enable/disable feature f_frac_td_text
f_frac_td_text = 1
```
