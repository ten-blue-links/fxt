/*
 * Copyright 2018 The Fxt authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

#include "cereal/types/string.hpp"
#include "cereal/types/vector.hpp"

/**
 * A decoded posting list that is returned from `PostingList`.
 */
class Posting {
  std::unordered_map<uint32_t, uint32_t> postings_;

 public:
  Posting() = default;
  Posting(const std::vector<uint32_t> &d, const std::vector<uint32_t> &f)
      : doc(d), frequency(f) {
    // Assume lists are the same size
    for (size_t i = 0; i < doc.size(); ++i) {
      postings_[doc[i]] = frequency[i];
    }
  }

  inline uint32_t &operator[](const size_t &key) { return postings_[key]; }
  inline uint32_t &operator[](size_t &&key) { return postings_[key]; }

  // Aggregate scoring functions need access to these lists.
  std::vector<uint32_t> doc;
  std::vector<uint32_t> frequency;
};

/**
 * A posting list in the inverted index.
 */
class PostingList {
  // FIXME - Is it necessary to store this here? It is already in the Lexicon.
  std::string term_;
  // Number of times term appears in the collection.
  // FIXME - The lexicon also stores this, can it be stored here in one place
  // and removed from the lexicon?
  uint32_t term_count_ = 0;
  uint32_t length_ = 0;
  // Is compression used for this list
  bool coding_on_ = true;
  // Posting entries
  std::vector<uint32_t> docs_;
  std::vector<uint32_t> freqs_;

 public:
  PostingList() {}
  PostingList(const std::string &t, uint32_t tc) : term_(t), term_count_(tc) {}

  std::string term() const { return term_; }

  uint32_t term_count() const { return term_count_; }

  uint32_t length() const { return length_; }

  void coding_on() { coding_on_ = true; }

  void coding_off() { coding_on_ = false; }

  /**
   * Compress posting list. See `src/compression.cpp`.
   */
  void encode(std::vector<uint32_t> &doc, std::vector<uint32_t> &frequency);

  /**
   * Decompress posting list. See `src/compression.cpp`.
   */
  void decode(std::vector<uint32_t> &doc, std::vector<uint32_t> &frequency);

  /**
   * Fetch the posting.
   */
  Posting get() {
    std::vector<uint32_t> doc;
    std::vector<uint32_t> frequency;

    if (coding_on_) {
      decode(doc, frequency);
    } else {
      doc = docs_;
      frequency = freqs_;
    }

    return Posting(doc, frequency);
  }

  /**
   * Set posting data.
   */
  void set(std::vector<uint32_t> &doc, std::vector<uint32_t> &frequency) {
    if (coding_on_) {
      return encode(doc, frequency);
    }

    length_ = doc.size();
    docs_ = doc;
    freqs_ = frequency;
  }

  template <class Archive>
  void serialize(Archive &archive) {
    archive(term_, term_count_, length_, coding_on_, docs_, freqs_);
  }
};

using InvertedIndex = std::vector<PostingList>;
