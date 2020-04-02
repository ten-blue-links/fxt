/*
 * Copyright 2020 The Tesserae authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#include "tesserae/forward_index.hpp"
#include "tesserae/inverted_index.hpp"

#include "FastPFor/headers/codecfactory.h"
#include "FastPFor/headers/deltautil.h"

using namespace FastPForLib;

namespace {
IntegerCODEC &document_codec = *CODECFactory::getFromName("streamvbyte");
IntegerCODEC &posting_codec = *CODECFactory::getFromName("simdfastpfor256");
};

/**
 * Compress document representation.
 */
void Document::compress() {
  m_num_terms = m_terms.size();
  if (0 == m_num_terms) {
    return;
  }

  {
    std::vector<uint32_t> buffer(m_num_terms * 2 + 1024);
    size_t compressedsize = m_unique_terms.size();
    Delta::deltaSIMD(m_unique_terms.data(), m_unique_terms.size());
    document_codec.encodeArray(m_unique_terms.data(), m_unique_terms.size(),
                      buffer.data(), compressedsize);
    buffer.resize(compressedsize);
    m_unique_terms = buffer;
  }
  {
    std::vector<uint32_t> buffer(m_num_terms * 2 + 1024);
    size_t compressedsize = m_terms.size();
    document_codec.encodeArray(m_terms.data(), m_terms.size(), buffer.data(),
                      compressedsize);
    buffer.resize(compressedsize);
    m_terms = buffer;
  }
  {
    std::vector<uint32_t> buffer(m_num_terms);
    size_t compressedsize = m_unique_terms.size();
    document_codec.encodeArray(m_freqs.data(), m_freqs.size(), buffer.data(),
                      compressedsize);
    buffer.resize(compressedsize);
    m_freqs = buffer;
  }
  {
    for (auto &&ff : m_field_freqs) {
      std::vector<uint32_t> buffer(m_num_terms);
      size_t compressedsize = ff.size();
      document_codec.encodeArray(ff.data(), ff.size(), buffer.data(), compressedsize);
      buffer.resize(compressedsize);
      ff = buffer;
    }
  }
}

/**
 * Decompress document representation.
 */
void Document::decompress() {
  if (0 == m_num_terms) {
    return;
  }

  {
    std::vector<uint32_t> terms(m_num_terms);
    size_t recoveredsize = terms.size();
    document_codec.decodeArray(m_unique_terms.data(), m_unique_terms.size(),
                      terms.data(), recoveredsize);
    terms.resize(recoveredsize);
    Delta::inverseDeltaSIMD(terms.data(), terms.size());
    m_unique_terms = terms;
  }
  {
    std::vector<uint32_t> terms(m_num_terms);
    size_t recoveredsize = terms.size();
    document_codec.decodeArray(m_terms.data(), m_terms.size(), terms.data(),
                      recoveredsize);
    terms.resize(recoveredsize);
    std::vector<uint32_t> tmp;
    for (auto &&i : terms) {
      tmp.push_back(m_unique_terms[i]);
    }
    m_terms = tmp;
  }
  {
    std::vector<uint32_t> freqs(m_num_terms);
    size_t recoveredsize = freqs.size();
    document_codec.decodeArray(m_freqs.data(), m_freqs.size(), freqs.data(),
                      recoveredsize);
    freqs.resize(recoveredsize);
    m_freqs = freqs;
  }
  {
    for (auto &&ff : m_field_freqs) {
      std::vector<uint32_t> freqs(m_num_terms);
      size_t recoveredsize = freqs.size();
      document_codec.decodeArray(ff.data(), ff.size(), freqs.data(), recoveredsize);
      freqs.resize(recoveredsize);
      ff = freqs;
    }
  }
}

/**
 * Compress posting list representation.
 */
void PostingList::add_list(std::vector<uint32_t> &docs,
                           std::vector<uint32_t> &freqs) {
  assert(docs.size() == freqs.size());

  m_size = docs.size();
  m_docs.resize(m_size * 2);
  m_freqs.resize(m_size * 2);

  size_t compressedsize = m_docs.size();
  Delta::deltaSIMD(docs.data(), docs.size());
  posting_codec.encodeArray(docs.data(), docs.size(), m_docs.data(), compressedsize);
  m_docs.resize(compressedsize);
  m_docs.shrink_to_fit();

  compressedsize = m_freqs.size();
  posting_codec.encodeArray(freqs.data(), freqs.size(), m_freqs.data(), compressedsize);
  m_freqs.resize(compressedsize);
  m_freqs.shrink_to_fit();
}

/**
 * Decompress posting list representation.
 */
std::pair<std::vector<uint32_t>, std::vector<uint32_t>> PostingList::list() {
  std::vector<uint32_t> docs(m_size);
  std::vector<uint32_t> freqs(m_size);

  size_t recoveredsize = docs.size();
  posting_codec.decodeArray(m_docs.data(), m_docs.size(), docs.data(), recoveredsize);
  docs.resize(recoveredsize);
  Delta::inverseDeltaSIMD(docs.data(), docs.size());

  recoveredsize = freqs.size();
  posting_codec.decodeArray(m_freqs.data(), m_freqs.size(), freqs.data(),
                    recoveredsize);
  freqs.resize(recoveredsize);
  return std::make_pair(docs, freqs);
}
