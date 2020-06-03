#include "catch2/catch.hpp"

#include "tesserae/features/proximity/sdm.hpp"
#include "tesserae/forward_index.hpp"
#include "tesserae/inverted_index.hpp"
#include "tesserae/lexicon.hpp"
#include "tesserae/query_train_file.hpp"

#include "fixture/stub_index.hpp"
#include "fixture/stub_query.hpp"

TEST_CASE("sanity check lexicon and forward_index stub") {
  ForwardIndex fwdidx = fixture::stub_forward_index();
  Lexicon lexicon = fixture::stub_lexicon();
  const InvertedIndex invidx = fixture::stub_inverted_index();
  Document doc = fwdidx[16];

  // sanity check that we have the correct representation
  REQUIRE("model" == lexicon.term(doc.terms()[0]));
  REQUIRE("agnostic" == lexicon.term(doc.terms()[1]));

  REQUIRE(300 == lexicon.term("model"));
  REQUIRE(29 == lexicon.term("agnostic"));
}

TEST_CASE("find ordered phrases within a document") {
  const ForwardIndex fwdidx = fixture::stub_forward_index();
  const Lexicon lexicon = fixture::stub_lexicon();
  const InvertedIndex invidx = fixture::stub_inverted_index();
  Document doc = fwdidx[16];
  query_train qry = fixture::stub_query({"model", "agnostic"}, lexicon);
  SdmBigram bigram = {qry.tids[0], qry.tids[1]};
  Sdm sdm;

  uint64_t count = sdm.count_ordered_phrase(bigram, doc);

  REQUIRE(3 == count);
}

TEST_CASE("find unordered phrases within a document") {
  const ForwardIndex fwdidx = fixture::stub_forward_index();
  const Lexicon lexicon = fixture::stub_lexicon();
  const InvertedIndex invidx = fixture::stub_inverted_index();
  Document doc = fwdidx[16];
  query_train qry = fixture::stub_query({"model", "agnostic"}, lexicon);
  SdmBigram bigram = {qry.tids[0], qry.tids[1]};
  Sdm sdm;

  uint64_t count = sdm.count_unordered_phrase(bigram, doc);

  REQUIRE(3 == count);
}

TEST_CASE("score for unigrams is language model") {
  const ForwardIndex fwdidx = fixture::stub_forward_index();
  const Lexicon lexicon = fixture::stub_lexicon();
  const InvertedIndex invidx = fixture::stub_inverted_index();
  Document doc = fwdidx[16];
  query_train qry = fixture::stub_query({"model", "agnostic"}, lexicon);
  // "model"
  Term t1 = lexicon[qry.tids[0]];
  PostingList pl1 = invidx[qry.tids[0]];
  Posting p1 = pl1.get();
  // "agnostic"
  Term t2 = lexicon[qry.tids[1]];
  PostingList pl2 = invidx[qry.tids[1]];
  Posting p2 = pl2.get();
  Sdm sdm;

  double score1 = sdm.score_term(p1[doc.id()], doc.length(), t1.term_count(),
                                 lexicon.term_count());
  REQUIRE(Approx(-4.59750) == score1);

  double score2 = sdm.score_term(p2[doc.id()], doc.length(), t2.term_count(),
                                 lexicon.term_count());
  REQUIRE(Approx(-5.80148) == score2);
}

TEST_CASE("score single ordered phrase within a document") {
  const ForwardIndex fwdidx = fixture::stub_forward_index();
  const Lexicon lexicon = fixture::stub_lexicon();
  const InvertedIndex invidx = fixture::stub_inverted_index();
  Document doc = fwdidx[16];
  query_train qry = fixture::stub_query({"model", "agnostic"}, lexicon);
  Sdm sdm;
  sdm.set_context(qry, invidx);

  std::vector<SdmBigram> phrases = sdm.search_ordered_phrase(doc, fwdidx);
  SdmBigram od = phrases[0];
  double score = sdm.score_term(od.document_count, doc.length(), od.term_count,
                                lexicon.term_count());

  REQUIRE(Approx(-5.80148) == score);
}

TEST_CASE("score single unordered phrase within a document") {
  const ForwardIndex fwdidx = fixture::stub_forward_index();
  const Lexicon lexicon = fixture::stub_lexicon();
  const InvertedIndex invidx = fixture::stub_inverted_index();
  Document doc = fwdidx[16];
  query_train qry = fixture::stub_query({"model", "agnostic"}, lexicon);
  Sdm sdm;
  sdm.set_context(qry, invidx);

  std::vector<SdmBigram> phrases = sdm.search_unordered_phrase(doc, fwdidx);
  SdmBigram uw = phrases[0];
  double score = sdm.score_term(uw.document_count, doc.length(), uw.term_count,
                                lexicon.term_count());

  REQUIRE(Approx(-5.80148) == score);
}

TEST_CASE("empty query has score 0") {
  const ForwardIndex fwdidx = fixture::stub_forward_index();
  const Lexicon lexicon = fixture::stub_lexicon();
  const InvertedIndex invidx = fixture::stub_inverted_index();
  Document doc = fwdidx[1];
  query_train qry = fixture::stub_query({}, lexicon);
  Sdm sdm;

  double score = sdm.extract(qry, doc, lexicon, fwdidx, invidx);

  REQUIRE(Approx(0.0) == score);
}

TEST_CASE("single term query is unweighted language model") {
  const ForwardIndex fwdidx = fixture::stub_forward_index();
  const Lexicon lexicon = fixture::stub_lexicon();
  const InvertedIndex invidx = fixture::stub_inverted_index();
  Document doc = fwdidx[16];
  query_train qry = fixture::stub_query({"model"}, lexicon);
  Sdm sdm;

  double score = sdm.extract(qry, doc, lexicon, fwdidx, invidx);

  REQUIRE(Approx(-4.59750) == score);
}

TEST_CASE("score is reset on each call to extract") {
  const ForwardIndex fwdidx = fixture::stub_forward_index();
  const Lexicon lexicon = fixture::stub_lexicon();
  const InvertedIndex invidx = fixture::stub_inverted_index();
  Document doc = fwdidx[16];
  query_train qry1 = fixture::stub_query({"model"}, lexicon);
  query_train qry2 = fixture::stub_query({"agnostic"}, lexicon);
  Sdm sdm;

  double score1 = sdm.extract(qry1, doc, lexicon, fwdidx, invidx);
  double score2 = sdm.extract(qry2, doc, lexicon, fwdidx, invidx);

  REQUIRE(Approx(-4.59750) == score1);
  REQUIRE(Approx(-5.80148) == score2);
}

TEST_CASE("SDM score for two term query") {
  const ForwardIndex fwdidx = fixture::stub_forward_index();
  const Lexicon lexicon = fixture::stub_lexicon();
  const InvertedIndex invidx = fixture::stub_inverted_index();
  Document doc = fwdidx[16];
  query_train qry = fixture::stub_query({"model", "agnostic"}, lexicon);
  Sdm sdm;

  // The Indri SDM query
  //
  //   #weight(0.8 #combine(model agnostic)
  //           0.15 #combine(#1(model agnostic))
  //           0.05 #combine(#uw8(model agnostic)))
  //
  // results in the following inference network
  //
  //   ScoreAccumulatorNode #weight(0.4 model
  //                                0.4 agnostic
  //                                0.15 #1(model agnostic)
  //                                0.05 #uw8(model agnostic))
  //     WeightNode #weight(0.4 model
  //                        0.4 agnostic
  //                        0.15 #1(model agnostic)
  //                        0.05 #uw8(model agnostic))
  //       TermFrequencyScorerNode model
  //       TermFrequencyScorerNode agnostic
  //       RawScorerNode #1(model agnostic)
  //         ODNode #1(model agnostic)
  //           IndexTerm model -263814880
  //           IndexTerm agnostic -263814752
  //       RawScorerNode #uw8(model agnostic)
  //         UWNode #uw8(model agnostic)
  //           IndexTerm model -263814880
  //           IndexTerm agnostic -263814752
  //
  // trace of network evaluation (a.k.a. scoring)
  //
  // ScoredExtentAccumulator::evaluate
  //   WeightedAndNode::score
  //     ListBeliefNode::score
  //       DirichletTermScoreFunction::scoreOccurrence (#1 model agnostic)
  //     ListBeliefNode::score
  //       DirichletTermScoreFunction::scoreOccurrence (#uw model agnostic)
  //     TermFrequencyBeliefNode::score
  //       DirichletTermScoreFunction::scoreOccurrence (model)
  //     TermFrequencyBeliefNode::score
  //       DirichletTermScoreFunction::scoreOccurrence (agnostic)

  double score = sdm.extract(qry, doc, lexicon, fwdidx, invidx);

  REQUIRE(Approx(-5.31989) == score);
}

TEST_CASE("score non-existent ordered phrase within a document") {
  const ForwardIndex fwdidx = fixture::stub_forward_index();
  const Lexicon lexicon = fixture::stub_lexicon();
  const InvertedIndex invidx = fixture::stub_inverted_index();
  Document doc = fwdidx[16];
  query_train qry = fixture::stub_query({"agnostic", "learn"}, lexicon);
  Sdm sdm;
  sdm.set_context(qry, invidx);

  std::vector<SdmBigram> phrases = sdm.search_ordered_phrase(doc, fwdidx);
  SdmBigram od = phrases[0];
  double score = sdm.score_term(od.document_count, doc.length(), od.term_count,
                                lexicon.term_count());

  REQUIRE(Approx(-8.01589) == score);
}

TEST_CASE("score non-existent unordered phrase within a document") {
  const ForwardIndex fwdidx = fixture::stub_forward_index();
  const Lexicon lexicon = fixture::stub_lexicon();
  const InvertedIndex invidx = fixture::stub_inverted_index();
  Document doc = fwdidx[16];
  query_train qry = fixture::stub_query({"agnostic", "learn"}, lexicon);
  Sdm sdm;
  sdm.set_context(qry, invidx);

  std::vector<SdmBigram> phrases = sdm.search_unordered_phrase(doc, fwdidx);
  SdmBigram uw = phrases[0];
  double score = sdm.score_term(uw.document_count, doc.length(), uw.term_count,
                                lexicon.term_count());

  REQUIRE(Approx(-8.01589) == score);
}

TEST_CASE("SDM score for three term query") {
  const ForwardIndex fwdidx = fixture::stub_forward_index();
  const Lexicon lexicon = fixture::stub_lexicon();
  const InvertedIndex invidx = fixture::stub_inverted_index();
  Document doc = fwdidx[16];
  query_train qry =
      fixture::stub_query({"model", "agnostic", "learn"}, lexicon);
  Sdm sdm;

  // The Indri SDM query
  //
  // #weight(0.8 #combine(model agnostic learn)
  //         0.15 #combine(#1(agnostic learn) #1(model agnostic))
  //         0.05 #combine(#uw8(agnostic learn) #uw8(model agnostic)))
  //
  // results in the following inference network
  //
  // ScoreAccumulatorNode #weight(0.266667 model
  //                              0.266667 agnostic
  //                              0.266667 learn
  //                              0.075 #1(agnostic learn)
  //                              0.075 #1(model agnostic)
  //                              0.025 #uw8(agnostic learn)
  //                              0.025 #uw8(model agnostic))
  //   WeightNode #weight(0.266667 model
  //                      0.266667 agnostic
  //                      0.266667 learn
  //                      0.075 #1(agnostic learn)
  //                      0.075 #1(model agnostic)
  //                      0.025 #uw8(agnostic learn)
  //                      0.025 #uw8(model agnostic))
  //     TermFrequencyScorerNode model
  //     TermFrequencyScorerNode agnostic
  //     TermFrequencyScorerNode learn
  //     RawScorerNode #1(agnostic learn)
  //       ODNode #1(agnostic learn)
  //         IndexTerm agnostic 71729984
  //         IndexTerm learn 71730112
  //     RawScorerNode #1(model agnostic)
  //       ODNode #1(model agnostic)
  //         IndexTerm model 71731536
  //         IndexTerm agnostic 71729984
  //     RawScorerNode #uw8(agnostic learn)
  //       UWNode #uw8(agnostic learn)
  //         IndexTerm agnostic 71729984
  //         IndexTerm learn 71730112
  //     RawScorerNode #uw8(model agnostic)
  //       UWNode #uw8(model agnostic)
  //         IndexTerm model 71731536
  //         IndexTerm agnostic 71729984

  double score = sdm.extract(qry, doc, lexicon, fwdidx, invidx);

  REQUIRE(Approx(-5.80998) == score);
}

TEST_CASE("score ordered phrases 'image segway example'") {
  const ForwardIndex fwdidx = fixture::stub_forward_index();
  const Lexicon lexicon = fixture::stub_lexicon();
  const InvertedIndex invidx = fixture::stub_inverted_index();
  Document doc = fwdidx[16];
  query_train qry =
      fixture::stub_query({"image", "segway", "example"}, lexicon);
  Sdm sdm;
  double score;
  SdmBigram od;
  sdm.set_context(qry, invidx);

  std::vector<SdmBigram> phrases = sdm.search_ordered_phrase(doc, fwdidx);

  od = phrases[0];
  score = sdm.score_term(od.document_count, doc.length(), od.term_count,
                         lexicon.term_count());
  REQUIRE(Approx(-8.01589) == score);

  od = phrases[1];
  score = sdm.score_term(od.document_count, doc.length(), od.term_count,
                         lexicon.term_count());
  REQUIRE(Approx(-8.01589) == score);
}

TEST_CASE("score unordered phrases 'image segway example'") {
  const ForwardIndex fwdidx = fixture::stub_forward_index();
  const Lexicon lexicon = fixture::stub_lexicon();
  const InvertedIndex invidx = fixture::stub_inverted_index();
  Document doc = fwdidx[16];
  query_train qry =
      fixture::stub_query({"image", "segway", "example"}, lexicon);
  Sdm sdm;
  double score;
  SdmBigram uw;
  sdm.set_context(qry, invidx);

  std::vector<SdmBigram> phrases = sdm.search_unordered_phrase(doc, fwdidx);

  uw = phrases[0];
  score = sdm.score_term(uw.document_count, doc.length(), uw.term_count,
                         lexicon.term_count());
  REQUIRE(Approx(-6.90009) == score);

  uw = phrases[1];
  score = sdm.score_term(uw.document_count, doc.length(), uw.term_count,
                         lexicon.term_count());
  REQUIRE(Approx(-6.90009) == score);
}

TEST_CASE("SDM score for query 'image segway example'") {
  const ForwardIndex fwdidx = fixture::stub_forward_index();
  const Lexicon lexicon = fixture::stub_lexicon();
  const InvertedIndex invidx = fixture::stub_inverted_index();
  Document doc = fwdidx[16];
  query_train qry =
      fixture::stub_query({"image", "segway", "example"}, lexicon);
  Sdm sdm;

  double score = sdm.extract(qry, doc, lexicon, fwdidx, invidx);

  REQUIRE(Approx(-6.51295) == score);
}

TEST_CASE("search ordered phrases in documents with length < 2") {
  const ForwardIndex fwdidx = fixture::stub_forward_index();
  const Lexicon lexicon = fixture::stub_lexicon();
  const InvertedIndex invidx = fixture::stub_inverted_index();
  Document doc0 = fwdidx[0];
  Document doc1 = fwdidx[1];
  query_train qry = fixture::stub_query({"one", "two"}, lexicon);
  Sdm sdm;
  sdm.set_context(qry, invidx);

  std::vector<SdmBigram> od0 = sdm.search_ordered_phrase(doc0, fwdidx);
  REQUIRE(0 == doc0.length());
  REQUIRE(1 == od0.size());
  REQUIRE(0 == od0[0].document_count);
  REQUIRE(0 == od0[0].term_count);

  std::vector<SdmBigram> od1 = sdm.search_ordered_phrase(doc1, fwdidx);
  REQUIRE(1 == doc1.length());
  REQUIRE(1 == od1.size());
  REQUIRE(0 == od1[0].document_count);
  REQUIRE(0 == od1[0].term_count);
}

TEST_CASE("search ordered phrases in documents with length >= 2") {
  const ForwardIndex fwdidx = fixture::stub_forward_index();
  const Lexicon lexicon = fixture::stub_lexicon();
  const InvertedIndex invidx = fixture::stub_inverted_index();
  Document doc2 = fwdidx[2];
  Document doc3 = fwdidx[3];
  query_train qry2 = fixture::stub_query({"two", "two"}, lexicon);
  query_train qry3 = fixture::stub_query({"three", "three"}, lexicon);
  Sdm sdm;
  std::vector<SdmBigram> od;

  sdm.set_context(qry2, invidx);
  od = sdm.search_ordered_phrase(doc2, fwdidx);
  REQUIRE(2 == doc2.length());
  REQUIRE(1 == od.size());
  REQUIRE(1 == od[0].document_count);
  REQUIRE(1 == od[0].term_count);

  sdm.set_context(qry3, invidx);
  od = sdm.search_ordered_phrase(doc3, fwdidx);
  REQUIRE(3 == doc3.length());
  REQUIRE(1 == od.size());
  REQUIRE(1 == od[0].document_count);
  REQUIRE(1 == od[0].term_count);
}

TEST_CASE("search unordered phrases in documents with length < 8") {
  const ForwardIndex fwdidx = fixture::stub_forward_index();
  const Lexicon lexicon = fixture::stub_lexicon();
  const InvertedIndex invidx = fixture::stub_inverted_index();
  Document doc0 = fwdidx[0];
  Document doc1 = fwdidx[1];
  Document doc7 = fwdidx[7];
  query_train qry = fixture::stub_query({"seven", "seven"}, lexicon);
  Sdm sdm;
  std::vector<SdmBigram> uw;
  sdm.set_context(qry, invidx);

  uw = sdm.search_unordered_phrase(doc0, fwdidx);
  REQUIRE(0 == doc0.length());
  REQUIRE(1 == uw.size());
  REQUIRE(0 == uw[0].document_count);
  REQUIRE(0 == uw[0].term_count);

  uw = sdm.search_unordered_phrase(doc1, fwdidx);
  REQUIRE(1 == doc1.length());
  REQUIRE(1 == uw.size());
  REQUIRE(0 == uw[0].document_count);
  REQUIRE(0 == uw[0].term_count);

  uw = sdm.search_unordered_phrase(doc7, fwdidx);
  REQUIRE(7 == doc7.length());
  REQUIRE(1 == uw.size());
  REQUIRE(7 == uw[0].document_count);
  REQUIRE(8 == uw[0].term_count);
}

TEST_CASE("search ordered different phrases can overlap") {
  const ForwardIndex fwdidx = fixture::stub_forward_index();
  const Lexicon lexicon = fixture::stub_lexicon();
  const InvertedIndex invidx = fixture::stub_inverted_index();
  Document doc = fwdidx[12];
  query_train qry =
      fixture::stub_query({"one", "two", "three", "four"}, lexicon);
  Sdm sdm;
  std::vector<SdmBigram> od;
  sdm.set_context(qry, invidx);

  od = sdm.search_ordered_phrase(doc, fwdidx);
  REQUIRE(67 == doc.length());
  REQUIRE(3 == od.size());
  // one two
  REQUIRE(2 == od[0].document_count);
  REQUIRE(2 == od[0].term_count);
  // two three
  REQUIRE(2 == od[1].document_count);
  REQUIRE(2 == od[1].term_count);
  // three four
  REQUIRE(2 == od[2].document_count);
  REQUIRE(2 == od[2].term_count);
}

TEST_CASE("search unordered different phrases can overlap") {
  const ForwardIndex fwdidx = fixture::stub_forward_index();
  const Lexicon lexicon = fixture::stub_lexicon();
  const InvertedIndex invidx = fixture::stub_inverted_index();
  Document doc = fwdidx[12];
  query_train qry =
      fixture::stub_query({"one", "two", "three", "four"}, lexicon);
  Sdm sdm;
  std::vector<SdmBigram> uw;
  sdm.set_context(qry, invidx);

  uw = sdm.search_unordered_phrase(doc, fwdidx);
  REQUIRE(67 == doc.length());
  REQUIRE(3 == uw.size());
  // one two
  REQUIRE(2 == uw[0].document_count);
  REQUIRE(3 == uw[0].term_count);
  // two three
  REQUIRE(2 == uw[1].document_count);
  REQUIRE(2 == uw[1].term_count);
  // three four
  REQUIRE(2 == uw[2].document_count);
  REQUIRE(2 == uw[2].term_count);
}

TEST_CASE("SDM score for query 'one two three four' for doc 12") {
  const ForwardIndex fwdidx = fixture::stub_forward_index();
  const Lexicon lexicon = fixture::stub_lexicon();
  const InvertedIndex invidx = fixture::stub_inverted_index();
  Document doc = fwdidx[12];
  query_train qry =
      fixture::stub_query({"one", "two", "three", "four"}, lexicon);
  Sdm sdm;
  double score;

  score = sdm.extract(qry, doc, lexicon, fwdidx, invidx);

  REQUIRE(Approx(-5.32726) == score);
}

TEST_CASE("SDM convert empty query to vector of bigrams") {
  const Lexicon lexicon = fixture::stub_lexicon();
  query_train qry = fixture::stub_query({}, lexicon);
  Sdm sdm;

  std::vector<SdmBigram> result = sdm.bigrams(qry);

  CHECK(0 == result.size());
}

TEST_CASE("SDM convert single term query to vector of bigrams") {
  const Lexicon lexicon = fixture::stub_lexicon();
  query_train qry = fixture::stub_query({"one"}, lexicon);
  Sdm sdm;

  std::vector<SdmBigram> result = sdm.bigrams(qry);

  CHECK(0 == result.size());
}

TEST_CASE("SDM convert query to vector of bigrams") {
  const Lexicon lexicon = fixture::stub_lexicon();
  query_train qry =
      fixture::stub_query({"one", "two", "three", "four"}, lexicon);
  Sdm sdm;
  std::vector<SdmBigram> expected = {
      {341, 518},
      {518, 505},
      {505, 185},
  };

  std::vector<SdmBigram> result = sdm.bigrams(qry);

  CHECK(expected.size() == result.size());
  for (size_t i = 0; i < result.size(); ++i) {
    CHECK(expected[i].first == result[i].first);
    CHECK(expected[i].second == result[i].second);
  }
}

TEST_CASE("SDM get postings for empty query") {
  const Lexicon lexicon = fixture::stub_lexicon();
  const InvertedIndex invidx = fixture::stub_inverted_index();
  query_train qry = fixture::stub_query({}, lexicon);
  Sdm sdm;
  std::map<size_t, Posting> result;

  result = sdm.unigram_postings(qry, invidx);

  CHECK(0 == result.size());
}

TEST_CASE("SDM get postings for query") {
  const Lexicon lexicon = fixture::stub_lexicon();
  const InvertedIndex invidx = fixture::stub_inverted_index();
  query_train qry = fixture::stub_query({"one", "two"}, lexicon);
  Sdm sdm;
  std::map<size_t, Posting> result;

  result = sdm.unigram_postings(qry, invidx);

  CHECK(2 == result.size());
}

TEST_CASE("SDM intersect bigrams for empty query") {
  const Lexicon lexicon = fixture::stub_lexicon();
  const InvertedIndex invidx = fixture::stub_inverted_index();
  query_train qry = fixture::stub_query({}, lexicon);
  Sdm sdm;
  std::vector<std::vector<uint32_t>> result;
  // FIXME - stub these out
  std::vector<SdmBigram> bigrams = sdm.bigrams(qry);
  std::map<size_t, Posting> unigram_postings =
      sdm.unigram_postings(qry, invidx);

  result = sdm.bigram_postings(bigrams, unigram_postings);

  CHECK(0 == result.size());
}

TEST_CASE("SDM intersect bigrams for query") {
  const Lexicon lexicon = fixture::stub_lexicon();
  const InvertedIndex invidx = fixture::stub_inverted_index();
  query_train qry = fixture::stub_query({"one", "two"}, lexicon);
  Sdm sdm;
  std::vector<std::vector<uint32_t>> result;
  std::vector<uint32_t> expected = {11, 12, 13};
  // FIXME - stub these out
  std::vector<SdmBigram> bigrams = sdm.bigrams(qry);
  std::map<size_t, Posting> unigram_postings =
      sdm.unigram_postings(qry, invidx);

  result = sdm.bigram_postings(bigrams, unigram_postings);

  CHECK(1 == result.size());
  CHECK(std::equal(expected.begin(), expected.end(), result[0].begin(),
                   result[0].end()));
}
