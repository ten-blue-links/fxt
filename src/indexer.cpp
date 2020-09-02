/*
 * Copyright 2020 The Fxt authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#include <cassert>
#include <filesystem>
#include <iostream>
#include <string>

#include "cereal/archives/binary.hpp"
#include "indri/QueryEnvironment.hpp"
#include "indri/Repository.hpp"

#include "fxt/doc_lens.hpp"
#include "fxt/field_map.hpp"
#include "fxt/forward_index.hpp"
#include "fxt/forward_index_interactor.hpp"
#include "fxt/inverted_index.hpp"
#include "fxt/lexicon.hpp"
#include "fxt/util.hpp"

namespace fs = std::filesystem;

static const std::vector<std::string> _fields = {"body", "title", "heading",
                                                 "inlink", "a"};
class IndriIndexAdapter {
 public:
  indri::collection::Repository repo;
  indri::index::Index *index = nullptr;

  IndriIndexAdapter() = default;

  void open(const std::string path) {
    repo.openRead(path);
    indri::collection::Repository::index_state state = repo.indexes();
    index = (*state)[0];
  }
};

/**
 * Convert an Indri index to a Fxt index.
 *
 * The `InvertedIndex` is constructed in memory so that the postings lists can
 * be organized according to their term id's.
 */
class IndexerInteractor {
  const std::string sep = "/";  // assume unix like filesystem
  const std::string lexicon_file = "lexicon";
  const std::string doclen_file = "doclen";
  const std::string fwdidx_file = "forward_index";
  const std::string invidx_file = "inverted_index";
  const IndriIndexAdapter &indri;
  std::string outpath;

 public:
  IndexerInteractor(const IndriIndexAdapter &index, const std::string path)
      : indri(index), outpath(path) {}

  // Build the lexicon and serialize to file.
  void lexicon() {
    std::string outfile =
        outpath + std::string(sep) + std::string(lexicon_file);
    std::ofstream os(outfile, std::ios::binary);
    cereal::BinaryOutputArchive archive(os);
    ProgressPresenter pp(indri.index->uniqueTermCount(), 1, 10000, "lexicon: ");
    FieldMap fields;
    fields.insert(*indri.index, _fields);

    indri::index::VocabularyIterator *iter = indri.index->vocabularyIterator();
    iter->startIteration();

    Lexicon lexicon(
        Counts(indri.index->documentCount(), indri.index->termCount()));

    while (!iter->finished()) {
      indri::index::DiskTermData *entry = iter->currentEntry();
      indri::index::TermData *termData = entry->termData;

      FieldCounts field_counts;
      for (const int &field_id : fields.values()) {
        Counts c(termData->fields[field_id - 1].documentCount,
                 termData->fields[field_id - 1].totalCount);
        field_counts.insert(std::make_pair(field_id, c));
      }

      // `VocabularyIterator` sanity check
      assert(lexicon.length() + 1 == size_t(indri.index->term(termData->term)));

      Counts counts(termData->corpus.documentCount,
                    termData->corpus.totalCount);
      lexicon.push_back(termData->term, counts, field_counts);
      pp.progress();
      iter->nextEntry();
    }

    delete iter;
    archive(lexicon);
  }

  // Collect a vector of document lengths and serialize to file.
  void document_length() {
    std::string outfile = outpath + std::string(sep) + std::string(doclen_file);
    std::ofstream os(outfile, std::ios::binary);
    cereal::BinaryOutputArchive archive(os);

    DocLens doc_lens;
    doc_lens.reserve(indri.index->documentCount() + 1);
    doc_lens.push_back(0);

    ProgressPresenter pp(indri.index->documentCount(),
                         indri.index->documentBase(), 10000,
                         "document lengths: ");
    indri::index::TermListFileIterator *iter =
        indri.index->termListFileIterator();
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
  }

  // Construct a document forward index with positional and field information.
  void forward_index() {
    std::string outfile = outpath + std::string(sep) + std::string(fwdidx_file);
    std::ofstream os(outfile, std::ios::binary);
    cereal::BinaryOutputArchive archive(os);

    ForwardIndexInteractor interactor;
    FieldMap fields;
    fields.insert(*indri.index, _fields);

    size_t docid = 0;
    {
      // dump size of vector
      size_t len = indri.index->documentCount();
      // add 1 for the zero padded document
      len += 1;
      // pad document index zero (unused)
      Document zero(docid++);

      archive(len);
      archive(zero);
    }

    ProgressPresenter pp(indri.index->documentCount(),
                         indri.index->documentBase(), 10000,
                         "document forward index: ");
    indri::index::TermListFileIterator *iter =
        indri.index->termListFileIterator();
    iter->startIteration();

    while (!iter->finished()) {
      indri::index::TermList *list = iter->currentEntry();
      auto &doc_terms = list->terms();
      auto &doc_fields = list->fields();
      Document document(docid++);

      std::vector<uint32_t> terms(doc_terms.begin(), doc_terms.end());
      document.set_terms(terms);

      std::unordered_map<uint16_t, std::vector<indri::index::FieldExtent>>
          fid_extentlist;
      for (auto &f : doc_fields) {
        if (fields.get().find(indri.index->field(f.id)) != fields.get().end()) {
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

      document.compress();
      archive(document);
      pp.progress();
      iter->nextEntry();
    }

    delete iter;
  }

  // Build an inverted index with compression and serialize to file.
  void inverted_index() {
    std::string outfile = outpath + std::string(sep) + std::string(invidx_file);
    std::ofstream os(outfile, std::ios::binary);
    cereal::BinaryOutputArchive writer(os);
    ProgressPresenter pp(indri.index->uniqueTermCount(), 1, 10000,
                         "inverted index: ");

    // Indri's `VocabularyIterator` and `DocListIterator` enumerate terms in
    // different orders. The `VocabularyIterator` was used to construct the
    // `Lexicon`. The `Lexicon` is constructed before the `InvertedIndex`.
    // Therefore the inverted index is constructed in memory, so that the
    // posting lists are put into the correct "slot" in the `InvertedIndex`
    // according to their term id's.
    InvertedIndex inverted_index;
    // Add 1 for the OOV term
    inverted_index.resize(indri.index->uniqueTermCount() + 1);

    // OOV entry
    // FIXME - Possibly handle this in `InvertedIndex` constructor (which
    // requires changing `InvertedIndex` into a class).
    PostingList pl_oov(Lexicon::oov_str, Lexicon::oov_id);
    pl_oov.coding_off();
    inverted_index[Lexicon::oov_id] = pl_oov;

    indri::index::DocListFileIterator *iter =
        indri.index->docListFileIterator();
    iter->startIteration();
    while (!iter->finished()) {
      indri::index::DocListFileIterator::DocListData *entry =
          iter->currentEntry();
      entry->iterator->startIteration();
      indri::index::TermData *termData = entry->termData;

      PostingList pl(termData->term, termData->corpus.totalCount);
      std::vector<uint32_t> docs;
      std::vector<uint32_t> freqs;

      while (!entry->iterator->finished()) {
        indri::index::DocListIterator::DocumentData *doc =
            entry->iterator->currentEntry();
        docs.push_back(doc->document);
        freqs.push_back(doc->positions.size());
        entry->iterator->nextEntry();
      }
      pl.set(docs, freqs);
      size_t id = indri.index->term(termData->term);
      inverted_index[id] = pl;
      pp.progress();
      iter->nextEntry();
    }
    delete iter;

    writer(inverted_index);
  }
};

int main(int argc, char **argv) {
  if (argc != 3) {
    std::cerr << "usage: " << argv[0] << " <indri_index> <index>" << std::endl;
    return 1;
  }

  std::string indri_path = argv[1];
  std::string index_path = argv[2];

  if (fs::exists(index_path)) {
    std::cerr << "error index path exists" << std::endl;
    return 1;
  }

  if (!fs::create_directory(index_path)) {
    std::cerr << "error creating directory" << std::endl;
    return 1;
  }

  IndriIndexAdapter indri;
  indri.open(indri_path);

  // 1. Build lexicon
  // 2. Document lengths
  // 3. Forward index
  // 4. Inverted index
  IndexerInteractor indexer(indri, index_path);
  indexer.lexicon();
  indexer.document_length();
  indexer.forward_index();
  indexer.inverted_index();

  return 0;
}
