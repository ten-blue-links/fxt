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
};  // namespace

/**
 * Compress document representation.
 */
void Document::compress() {
  m_num_terms = m_terms.size();
  if (0 == m_num_terms) {
    return;
  }

  remap_local();

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
    std::vector<uint32_t> buffer(m_num_terms);
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
      document_codec.encodeArray(ff.data(), ff.size(), buffer.data(),
                                 compressedsize);
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
    m_terms = terms;
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
      document_codec.decodeArray(ff.data(), ff.size(), freqs.data(),
                                 recoveredsize);
      freqs.resize(recoveredsize);
      ff = freqs;
    }
  }

  remap_global();
}

/**
 * Compress posting list representation.
 */
void PostingList::encode(std::vector<uint32_t> &doc,
                         std::vector<uint32_t> &frequency) {
  size_t encoded_size = doc.size();

  assert(doc.size() == frequency.size());

  length_ = doc.size();
  docs_.clear();
  freqs_.clear();
  docs_.resize(length_ * 2);
  freqs_.resize(length_ * 2);

  Delta::deltaSIMD(doc.data(), doc.size());
  posting_codec.encodeArray(doc.data(), doc.size(), docs_.data(), encoded_size);
  docs_.resize(encoded_size);
  docs_.shrink_to_fit();

  posting_codec.encodeArray(frequency.data(), frequency.size(), freqs_.data(),
                            encoded_size);
  freqs_.resize(encoded_size);
  freqs_.shrink_to_fit();
}

/**
 * Decompress posting list representation.
 */
PostingEntry PostingList::decode() {
  std::vector<uint32_t> doc(length_);
  std::vector<uint32_t> frequency(length_);
  size_t decode_size = length_;

  posting_codec.decodeArray(docs_.data(), docs_.size(), doc.data(),
                            decode_size);
  doc.resize(decode_size);
  Delta::inverseDeltaSIMD(doc.data(), doc.size());

  posting_codec.decodeArray(freqs_.data(), freqs_.size(), frequency.data(),
                            decode_size);
  frequency.resize(decode_size);

  return PostingEntry(doc, frequency);
}
