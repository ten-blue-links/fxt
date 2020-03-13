/*
 * Copyright 2018 The Tesserae authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#pragma once

#include <cassert>

#include "cereal/types/string.hpp"
#include "cereal/types/vector.hpp"

class PostingList {
 public:
  std::string term;
  uint32_t totalCount = 0;
  uint32_t m_size;
  std::vector<uint32_t> m_docs;
  std::vector<uint32_t> m_freqs;

  PostingList() {}
  PostingList(const std::string &t, uint32_t tc) : term(t), totalCount(tc) {}

  uint32_t size() const { return m_size; }

  void add_list(std::vector<uint32_t> &docs, std::vector<uint32_t> &freqs);
  std::pair<std::vector<uint32_t>, std::vector<uint32_t>> list();

  template <class Archive>
  void serialize(Archive &archive) {
    archive(term, totalCount, m_size, m_docs, m_freqs);
  }
};

using InvertedIndex = std::vector<PostingList>;
