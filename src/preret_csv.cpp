/*
 * Copyright 2018 The Tesserae authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#include "CLI/CLI.hpp"
#include "cereal/archives/binary.hpp"

#include "fgen_bigram_qry.hpp"
#include "fgen_term_qry.hpp"
#include "query_features.h"
#include "tesserae/query_train_file.hpp"

char *stdstr_to_cstr(const std::string &s) {
  char *cstr = new char[s.size() + 1];
  std::strcpy(cstr, s.c_str());

  return cstr;
}

int main(int argc, char **argv) {
  std::string query_file;
  std::string unigram_file;
  std::string bigram_file;
  std::string lexicon_file;

  CLI::App app{"Merge unigram and bigram features."};
  app.add_option("query_file", query_file, "Query file")->required();
  app.add_option("unigram_file", unigram_file, "Unigram file")->required();
  app.add_option("bigram_file", bigram_file, "Bigram File")->required();
  app.add_option("lexicon_file", lexicon_file, "Lexicon file")->required();
  CLI11_PARSE(app, argc, argv);

  // load lexicon
  std::ifstream lexicon_f(lexicon_file);
  cereal::BinaryInputArchive iarchive_lex(lexicon_f);
  Lexicon lexicon(Counts(0, 0));
  iarchive_lex(lexicon);

  // load query file
  std::ifstream ifs(query_file);
  if (!ifs.is_open()) {
    std::cerr << "Could not open file: " << query_file << std::endl;
    exit(EXIT_FAILURE);
  }
  query_train_file qtfile(ifs, lexicon);
  ifs.close();
  ifs.clear();

  // init static features
  query_features_init(lexicon.document_count(), lexicon.term_count());

  // load unigram features
  std::cerr << "loading unigram features...";
  auto termmap = load_termmap(unigram_file.c_str());
  std::cerr << " done." << std::endl;

  // load bigram features
  std::cerr << "loading bigram features...";
  auto bigrammap = load_termmap(bigram_file.c_str());
  std::cerr << " done." << std::endl;

  for (auto &qry : qtfile.get_queries()) {
    std::vector<char *> stems;
    std::transform(qry.stems.begin(), qry.stems.end(),
                   std::back_inserter(stems), stdstr_to_cstr);

    std::string buf_unigram, buf_bigram;

    // dump unigram features
    buf_unigram = fgen_term_qry_main(termmap, qry.id, &stems[0], stems.size());
    // dump bigram features
    buf_bigram =
        fgen_bigram_qry_main(bigrammap, qry.id, &stems[0], stems.size());
    std::string buf_common(buf_unigram);
    buf_common.append(buf_bigram);

    std::cout << qry.id;
    if (buf_common.length()) {
      std::cout << buf_common;
    }
    std::cout << std::endl;

    for (auto cstr : stems) {
      delete[] cstr;
    }
  }

  return 0;
}
