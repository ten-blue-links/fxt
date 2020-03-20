/*
 * Copyright 2018 The Tesserae authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#include <future>
#include "indri/CompressedCollection.hpp"
#include "indri/QueryEnvironment.hpp"
#include "indri/Repository.hpp"

#include "CLI/CLI.hpp"
#include "cereal/archives/binary.hpp"

#include "tesserae/field_map.hpp"
#include "tesserae/forward_index.hpp"
#include "tesserae/forward_index_interactor.hpp"

static const std::vector<std::string> _fields = {"body", "title", "heading",
                                                 "inlink", "a"};

int main(int argc, char const *argv[]) {
  std::string repo_path;
  std::string forward_index_file;

  CLI::App app{"Inverted index generator."};
  app.add_option("repo_path", repo_path, "Indri repo path")->required();
  app.add_option("forward_index_file", forward_index_file, "Forward index file")
      ->required();
  CLI11_PARSE(app, argc, argv);

  std::ofstream os(forward_index_file, std::ios::binary);
  cereal::BinaryOutputArchive archive(os);

  indri::collection::Repository repo;
  repo.openRead(repo_path);
  indri::collection::Repository::index_state state = repo.indexes();
  const auto &index = (*state)[0];

  ForwardIndexInteractor interactor;
  FieldMap fields;
  fields.insert(*index, _fields);

  indri::api::QueryEnvironment indri_env;
  indri_env.addIndex(repo_path);

  {
    // dump size of vector
    size_t len = index->documentCount();
    // add 1 for the zero padded document
    len += 1;
    // pad document index zero (unused)
    Document zero;

    archive(len);
    archive(zero);
  }

  size_t total_docs = index->documentCount();
  uint64_t docid = index->documentBase();
  indri::index::TermListFileIterator *iter = index->termListFileIterator();
  iter->startIteration();

  while (!iter->finished()) {
    std::vector<std::future<void>> futures;

    indri::index::TermList *list = iter->currentEntry();
    auto &doc_terms = list->terms();
    auto &doc_fields = list->fields();
    Document document;

    futures.push_back(std::async([&]() {
      std::vector<uint32_t> terms(doc_terms.begin(), doc_terms.end());
      document.set_terms(terms);
    }));

    std::unordered_map<uint16_t, std::vector<indri::index::FieldExtent>>
        fid_extentlist;
    for (auto &f : doc_fields) {
      if (fields.get().find(index->field(f.id)) != fields.get().end()) {
        fid_extentlist[f.id].push_back(f);
      }
    }

    std::vector<uint16_t> fv;
    for (auto &f : fields.get()) {
      fv.push_back(f.second);
    }
    document.set_fields(fv);

    std::unordered_map<size_t, std::unordered_map<uint32_t, uint32_t>>
        field_freqs;
    for (const auto &curr : fid_extentlist) {
      for (const auto &f : curr.second) {
        auto d_len = f.end - f.begin;
        interactor.process_field_len(document, f.id, d_len);
        interactor.process_field_len_sum_sqrs(document, f.id, d_len);
        interactor.process_field_max_len(document, f.id, d_len);
        interactor.process_field_min_len(document, f.id, d_len);
        document.set_tag_count(f.id, document.tag_count(f.id) + 1);

        for (size_t i = f.begin; i < f.end; ++i) {
          field_freqs[f.id][doc_terms[i]] += 1;
        }
      }
    }
    for (auto &&freq : field_freqs) {
      for (auto &&f : freq.second) {
        document.set_freq(freq.first, f.first, f.second);
      }
    }

    for (auto &e : futures) {
      e.get();
    }

    document.compress();
    archive(document);

    if (docid % 10000 == 0 || docid == index->documentBase() ||
        size_t(docid) == total_docs) {
      static size_t last_len = 0;
      std::ostringstream oss;
      double progress = double(docid) / double(total_docs);
      progress *= 100;
      std::cerr << std::string(last_len, '\b');
      oss.str("");
      oss << "documents processed: " << docid << " (" << int(progress) << "%)";
      last_len = oss.str().size();
      std::cerr << oss.str();
    }

    iter->nextEntry();
    ++docid;
  }
  delete iter;
  std::cerr << std::endl;

  return 0;
}
