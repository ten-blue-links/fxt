/*
 * Copyright 2018 The Fxt authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <unordered_map>

#include "CLI/CLI.hpp"
#include "cereal/archives/binary.hpp"

#include "indri/CompressedCollection.hpp"
#include "indri/Repository.hpp"
#include "indri/greedy_vector"

#include "fxt/static_feature.hpp"
#include "fxt/features/static/web_document.hpp"
#include "fxt/field_map.hpp"
#include "fxt/web_1t_stopwords.hpp"

uint32_t field_len(
    const int field_id,
    const indri::utility::greedy_vector<indri::index::FieldExtent> &list) {
  uint32_t len = 0;

  for (const auto &f : list) {
    if (f.id == field_id) {
      len += f.end - f.begin;
    }
  }

  return len;
}

double avg_term_len(
    indri::index::Index *const idx,
    const indri::utility::greedy_vector<lemur::api::TERMID_T> &terms) {
  double avg = 0.0;

  for (lemur::api::TERMID_T i : terms) {
    avg += idx->term(i).size();
  }

  if (terms.size()) {
    avg /= double(terms.size());
  }

  return avg;
}

double entropy(
    indri::index::Index *const idx,
    const indri::utility::greedy_vector<lemur::api::TERMID_T> &terms) {
  double ent = 0.0;
  std::unordered_map<lemur::api::TERMID_T, int> c;

  for (const auto &i : terms) {
    c[i]++;
  }

  for (const auto &w : c) {
    double p = w.second / (double)terms.size();
    ent += p * std::log(p);
  }

  if (ent > 0) {
    ent = -ent;
  }

  return ent;
}

double stop_cover(
    const std::unordered_map<lemur::api::TERMID_T, int> &stopwords,
    const indri::utility::greedy_vector<lemur::api::TERMID_T> &terms) {
  double cov = 0.0;

  for (const auto &i : terms) {
    if (stopwords.find(i) != stopwords.end()) {
      cov += 1.0;
    }
  }

  if (terms.size()) {
    cov /= double(terms.size());
  }

  return cov;
}

double frac_stop(
    const std::unordered_map<lemur::api::TERMID_T, int> &stopwords,
    const indri::utility::greedy_vector<lemur::api::TERMID_T> &terms) {
  int stop = 0;
  int nonstop = 0;
  double ret = 0.0;

  for (const auto &i : terms) {
    if (stopwords.find(i) != stopwords.end()) {
      stop += 1;
    } else {
      nonstop += 1;
    }
  }

  if (nonstop) {
    ret = double(stop) / double(nonstop);
  }

  return ret;
}

double frac_anchor_text(
    indri::index::Index *const idx,
    const indri::utility::greedy_vector<indri::index::FieldExtent> &list) {
  double ret = 0.0;
  int a, b;

  a = idx->field("a");
  b = idx->field("body");
  if (a > 0 && b > 0) {
    size_t body_len = field_len(b, list);
    if (body_len > 0) {
      ret = double(field_len(a, list)) / double(body_len);
    }
  }

  return ret;
}

double frac_vis_text(const statdoc_entry &s, const size_t bytes) {
  double ret = 0.0;

  if (bytes > 0) {
    ret = double(s.len) / double(bytes);
  }

  return ret;
}

// original Bendersky formulation
double frac_td_text(
    indri::index::Index *const idx,
    const indri::utility::greedy_vector<indri::index::FieldExtent> &list) {
  double ret = 0.0;
  int a, b;

  a = idx->field("td");
  b = idx->field("body");
  if (a > 0 && b > 0) {
    size_t body_len = field_len(b, list);
    if (body_len > 0) {
      ret = double(field_len(a, list)) / double(body_len);
    }
  }

  return ret;
}

// look at entire table to catch <thead>, <tfooter>
double frac_table_text(
    indri::index::Index *const idx,
    const indri::utility::greedy_vector<indri::index::FieldExtent> &list) {
  double ret = 0.0;
  int a, b;

  a = idx->field("table");
  b = idx->field("body");
  if (a > 0 && b > 0) {
    size_t body_len = field_len(b, list);
    if (body_len > 0) {
      ret = double(field_len(a, list)) / double(body_len);
    }
  }

  return ret;
}

/*
 * Extract static document features. Many of which are from Bendersky, et al.
 * WSDM (2011).
 */
int main(int argc, char **argv) {
  bool list_fields = false;
  std::string repo_path;
  std::string output_file;

  CLI::App app{"Generate static document features."};
  app.add_flag("-l", list_fields, "List available fields and exit");
  app.add_option("repo_path", repo_path, "Indri repo path")->required();
  app.add_option("output_file", output_file, "Name of output file")->required();
  CLI11_PARSE(app, argc, argv);

  std::ofstream os(output_file, std::ios::binary);
  cereal::BinaryOutputArchive archive(os);

  indri::collection::Repository repo;
  repo.openRead(repo_path);
  indri::collection::Repository::index_state state = repo.indexes();
  const auto &index = (*state)[0];

  if (list_fields) {
    std::cerr << "available fields are:" << std::endl;
    int id = 1;
    while ("" != index->field(id)) {
      std::cerr << "  " << index->field(id++) << std::endl;
    }
    return EXIT_FAILURE;
  }

  {
    // check fields are valid
    FieldMap fields;
    fields.insert(*index, {"body", "title", "table", "td", "a"});
  }

  std::cerr << "extracting static document features..." << std::endl;

  indri::collection::CompressedCollection *collection = repo.collection();
  indri::index::TermListFileIterator *it = index->termListFileIterator();

  std::unordered_map<lemur::api::TERMID_T, int> stopwords;
  for (const auto &str : web_1t_top_100) {
    stopwords[index->term(str)] = 1;
  }

  StaticDocFeatureList statdoc_feat;
  statdoc_feat.push_back({});

  int id = index->documentBase();
  const size_t total_docs = index->documentCount();
  it->startIteration();
  while (!it->finished()) {
    statdoc_entry s;
    indri::index::TermList *list = it->currentEntry();
    std::string doc_name = collection->retrieveMetadatum(id, "docno");
    std::string doc_url = collection->retrieveMetadatum(id, "url");
    indri::api::ParsedDocument *doc = collection->retrieve(id);

    s.len = list->terms().size();
    s.title_len = field_len(index->field("title"), list->fields());
    s.avg_term_len = avg_term_len(index, list->terms());
    s.entropy = entropy(index, list->terms());
    s.stop_cover = stop_cover(stopwords, list->terms());
    s.frac_stop = frac_stop(stopwords, list->terms());
    // assume body field exists
    s.visterm_len = field_len(index->field("body"), list->fields());
    // assume <a>, <body> fields exist
    s.frac_anchor_text = frac_anchor_text(index, list->fields());
    s.frac_vis_text = frac_vis_text(s, doc->contentLength);
    s.frac_table_text = frac_table_text(index, list->fields());
    s.frac_td_text = frac_td_text(index, list->fields());
    set_url_lendep(s, doc_url);
    s.is_wikipedia = uint8_t(is_wikipedia_url(doc_url));

    /* std::cout << doc_name << s << std::endl; */
    statdoc_feat.push_back(s);

    if (id % 100 == 0 || id == index->documentBase() ||
        size_t(id) == total_docs) {
      static size_t last_len = 0;
      std::ostringstream oss;
      double progress = double(id) / double(total_docs);
      progress *= 100;
      std::cerr << std::string(last_len, '\b');
      oss.str("");
      oss << "documents processed: " << id << " (" << int(progress) << "%)";
      last_len = oss.str().size();
      std::cerr << oss.str();
    }

    delete doc;
    id++;
    it->nextEntry();
  }
  std::cerr << std::endl;

  archive(statdoc_feat);
  return 0;
}
