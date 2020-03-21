/*
 * Copyright 2018 The Tesserae authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#include "indri/CompressedCollection.hpp"
#include "indri/QueryEnvironment.hpp"
#include "indri/Repository.hpp"

#include "CLI/CLI.hpp"
#include "cereal/archives/binary.hpp"

#include "tesserae/doc_lens.hpp"
#include "tesserae/util.hpp"

int main(int argc, char const *argv[]) {
  std::string repo_path;
  std::string doc_lens_file;

  CLI::App app{"Inverted index generator."};
  app.add_option("repo_path", repo_path, "Indri repo path")->required();
  app.add_option("doc_lens_file", doc_lens_file, "Document lens file")
      ->required();
  CLI11_PARSE(app, argc, argv);

  std::ofstream os(doc_lens_file, std::ios::binary);
  cereal::BinaryOutputArchive archive(os);

  indri::collection::Repository repo;
  repo.openRead(repo_path);
  indri::collection::Repository::index_state state = repo.indexes();
  const auto &index = (*state)[0];

  indri::api::QueryEnvironment indri_env;
  indri_env.addIndex(repo_path);

  DocLens doc_lens;
  doc_lens.reserve(index->documentCount() + 1);
  doc_lens.push_back(0);

  ProgressPresenter pp(index->documentCount(), index->documentBase(), 10000,
                       "documents processed: ");
  indri::index::TermListFileIterator *iter = index->termListFileIterator();
  iter->startIteration();
  while (!iter->finished()) {
    indri::index::TermList *list = iter->currentEntry();
    auto &doc_terms = list->terms();
    doc_lens.push_back(doc_terms.size());
    pp.progress();
    iter->nextEntry();
  }

  delete iter;
  archive(doc_lens);

  return 0;
}
