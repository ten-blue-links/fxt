/*
 * Copyright 2020 The Tesserae authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <vector>

#include "cereal/archives/binary.hpp"

#include "tesserae/forward_index.hpp"
#include "tesserae/inverted_index.hpp"
#include "tesserae/lexicon.hpp"

void dump_lexicon(Lexicon& lex) {
  // The `Lexicon` constructor already added the OOV term internally so start
  // the counter `i` from 1 to skip adding the OOV term again.
  for (size_t i = 1; i < lex.length(); ++i) {
    auto t = lex[i];
    const auto &str = lex.term(i);
    auto c = t.get_counts();
    std::cout << "{" << std::endl;
    std::cout << "Counts c(" << c.document_count << ", " << c.term_count << ");" << std::endl;
    std::cout << "FieldCounts fc;" << std::endl;
    for (auto& e : t.get_field_counts()) {
      std::cout << "fc.insert(std::make_pair("
        << e.first << ", "
        << "Counts(" << e.second.document_count << ", " << e.second.term_count << ")));"
        << std::endl;
    }
    std::cout << "lexicon.push_back(\"" << str << "\", c, fc);" << std::endl;
    std::cout << "}" << std::endl;
  }
}

void dump_doc(Document& d, size_t id) {
  std::cout << "const std::vector<uint16_t> doc_fields_" << id << " = {";
  for (auto i : d.fields()) { std::cout << i << ", "; }
  std::cout <<  "};" << std::endl;

  std::cout << "const std::vector<uint32_t> doc_terms_" << id << " = {";
  for (auto i : d.terms()) { std::cout << i << ", "; }
  std::cout <<  "};" << std::endl;

  std::cout << "const std::vector<uint32_t> doc_unique_terms_" << id << " = {";
  for (auto i : d.unique_terms()) { std::cout << i << ", "; }
  std::cout <<  "};" << std::endl;

  std::cout << "const std::vector<uint32_t> doc_freqs_" << id << " = {";
  for (auto i : d.freqs()) { std::cout << i << ", "; }
  std::cout <<  "};" << std::endl;

  std::cout << "const std::vector<std::vector<uint32_t>> doc_field_freqs_" << id << " = {";
  for (auto i : d.field_freqs()) {
    std::cout << "{";
    for (auto j : i) {
      std::cout << j << ", ";
    }
    std::cout << "}, ";
  }
  std::cout <<  "};" << std::endl;

  // FIXME - generate field stats
  std::cout << "const std::map<uint16_t, Field> doc_field_stats_" << id << " = {};" << std::endl;

  std::cout <<  "{" << std::endl;
  std::cout << "Document doc_" << id << "(" << id << ");" << std::endl;
  std::cout << "doc_" << id << ".set_fields(doc_fields_" << id << ");" << std::endl;
  std::cout << "doc_" << id << ".set_terms(doc_terms_" << id << ");" << std::endl;
  std::cout << "doc_" << id << ".set_freq(doc_freqs_" << id << ");" << std::endl;
  // FIXME - set doc_field_freqs
  // FIXME - set doc_field_stats
  std::cout << "forward_index.push_back(doc_" << id << ");" << std::endl;
  std::cout <<  "}" << std::endl;
}

void dump_posting(PostingList &p, size_t id) {
  const Posting entry = p.get();

  std::cout <<  "{" << std::endl;
  std::cout << "PostingList pl_" << id << "(\"" << p.term() << "\", " << p.term_count() << ");" << std::endl;
  std::cout << "pl_" << id << ".coding_off();" << std::endl;
  std::cout << "std::vector<uint32_t> docs = {";
  for (auto id : entry.doc) {
    std::cout << id << ",";
  }
  std::cout <<  "};" << std::endl;
  std::cout << "std::vector<uint32_t> freqs = {";
  for (auto id : entry.frequency) {
    std::cout << id << ",";
  }
  std::cout <<  "};" << std::endl;
  std::cout << "pl_" << id << ".set(docs, freqs);" << std::endl;
  std::cout << "inverted_index.push_back(pl_" << id << ");" << std::endl;
  std::cout <<  "}" << std::endl;
}

/*
 * Dump lexicon and documents to use as fixtures.
 */
int main(int argc, char **argv) {
    if (argc != 2) {
      std::cerr << "usage: " << argv[0] << " <index>" << std::endl;
      return 1;
    }

    std::string path = argv[1];
    std::string fwdpath = path + "/forward_index";
    std::string lexpath = path + "/lexicon";
    std::string invpath = path + "/inverted_index";

    using clock = std::chrono::high_resolution_clock;

    std::cerr << "Loading " << fwdpath << "..." << std::endl;
    auto start = clock::now();
    std::ifstream ifs_fwd(fwdpath);
    cereal::BinaryInputArchive iarchive_fwd(ifs_fwd);
    ForwardIndex fwd_idx;
    iarchive_fwd(fwd_idx);

    auto stop = clock::now();
    auto load_time = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cerr << "Loaded " << fwdpath << " in " << load_time.count() << " ms" << std::endl;

    std::cerr << "Loading " << lexpath << "..." << std::endl;
    start = clock::now();
    std::ifstream lexicon_f(lexpath);
    cereal::BinaryInputArchive iarchive_lex(lexicon_f);
    Lexicon lexicon;
    iarchive_lex(lexicon);

    stop = clock::now();
    load_time = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cerr << "Loaded " << lexpath << " in " << load_time.count() << " ms" << std::endl;

    std::cerr << "Loading " << invpath << "..." << std::endl;
    start = clock::now();
    std::ifstream invidx_f(invpath);
    cereal::BinaryInputArchive iarchive_inv(invidx_f);
    InvertedIndex inv_idx;
    iarchive_inv(inv_idx);

    stop = clock::now();
    load_time = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cerr << "Loaded " << invpath << " in " << load_time.count() << " ms" << std::endl;

    std::cout << "#include \"tesserae/forward_index.hpp\"" << std::endl;
    std::cout << "#include \"tesserae/inverted_index.hpp\"" << std::endl;
    std::cout << "#include \"tesserae/lexicon.hpp\"" << std::endl << std::endl;
    std::cout << "namespace fixture {" << std::endl << std::endl;
    std::cout << "Lexicon stub_lexicon() {" << std::endl;
    std::cout << "Lexicon lexicon(Counts("
      << lexicon.document_count() << ", "
      << lexicon.term_count() << "));"
      << std::endl;
    dump_lexicon(lexicon);
    std::cout << "return lexicon;" << std::endl;
    std::cout << "}" << std::endl << std::endl;

    std::cout << "ForwardIndex stub_forward_index() {" << std::endl;
    std::cout << "ForwardIndex forward_index;" << std::endl;
    for (size_t i = 0; i < fwd_idx.size(); ++i) {
      fwd_idx[i].decompress();
      dump_doc(fwd_idx[i], i);
    }
    std::cout << "return forward_index;" << std::endl;
    std::cout << "}" << std::endl << std::endl;
    std::cout << "InvertedIndex stub_inverted_index() {" << std::endl;
    std::cout << "InvertedIndex inverted_index;" << std::endl;
    for (size_t i = 0; i < inv_idx.size(); ++i) {
      dump_posting(inv_idx[i], i);
    }
    std::cout << "return inverted_index;" << std::endl;
    std::cout << "}" << std::endl << std::endl;
    std::cout << "} // namespace fixture" << std::endl;

    return 0;
}
