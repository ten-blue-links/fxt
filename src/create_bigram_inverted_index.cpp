/*
 * Copyright 2018 The Tesserae authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#include <unistd.h>
#include <iostream>
#include <tuple>
#include <unordered_set>

#include "indri/DocListIterator.hpp"
#include "indri/Index.hpp"
#include "indri/Repository.hpp"

#include "CLI/CLI.hpp"
#include "cereal/archives/binary.hpp"

#include "tesserae/inverted_index.hpp"
#include "tesserae/query_train_file.hpp"
#include "tesserae/w_scanner.hpp"

using namespace indri::api;

indri::collection::Repository repository;

std::vector<std::string> uniq_terms(const std::vector<std::string> &qry);

struct bigram {
  size_t term_a;
  size_t term_b;

  bigram(size_t a, size_t b) : term_a(a), term_b(b) {}

  bool operator<(const bigram &rhs) const {
    return std::tie(term_a, term_b) < std::tie(rhs.term_a, rhs.term_b);
  }
};

int main(int argc, char *argv[]) {
  constexpr int w_size = 8;  //!< window size
  std::string query_file;
  std::string lexicon_file;
  std::string repo_path;
  std::string output_file;

  CLI::App app{"Create bigram inverted index."};
  app.add_option("-q,--query-file", query_file, "Query filename")->required();
  app.add_option("-r,--repo-path", repo_path, "Repo path")->required();
  app.add_option("-l,--lexicon", lexicon_file, "Lexicon file")->required();
  app.add_option("-o,--out-file", output_file, "Output filename")->required();

  CLI11_PARSE(app, argc, argv);

  //<! open read index
  indri::collection::Repository repo;
  repo.openRead(repo_path);
  indri::collection::Repository::index_state state = repo.indexes();
  const auto &index = (*state)[0];

  //!< init scanner
  WScanner w_scanner = WScanner(w_size);
  //!< prepare the output file

  std::ofstream os(output_file, std::ios::binary);
  cereal::BinaryOutputArchive archive(os);

  InvertedIndex inv_idx;

  // load lexicon
  std::ifstream lexicon_f(lexicon_file);
  cereal::BinaryInputArchive iarchive_lex(lexicon_f);
  Lexicon lexicon(Counts(0, 0));
  iarchive_lex(lexicon);

  uint64_t tot_doc = lexicon.document_count();
  std::cerr << "Open Index, containing: " << tot_doc << " docs\n";

  //!< load query set
  // load query file
  std::ifstream ifs(query_file);
  if (!ifs.is_open()) {
    std::cerr << "Could not open file: " << query_file << std::endl;
    exit(EXIT_FAILURE);
  }
  query_train_file qtfile(ifs, lexicon);
  ifs.close();
  std::vector<std::vector<std::string>> qry_set;
  auto queries = qtfile.get_queries();
  for (auto &qry : queries) {
    qry_set.push_back(qry.stems);
  }

  // bigrams already done
  std::map<bigram, bool> bigram_seen;

  //!< start iterating over queries
  for (std::vector<std::vector<std::string>>::iterator qset_iter =
           qry_set.begin();
       qset_iter != qry_set.end(); qset_iter++) {
    std::string qry_str = "";
    std::vector<std::string> curr_qry = uniq_terms(*qset_iter);
    if (curr_qry.size() < 2) {
      std::cerr << "Omit one term query." << std::endl;
    } else {
      // bigrams of query terms
      std::vector<std::pair<std::string, std::string>> qry_bigrams;
      for (size_t i = 0; i < curr_qry.size(); ++i) {
        for (size_t j = 0; j < curr_qry.size(); ++j) {
          if (i == j) continue;
          qry_bigrams.push_back(std::make_pair(curr_qry[i], curr_qry[j]));
        }
      }

      for (auto &curr_bigram : qry_bigrams) {
        bigram term_bigram(lexicon.term(curr_bigram.first),
                           lexicon.term(curr_bigram.second));

        std::map<bigram, bool>::iterator found;

        found = std::find_if(bigram_seen.begin(), bigram_seen.end(),
                             [&](const std::pair<bigram, bool> &el) {
                               return (el.first.term_a == term_bigram.term_a &&
                                       el.first.term_b == term_bigram.term_b) ||
                                      (el.first.term_a == term_bigram.term_b &&
                                       el.first.term_b == term_bigram.term_a);
                             });

        if (found == bigram_seen.end()) {
          std::vector<indri::index::DocListIterator *> doc_iters(2);
          uint64_t min_df = tot_doc;
          int min_term = -1;
          for (int i = 0; i < 2; ++i) {
            std::string curr_str =
                (i == 0) ? curr_bigram.first : curr_bigram.second;

            qry_str += curr_str;
            qry_str += (i == 0) ? "," : " ";
            // get inverted list iterator and start with the term has smallest
            // df
            size_t tid = lexicon.term(curr_str);
            if (lexicon.is_oov(tid)) {
              // skip terms that don't exist
              break;
            }
            uint64_t curr_df = lexicon[tid].document_count();
            doc_iters[i] = index->docListIterator(curr_str);
            if (!doc_iters[i]) {
              break;
            }
            doc_iters[i]->startIteration();
            if (curr_df <= min_df) {
              min_term = i;
              min_df = curr_df;
            }
          }

          if (!doc_iters[0] || !doc_iters[1]) {
            qry_str = "";
            continue;
          }

          //!< start counting and then dumping out the results
          std::vector<std::pair<lemur::api::DOCID_T, uint64_t>>
              window_postings = w_scanner.window_count(doc_iters, min_term);

          PostingList pl(qry_str, w_scanner.collection_cnt());
          std::vector<uint32_t> docs;
          std::vector<uint32_t> freqs;
          for (auto post_iter = window_postings.begin();
               post_iter != window_postings.end(); ++post_iter) {
            docs.push_back(post_iter->first);
            freqs.push_back(post_iter->second);
          }
          qry_str = "";
          if (docs.size() == 0) {
            continue;
          }
          pl.add_list(docs, freqs);
          inv_idx.push_back(pl);

          bigram_seen.emplace(
              std::pair<bigram, bool>({lexicon.term(curr_bigram.first),
                                       lexicon.term(curr_bigram.second)},
                                      true));
          delete doc_iters[0];
          delete doc_iters[1];
        }
      }
    }
    w_scanner.set_wsize(w_size);
  }
  archive(inv_idx);
  return 0;
}

std::vector<std::string> uniq_terms(const std::vector<std::string> &qry) {
  std::vector<std::string> qry_tokens;         //!< original order must be kept
  std::unordered_set<std::string> uniq_terms;  //!< deduplicate
  for (size_t i = 0; i < qry.size(); ++i) {
    std::string curr_token = qry[i];
    if (uniq_terms.empty() || uniq_terms.find(curr_token) == uniq_terms.end()) {
      qry_tokens.push_back(curr_token);
      uniq_terms.insert(curr_token);
    }
  }
  return qry_tokens;
}
