/*
 * Copyright 2020 The Fxt authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#pragma once

#include <algorithm>
#include <cmath>
#include <limits>
#include <map>
#include <vector>

#include "fxt/features/lmds/lm.hpp"
#include "fxt/forward_index.hpp"
#include "fxt/inverted_index.hpp"
#include "fxt/lexicon.hpp"
#include "fxt/query_train_file.hpp"

/**
 * Statistics for a given term pair both ordered and unordered.
 */
struct SdmBigram {
  size_t first = 0;
  size_t second = 0;
  // Document frequency
  uint64_t document_count = 0;
  // Collection frequency
  uint64_t term_count = 0;

  SdmBigram() = default;

  bool operator==(const SdmBigram &other) const {
    return first == other.first && second == other.second;
  }
};

// Identify each term in the phrase when counting statistics. These types are
// used to index into vectors which is why they are explicitly defined as
// `size_t`.
const size_t TY_FIRST = 0;
const size_t TY_SECOND = 1;

// Initialization value for tracking which window a term was last seen in when
// counting phrases.
const size_t DEFAULT_LAST = std::numeric_limits<size_t>::max();

/**
 * For unordered phrase counting, term positions are tagged with a type (first
 * or second term) so that an unordered search may be performed.
 *
 * See indri::infnet::UnorderedWindowNode::term_position
 */
struct SdmTerm {
  size_t type;
  size_t pos;
  size_t last_idx;

  SdmTerm() = default;

  bool operator<(const SdmTerm &other) { return pos < other.pos; }

  uint32_t start() { return pos; }
  uint32_t end() { return pos + 1; }
};

/**
 * Sequential Dependence Model.
 *
 * A Markov Random Field Model for Term Dependencies
 * Donald Metzler and W. Bruce Croft
 * SIGIR 2005
 * https://dl.acm.org/doi/10.1145/1076034.1076115
 *
 * There is no support for running queries over fields within a document but it
 * could be added in the future.
 *
 * Indri's terminology (assuming there are no document fields):
 *   `_occurrences` - the number of times the phrase occurs in the collection.
 *   `_documentOccurrences` - the number of documents in the collection the
 *   phrase occurs in.
 *   `_documentCount` - the total number of documents in the collection.
 *   `_contextSize` - the length of the collection.
 */
class Sdm {
  const size_t min_qry_len_ = 2;
  // Static window size as there are only term pairs to find, follows
  // Metzler's `dm.pl` Perl script.
  const size_t uw_window_ = 8;
  double score_ = 0.0;
  double mu_;
  double mu_phrase_;
  double term_weight_;
  double ordered_weight_;
  double unordered_weight_;
  DirichletTermScore term_score_fn_;
  DirichletTermScore phrase_score_fn_;

  // Data structures for the current scoring context.
  std::vector<SdmBigram> ctx_bigrams_;
  std::map<size_t, Posting> ctx_tid_postings_;
  std::vector<std::vector<uint32_t>> ctx_docid_;

 public:
  Sdm(double mu = 2500, double mu_phrase = 2500, double term_weight = 0.8,
      double ordered_weight = 0.15, double unordered_weight = 0.05)
      : mu_(mu),
        mu_phrase_(mu_phrase),
        term_weight_(term_weight),
        ordered_weight_(ordered_weight),
        unordered_weight_(unordered_weight),
        term_score_fn_(mu),
        phrase_score_fn_(mu_phrase) {}

  /**
   * Score term features. This reduces to the QL retrieval function.
   */
  inline double score_term(uint32_t document_count, uint32_t document_length,
                           uint32_t term_count, uint32_t collection_length) {
    return term_score_fn_(document_count, document_length, term_count,
                          collection_length);
  }

  /**
   * Score phrase features. It is the QL over phrase statistics and the scoring
   * function has a different smoothing parameter `mu_phrase_`.
   */
  inline double score_phrase(uint32_t document_count, uint32_t document_length,
                             uint32_t term_count, uint32_t collection_length) {
    return phrase_score_fn_(document_count, document_length, term_count,
                            collection_length);
  }

  /**
   * Calculate ordered bigram statistics for the current scoring context. The
   * given `Document` is the current one to be scored.
   */
  std::vector<SdmBigram> search_ordered_phrase(const Document &doc,
                                               const ForwardIndex &fwdidx) {
    std::vector<SdmBigram> od;

    for (size_t i = 0; i < ctx_bigrams_.size(); ++i) {
      SdmBigram bigram = ctx_bigrams_[i];
      bigram.document_count = count_ordered_phrase(bigram, doc);

      if (0 == bigram.document_count) {
        // Phrases that don't exist in the document are
        // `indri::infnet::NullScorerNode` which have a score and contribute to
        // the final score.
        od.push_back(bigram);
        continue;
      }

      // Scan the forward index to find the collection frequency for the given
      // bigram
      for (auto j : ctx_docid_[i]) {
        const auto &d = fwdidx[j];
        bigram.term_count += count_ordered_phrase(bigram, d);
      }
      od.push_back(bigram);
    }

    return od;
  }

  /**
   * Find ordered phrases within a document by counting the within document
   * frequency of the given bigram and the current document. The implementation
   * takes ideas from the following Indri classes:
   * indri::infnet::UnorderedWindowNode, indri::infnet::ContextCountAccumulator.
   */
  uint64_t count_ordered_phrase(const SdmBigram &qry, const Document &doc) {
    uint64_t count = 0;

    if (doc.length() < min_qry_len_) {
      return count;
    }

    // FIXME - Maybe collecting term positions first and sorting them will
    // allow for an earlier exit. See also
    // `indri::infnet::OrderedWindowNode::findNextPossibleOccurrence`.

    size_t last_end = 0;
    const auto &tv = doc.terms();
    for (size_t i = 0, j = 1; i < doc.length() - 1; ++i, ++j) {
      SdmTerm a = {TY_FIRST, i, DEFAULT_LAST};
      SdmTerm b = {TY_SECOND, j, DEFAULT_LAST};
      // no duplicates (overlapping)
      if (a.start() < last_end) {
        continue;
      }
      if (qry.first == tv[a.pos] && qry.second == tv[b.pos]) {
        ++count;
        last_end = b.end();
      }
    }

    return count;
  }

  /**
   * Calculate unordered bigram statistics for the current scoring context. The
   * given `Document` is the current one to be scored.
   */
  std::vector<SdmBigram> search_unordered_phrase(const Document &doc,
                                                 const ForwardIndex &fwdidx) {
    std::vector<SdmBigram> uw;

    for (size_t i = 0; i < ctx_bigrams_.size(); ++i) {
      SdmBigram bigram = ctx_bigrams_[i];
      bigram.document_count = count_unordered_phrase(bigram, doc);

      if (0 == bigram.document_count) {
        // Phrases that don't exist in the document are
        // `indri::infnet::NullScorerNode` which have a score and contribute to
        // the final score.
        uw.push_back(bigram);
        continue;
      }

      // Scan the forward index to find the collection frequency for the given
      // bigram
      for (auto j : ctx_docid_[i]) {
        const auto &d = fwdidx[j];
        bigram.term_count += count_unordered_phrase(bigram, d);
      }
      uw.push_back(bigram);
    }

    return uw;
  }

  /**
   * Find unordered phrases within a document by counting the within document
   * frequency of the given bigram and a given document. The implementation
   * takes ideas from  UnorderedWindowNode::prepare,
   * ContextCountAccumulator::evaluate.
   */
  uint64_t count_unordered_phrase(const SdmBigram &qry, const Document &doc) {
    uint64_t count = 0;
    std::vector<SdmTerm> terms;
    std::set<size_t> seen;

    // Collect term positions
    auto tv = doc.terms();
    for (size_t i = 0; i < doc.length(); ++i) {
      if (qry.first == tv[i]) {
        terms.push_back({TY_FIRST, i, DEFAULT_LAST});
        seen.insert(TY_FIRST);
      }
      if (qry.second == tv[i]) {
        terms.push_back({TY_SECOND, i, DEFAULT_LAST});
        seen.insert(TY_SECOND);
      }
    }

    // Only continue if all terms appear in the document
    if (2 != seen.size()) {
      return count;
    }

    std::sort(terms.begin(), terms.end());

    // Setup `SdmTerm` last positions to track which window the term was last
    // used in.
    std::vector<size_t> last_pos(2, DEFAULT_LAST);
    for (size_t i = 0; i < terms.size(); ++i) {
      terms[i].last_idx = last_pos[terms[i].type];
      last_pos[terms[i].type] = i;
    }

    // Find matching phrases from the term positions
    size_t last_end = 0;
    for (size_t i = 0; i < terms.size(); ++i) {
      size_t found = 1;

      for (size_t j = i + 1; j < terms.size(); ++j) {
        // Exit early if the second term was already found
        if (found >= 2) {
          break;
        }

        auto a = terms[i];
        auto b = terms[j];
        if (a.type == b.type) {
          continue;
        }

        // UnorderedWindowNode.cpp:136
        auto diff = b.end() - a.start();
        if (diff > uw_window_) {
          break;
        }

        // The next `if` statement is a combination of term position matching
        // within the document, and extent matching within the document.
        // Since we are not Indri and we do not need to be generic, we can
        // afford to find the bigram matches at the same time that the term
        // positions are checked. This is the combination of
        // indri::infnet::UnorderedWindowNode::prepare and
        // indri::infnet::ContextCountAccumulator::evaluate.
        // A side effect of doing things this way means that there is no
        // "Extent" type required that is seen in Indri (indri::index::Extent).
        // If this is extended to work with indexed fields then this may need
        // revisiting.
        //
        // `DEFAULT_LAST` is a placeholder for `-1` so the value is explicitly
        // checked here because it is `size_t`. This also avoids type
        // conversion warnings which may result in counting errors, as the
        // original implementation in Indri used an `int` type.
        if (
            // UnorderedWindowNode.cpp:141 -- to count the phrase the second
            // term `b` must not have appeared within the current window `i`.
            (b.last_idx == DEFAULT_LAST || b.last_idx < i) &&
            // ContextCountAccumulator.cpp:88 -- no duplicates
            a.start() >= last_end) {
          ++found;
          ++count;
          last_end = b.end();
        }
      }
    }

    return count;
  }

  /**
   * Represents the scoring method of the `#weight()` query operator from
   * Indri. See `indri::infnet::WeightedAndNode::score`.
   */
  double score_weighted_and(const std::vector<double> &scores,
                            const std::vector<double> &weights) {
    double weight_score = 0.0;

    // A single term query becomes `#combine(foo)`, and therefore has no
    // weighting applied.
    if (1 == scores.size()) {
      return scores[0];
    }

    // FIXME - Add `sumWeight` when testing for three term queries. See
    // src/WeightedAndNode.cpp:253. `sumWeight` should be computed within each
    // for loop within `extract`. Need to confirm if `sumWeight` is only used
    // when scoring fields.
    //
    // FIXME - Add `childResults.size()` from src/WeightedAndNode.cpp:253. I
    // think this would be the case when multiple matches are found within a
    // window.
    for (size_t i = 0; i < scores.size(); ++i) {
      weight_score += weights[i] * scores[i];
    }

    return weight_score;
  }

  /**
   * Convert unigram query into a vector of SDM bigrams.
   */
  std::vector<SdmBigram> bigrams(const query_train &qry) {
    std::vector<SdmBigram> res;

    if (!qry.length()) {
      return res;
    }

    for (size_t i = 0, j = 1; i < qry.length() - 1; ++i, ++j) {
      SdmBigram bigram = {qry.tids[i], qry.tids[j]};
      res.push_back(bigram);
    }
    return res;
  }

  /**
   * Get a `map` of query term to postings.
   *
   * FIXME - Could this be generalized and moved elsewhere (`PostingList`,
   * `InvertedIndex`)?
   */
  std::map<size_t, Posting> unigram_postings(const query_train &qry,
                                             const InvertedIndex &invidx) {
    std::map<size_t, Posting> res;

    if (!qry.length()) {
      return res;
    }

    for (auto term_id : qry.tids) {
      PostingList plist = invidx[term_id];
      res[term_id] = plist.get();
    }

    return res;
  }

  /**
   * Intersect the docid of unigram postings for each bigram.
   */
  std::vector<std::vector<uint32_t>> bigram_postings(
      const std::vector<SdmBigram> bigrams,
      std::map<size_t, Posting> unigram_postings) {
    std::vector<std::vector<uint32_t>> res;

    for (const SdmBigram &b : bigrams) {
      const Posting posting_a = unigram_postings[b.first];
      const Posting posting_b = unigram_postings[b.second];
      std::vector<uint32_t> docid;  // result of intersection

      std::set_intersection(posting_a.doc.begin(), posting_a.doc.end(),
                            posting_b.doc.begin(), posting_b.doc.end(),
                            std::back_inserter(docid));

      res.push_back(docid);
    }

    return res;
  }

  /**
   * Setup the current scoring context.
   */
  void set_context(const query_train &qry, const InvertedIndex invidx) {
    // Bigrams from the query
    ctx_bigrams_ = bigrams(qry);
    // Term id to posting list map
    ctx_tid_postings_ = unigram_postings(qry, invidx);
    // Intersection of docid's from bigram terms
    ctx_docid_ = bigram_postings(ctx_bigrams_, ctx_tid_postings_);
  }

  /**
   * Extract SDM score and weight the various features.
   *
   * FIXME: Should this be renamed to `score` or `evalute`? The clasess with
   *        `compute` functions are doing "extraction" from an API viewpoint.
   */
  double extract(const query_train &qry, const Document &doc,
                 const Lexicon &lex, const ForwardIndex &fwdidx,
                 const InvertedIndex &invidx) {
    // reset score
    score_ = 0.0;

    if (!qry.length()) {
      return score_;
    }

    std::vector<double> feature_scores;
    std::vector<double> feature_weights;

    // Setup data structures required for scoring.
    set_context(qry, invidx);

    // Score the independent terms and compute the weights within
    // Indri's `#combine()` operator. For example `#weight(0.8 #combine(foo
    // bar))` assigns a weight of 0.4 to each of "foo" and "bar".
    for (auto &pentry : ctx_tid_postings_) {
      // Unpack `pentry` for readability
      auto term_id = pentry.first;
      Posting postings = pentry.second;

      Term t = lex[term_id];
      feature_scores.push_back(score_term(postings[doc.id()], doc.length(),
                                          t.term_count(), lex.term_count()));
      feature_weights.push_back(term_weight_ / double(qry.length()));
    }

    // Search for ordered phrases in the current document and forward index,
    // then score and compute weights.
    // FIXME - some form of statistics caching should be used when scoring
    // multiple documents
    std::vector<SdmBigram> od_phrases = search_ordered_phrase(doc, fwdidx);
    for (auto &od : od_phrases) {
      feature_scores.push_back(score_phrase(od.document_count, doc.length(),
                                            od.term_count, lex.term_count()));
      feature_weights.push_back(ordered_weight_ / double(od_phrases.size()));
    }

    // Search for unordered phrases in the current document and forward index,
    // then score and compute weights.
    // FIXME - some form of statistics caching should be used when scoring
    // multiple documents
    std::vector<SdmBigram> uw_phrases = search_unordered_phrase(doc, fwdidx);
    for (auto &uw : uw_phrases) {
      feature_scores.push_back(score_phrase(uw.document_count, doc.length(),
                                            uw.term_count, lex.term_count()));
      feature_weights.push_back(unordered_weight_ / double(uw_phrases.size()));
    }

    score_ = score_weighted_and(feature_scores, feature_weights);

    return score_;
  }
};
