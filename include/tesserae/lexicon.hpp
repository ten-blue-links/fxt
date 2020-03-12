/*
 * Copyright 2018 The Tesserae authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#pragma once

#include "cereal/types/map.hpp"
#include "cereal/types/string.hpp"
#include "cereal/types/vector.hpp"

#include <map>
#include <string>
#include <utility>
#include <vector>

struct Counts {
  uint64_t document_count = 0;
  uint64_t term_count = 0;

  Counts() = default;
  Counts(uint64_t dc, uint64_t tc) : document_count(dc), term_count(tc) {}

  template <class Archive>
  void serialize(Archive &archive) {
    archive(document_count, term_count);
  }
};
using FieldCounts = std::map<uint64_t, Counts>;

class Term {
 private:
  Counts counts;
  FieldCounts field_counts;

 public:
  Term() = default;

  Term(const Counts &c, const FieldCounts &fc) : counts(c), field_counts(fc){};

  inline uint64_t document_count() const { return counts.document_count; }

  inline uint64_t term_count() const { return counts.term_count; }

  inline uint64_t field_document_count(uint64_t field) const {
    auto it = field_counts.find(field);
    if (it == field_counts.end()) {
      return 0;
    }
    return it->second.document_count;
  }

  inline uint64_t field_term_count(uint64_t field) const {
    auto it = field_counts.find(field);
    if (it == field_counts.end()) {
      return 0;
    }
    return it->second.term_count;
  }

  template <class Archive>
  void serialize(Archive &archive) {
    archive(counts, field_counts);
  }
};

class Lexicon {
 public:
  // Number of documents in the collection
  inline uint64_t document_count() const { return counts.document_count; }

  // Number of terms in the collection
  inline uint64_t term_count() const { return counts.term_count; }

  // Number of unique terms in the collection
  inline uint64_t length() const { return terms.size(); }

  inline const Term &operator[](size_t pos) const { return terms[pos]; }
  inline Term &operator[](size_t pos) { return terms[pos]; }

  inline size_t term(const std::string &t) {
    auto it = term_id.find(t);
    if (it != term_id.end()) {
      return it->second;
    }
    return oov_term();
  }

  inline size_t oov_term() const { return oov_id; }

  inline bool is_oov(size_t tid) { return tid == oov_term(); }

  void push_back(const std::string &t, const Counts &c, const FieldCounts &fc) {
    auto id = terms.size();
    term_id.insert(std::make_pair(t, id));
    Term term(c, fc);
    terms.push_back(term);
  }

  Lexicon() = delete;

  Lexicon(Counts c) : counts(c) { push_back(oov_str, {}, {}); }

  template <class Archive>
  void serialize(Archive &archive) {
    archive(counts, terms, term_id);
  }

 private:
  const size_t oov_id = 0;
  const std::string oov_str = "xxoov";

  Counts counts;
  std::vector<Term> terms;
  std::map<std::string, size_t> term_id;
};
