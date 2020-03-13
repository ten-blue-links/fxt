/*
 * Copyright 2020 The Tesserae authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#include "tesserae/forward_index.hpp"

#include "FastPFor/headers/codecfactory.h"
#include "FastPFor/headers/deltautil.h"

using namespace FastPForLib;

namespace {
IntegerCODEC &codec = *CODECFactory::getFromName("streamvbyte");
};

void Document::compress() {
  m_num_terms = m_terms.size();
  if (0 == m_num_terms) {
    return;
  }

  {
    std::vector<uint32_t> buffer(m_num_terms * 2 + 1024);
    size_t compressedsize = m_unique_terms.size();
    Delta::deltaSIMD(m_unique_terms.data(), m_unique_terms.size());
    codec.encodeArray(m_unique_terms.data(), m_unique_terms.size(),
                      buffer.data(), compressedsize);
    buffer.resize(compressedsize);
    m_unique_terms = buffer;
  }
  {
    std::vector<uint32_t> buffer(m_num_terms);
    size_t compressedsize = m_terms.size();
    codec.encodeArray(m_terms.data(), m_terms.size(), buffer.data(),
                      compressedsize);
    buffer.resize(compressedsize);
    m_terms = buffer;
  }
  {
    std::vector<uint32_t> buffer(m_num_terms);
    size_t compressedsize = m_unique_terms.size();
    codec.encodeArray(m_freqs.data(), m_freqs.size(), buffer.data(),
                      compressedsize);
    buffer.resize(compressedsize);
    m_freqs = buffer;
  }
  {
    for (auto &&ff : m_field_freqs) {
      std::vector<uint32_t> buffer(m_num_terms);
      size_t compressedsize = ff.size();
      codec.encodeArray(ff.data(), ff.size(), buffer.data(), compressedsize);
      buffer.resize(compressedsize);
      ff = buffer;
    }
  }
}

void Document::decompress() {
  if (0 == m_num_terms) {
    return;
  }

  {
    std::vector<uint32_t> terms(m_num_terms);
    size_t recoveredsize = terms.size();
    codec.decodeArray(m_unique_terms.data(), m_unique_terms.size(),
                      terms.data(), recoveredsize);
    terms.resize(recoveredsize);
    Delta::inverseDeltaSIMD(terms.data(), terms.size());
    m_unique_terms = terms;
  }
  {
    std::vector<uint32_t> terms(m_num_terms);
    size_t recoveredsize = terms.size();
    codec.decodeArray(m_terms.data(), m_terms.size(), terms.data(),
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
    codec.decodeArray(m_freqs.data(), m_freqs.size(), freqs.data(),
                      recoveredsize);
    freqs.resize(recoveredsize);
    m_freqs = freqs;
  }
  {
    for (auto &&ff : m_field_freqs) {
      std::vector<uint32_t> freqs(m_num_terms);
      size_t recoveredsize = freqs.size();
      codec.decodeArray(ff.data(), ff.size(), freqs.data(), recoveredsize);
      freqs.resize(recoveredsize);
      ff = freqs;
    }
  }
}
