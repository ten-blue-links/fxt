#pragma once

#include "cereal/types/vector.hpp"
#include "cereal/types/string.hpp"

#include "codecfactory.h"
#include "deltautil.h"
#include <cassert>

using namespace FastPForLib;

struct PostingList {

    IntegerCODEC &codec = *CODECFactory::getFromName("simdfastpfor256");

    std::string term;
    uint32_t totalCount = 0;
    uint32_t m_size;
    std::vector<uint32_t> m_docs;
    std::vector<uint32_t> m_freqs;

    PostingList() = default;
    PostingList(const std::string &t, uint32_t tc) : term(t), totalCount(tc) {}

    uint32_t size() const { return m_size; }

    void add_list(std::vector<uint32_t> &docs, std::vector<uint32_t> &freqs) {
        assert(docs.size() == freqs.size());

        m_size = docs.size();
        m_docs.resize(m_size * 2);
        m_freqs.resize(m_size * 2);

        size_t compressedsize = m_docs.size();
        Delta::deltaSIMD(docs.data(), docs.size());
        codec.encodeArray(docs.data(), docs.size(), m_docs.data(), compressedsize);
        m_docs.resize(compressedsize);
        m_docs.shrink_to_fit();

        compressedsize = m_freqs.size();
        codec.encodeArray(freqs.data(), freqs.size(), m_freqs.data(), compressedsize);
        m_freqs.resize(compressedsize);
        m_freqs.shrink_to_fit();
    }

    std::pair<std::vector<uint32_t>, std::vector<uint32_t>> list() {
      std::vector<uint32_t> docs(m_size);
      std::vector<uint32_t> freqs(m_size);

      size_t recoveredsize = docs.size();
      codec.decodeArray(m_docs.data(), m_docs.size(), docs.data(), recoveredsize);
      docs.resize(recoveredsize);
      Delta::inverseDeltaSIMD(docs.data(), docs.size());

      recoveredsize = freqs.size();
      codec.decodeArray(m_freqs.data(), m_freqs.size(), freqs.data(), recoveredsize);
      freqs.resize(recoveredsize);
      return std::make_pair(docs, freqs);
    }

    template <class Archive>
    void serialize(Archive &archive) {
        archive(term, totalCount, m_size, m_docs, m_freqs);
    }
};

using InvertedIndex = std::vector<PostingList>;