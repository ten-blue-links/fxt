/*
 * Copyright 2018 The Tesserae authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#pragma once

#include <algorithm>
#include <iterator>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

#include "cereal/types/map.hpp"
#include "cereal/types/utility.hpp"
#include "cereal/types/vector.hpp"

class Field {
  uint16_t m_tag_count = 0;
  uint16_t m_field_len = 0;
  uint16_t m_field_min_len = std::numeric_limits<uint16_t>::max();
  uint16_t m_field_max_len = 0;
  uint32_t m_field_len_sum_sqrs = 0;

 public:
  Field() = default;
  Field(uint16_t tag_count, uint16_t field_len, uint16_t field_min_len,
        uint16_t field_max_len, uint32_t field_len_sum_sqrs)
      : m_tag_count(tag_count),
        m_field_len(field_len),
        m_field_min_len(field_min_len),
        m_field_max_len(field_max_len),
        m_field_len_sum_sqrs(field_len_sum_sqrs) {}

  uint16_t tag_count() const { return m_tag_count; };
  uint16_t field_len() const { return m_field_len; };
  uint16_t field_min_len() const { return m_field_min_len; };
  uint16_t field_max_len() const { return m_field_max_len; };
  uint32_t field_len_sum_sqrs() const { return m_field_len_sum_sqrs; };

  void tag_count(uint16_t tag_count) { m_tag_count = tag_count; };
  void field_len(uint16_t field_len) { m_field_len = field_len; };
  void field_min_len(uint16_t field_min_len) {
    m_field_min_len = field_min_len;
  };
  void field_max_len(uint16_t field_max_len) {
    m_field_max_len = field_max_len;
  };
  void field_len_sum_sqrs(uint32_t field_len_sum_sqrs) {
    m_field_len_sum_sqrs = field_len_sum_sqrs;
  };

  template <class Archive>
  void serialize(Archive &archive) {
    archive(m_tag_count, m_field_len, m_field_min_len, m_field_max_len,
            m_field_len_sum_sqrs);
  }
};

/**
 * Represents a document in the forward index. It is preferred to store
 * document fields as vectors for optimal compression.
 */
class Document {
  // A document `id` is a `uint32_t` for compression in postings, but is
  // instantiated here as a `size_t` because they are often used as indexes in
  // STL containers.
  size_t id_;
  // Used for compression/decompression
  // FIXME - change to stored_count?
  size_t m_num_terms;
  std::vector<uint32_t> m_unique_terms;
  std::vector<uint32_t> m_terms;
  std::vector<uint32_t> m_freqs;
  std::vector<uint16_t> m_fields;
  std::vector<std::vector<uint32_t>> m_field_freqs;
  std::map<uint16_t, Field> m_field_stats;

 public:
  // This constructor is required for cereal
  explicit Document() : id_(0), m_num_terms(0) {}

  Document(size_t i) : id_(i), m_num_terms(0) {}

  size_t id() const { return id_; }
  uint32_t length() const { return m_terms.size(); }

  const std::vector<uint16_t> fields() const { return m_fields; }
  const std::vector<uint32_t> terms() const { return m_terms; }
  const std::vector<uint32_t> unique_terms() const { return m_unique_terms; }
  const std::vector<uint32_t> freqs() const { return m_freqs; }
  const std::vector<std::vector<uint32_t>> field_freqs() const { return m_field_freqs; }
  const std::map<uint16_t, Field> field_stats() const { return m_field_stats; }

  void set_fields(const std::vector<uint16_t> &fields) {
    m_fields = fields;
    m_field_freqs.resize(fields.size());
  }

  /**
   * Set document terms.
   *
   * Also computes a vector of unique terms and updates the term frequency
   * statistics for the document.
   */
  void set_terms(const std::vector<uint32_t> &terms) {
    // collect unique terms
    std::set<uint32_t> terms_set(terms.begin(), terms.end());
    std::vector<uint32_t> unique_terms(terms_set.begin(), terms_set.end());
    m_unique_terms = unique_terms;

    // update frequency statistics
    m_freqs.resize(m_unique_terms.size());
    std::unordered_map<uint32_t, uint32_t> freqs;
    for (size_t i = 0; i < terms.size(); i++) {
      freqs[terms[i]] += 1;
    }
    for (auto &f : freqs) {
      set_freq(f.first, f.second);
    }

    m_terms = terms;
  }

  uint32_t freq(uint32_t term) const {
    auto it =
        std::lower_bound(m_unique_terms.begin(), m_unique_terms.end(), term);
    if (it == m_unique_terms.end()) {
      return 0;
    }
    auto idx = std::distance(m_unique_terms.begin(), it);
    return m_freqs.at(idx);
  }

  /**
   * Set frequency of a document term.
   */
  void set_freq(uint32_t term, uint32_t freq) {
    auto it =
        std::lower_bound(m_unique_terms.begin(), m_unique_terms.end(), term);
    if (it == m_unique_terms.end()) {
      return;
    }
    auto idx = std::distance(m_unique_terms.begin(), it);
    m_freqs[idx] = freq;
  }

  void set_freq(const std::vector<uint32_t>& freqs) {
    m_freqs = freqs;
  }

  uint32_t freq(uint16_t field_id, uint32_t term) const {
    auto it =
        std::lower_bound(m_unique_terms.begin(), m_unique_terms.end(), term);
    if (it == m_unique_terms.end()) {
      return 0;
    }
    size_t idx = std::distance(m_unique_terms.begin(), it);
    auto f_it = std::find(m_fields.begin(), m_fields.end(), field_id);
    if (f_it == m_fields.end()) {
      return 0;
    }
    auto idx2 = std::distance(m_fields.begin(), f_it);
    if (idx >= m_field_freqs.at(idx2).size()) return 0;
    return m_field_freqs.at(idx2).at(idx);
  }

  /**
   * Set term frequency within a document field.
   */
  void set_freq(uint16_t field_id, uint32_t term, uint32_t freq) {
    auto it =
        std::lower_bound(m_unique_terms.begin(), m_unique_terms.end(), term);
    if (it == m_unique_terms.end()) {
      return;
    }
    auto idx = std::distance(m_unique_terms.begin(), it);
    auto f_it = std::find(m_fields.begin(), m_fields.end(), field_id);
    if (f_it == m_fields.end()) {
      return;
    }
    auto idx2 = std::distance(m_fields.begin(), f_it);
    m_field_freqs[idx2].resize(m_unique_terms.size());
    m_field_freqs[idx2][idx] = freq;
  }

  uint16_t tag_count(uint16_t field_id) const {
    if (m_field_stats.find(field_id) == m_field_stats.end()) {
      return 0;
    }
    return m_field_stats.at(field_id).tag_count();
  }

  void set_tag_count(uint16_t field_id, uint32_t tag_count) {
    m_field_stats[field_id].tag_count(tag_count);
  }

  uint16_t field_len(uint16_t field_id) const {
    if (m_field_stats.find(field_id) == m_field_stats.end()) {
      return 0;
    }
    return m_field_stats.at(field_id).field_len();
  }

  void set_field_len(uint16_t field_id, uint16_t field_len) {
    m_field_stats[field_id].field_len(field_len);
  }

  uint16_t field_min_len(uint16_t field_id) const {
    if (m_field_stats.find(field_id) == m_field_stats.end()) {
      return 0;
    }
    return m_field_stats.at(field_id).field_min_len();
  }

  void set_field_min_len(uint16_t field_id, uint16_t field_min_len) {
    m_field_stats[field_id].field_min_len(field_min_len);
  }

  uint16_t field_max_len(uint16_t field_id) const {
    if (m_field_stats.find(field_id) == m_field_stats.end()) {
      return 0;
    }
    return m_field_stats.at(field_id).field_max_len();
  }

  void set_field_max_len(uint16_t field_id, uint16_t field_max_len) {
    m_field_stats[field_id].field_max_len(field_max_len);
  }

  uint32_t field_len_sum_sqrs(uint16_t field_id) const {
    if (m_field_stats.find(field_id) == m_field_stats.end()) {
      return 0;
    }
    return m_field_stats.at(field_id).field_len_sum_sqrs();
  }

  void set_field_len_sum_sqrs(uint16_t field_id, uint32_t field_len_sum_sqrs) {
    m_field_stats[field_id].field_len_sum_sqrs(field_len_sum_sqrs);
  }

  /**
   * Compress document. See `src/compression.cpp`
   */
  void compress();

  /**
   * Decompress document. See `src/compression.cpp`
   */
  void decompress();

  /**
   * Map the term ids in `m_terms` into a local document space based on
   * `m_unique_terms`. This called before encoding `m_terms` with `streamvbyte`
   * in `Document::compress`.
   */
  void remap_local() {
    std::vector<uint32_t> remap;
    for (auto &&t : m_terms) {
      auto it = std::lower_bound(m_unique_terms.begin(), m_unique_terms.end(), t);
      uint32_t idx = std::distance(m_unique_terms.begin(), it);
      remap.push_back(idx);
    }
    m_terms = remap;
  }

  /**
   * Map the term ids in `m_terms` into the global corpus space based on
   * `m_unique_terms`. This called after decoding `m_terms` with `streamvbyte`
   * in `Document::decompress`.
   */
  void remap_global() {
    std::vector<uint32_t> remap;
    for (auto &&i : m_terms) {
      remap.push_back(m_unique_terms[i]);
    }
    m_terms = remap;
  }

  template <class Archive>
  void serialize(Archive &archive) {
    archive(id_, m_fields, m_num_terms, m_terms, m_unique_terms, m_freqs,
            m_field_freqs, m_field_stats);
  }
};

using ForwardIndex = std::vector<Document>;
