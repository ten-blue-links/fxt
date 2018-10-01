#pragma once

#include "cereal/types/map.hpp"
#include "cereal/types/utility.hpp"
#include "cereal/types/vector.hpp"

#include "FastPFor/headers/codecfactory.h"
#include "FastPFor/headers/deltautil.h"

using namespace FastPForLib;
IntegerCODEC &codec = *CODECFactory::getFromName("streamvbyte");

class UrlStats {
    uint16_t m_url_slash_count = 0;
    uint16_t m_url_length      = 0;

   public:
    UrlStats() = default;
    UrlStats(uint16_t url_slash_count, uint16_t url_length)
        : m_url_slash_count(url_slash_count), m_url_length(url_length) {}

    uint16_t url_slash_count() const { return m_url_slash_count; }
    uint16_t url_length() const { return m_url_length; }

    template <class Archive>
    void serialize(Archive &archive) {
        archive(m_url_slash_count, m_url_length);
    }
};

class Field {
    uint16_t m_tag_count          = 0;
    uint16_t m_field_len          = 0;
    uint16_t m_field_min_len      = std::numeric_limits<uint16_t>::max();
    uint16_t m_field_max_len      = 0;
    uint32_t m_field_len_sum_sqrs = 0;

   public:
    Field() = default;
    Field(uint16_t tag_count,
          uint16_t field_len,
          uint16_t field_min_len,
          uint16_t field_max_len,
          uint32_t field_len_sum_sqrs)
        : m_tag_count(tag_count),
          m_field_len(field_len),
          m_field_min_len(field_min_len),
          m_field_max_len(field_max_len),
          m_field_len_sum_sqrs(field_len_sum_sqrs) {}

    uint16_t tag_count() const { return m_tag_count; };
    uint16_t field_len() const { return m_field_len; };
    uint16_t field_min_len() const { return m_field_min_len; };
    uint16_t field_max_len() const { return m_field_max_len; };
    uint32_t field_len_sum_sqrs() const { return m_field_len_sum_sqrs; };

    void tag_count(uint16_t tag_count) { m_tag_count = tag_count; };
    void field_len(uint16_t field_len) { m_field_len = field_len; };
    void field_min_len(uint16_t field_min_len) { m_field_min_len = field_min_len; };
    void field_max_len(uint16_t field_max_len) { m_field_max_len = field_max_len; };
    void field_len_sum_sqrs(uint32_t field_len_sum_sqrs) {
        m_field_len_sum_sqrs = field_len_sum_sqrs;
    };

    template <class Archive>
    void serialize(Archive &archive) {
        archive(m_tag_count, m_field_len, m_field_min_len, m_field_max_len, m_field_len_sum_sqrs);
    }
};

class Document {
    std::vector<uint16_t>              m_fields;
    UrlStats                           m_url_stats;
    size_t                             m_num_terms = 0;
    std::vector<uint32_t>              m_terms;
    std::vector<uint32_t>              m_unique_terms;
    std::vector<uint32_t>              m_freqs;
    std::vector<std::vector<uint32_t>> m_field_freqs;
    std::map<uint16_t, Field>          m_field_stats;

   public:
    Document() = default;

    uint16_t url_slash_count() const { return m_url_stats.url_slash_count(); }

    uint16_t url_length() const { return m_url_stats.url_length(); }

    void set_url_stats(const UrlStats &url_stats) { m_url_stats = url_stats; }

    uint32_t length() const { return m_terms.size(); }

    const std::vector<uint32_t> terms() const { return m_terms; }

    void set_fields(const std::vector<uint16_t> &fields) {
        m_fields = fields;
        m_field_freqs.resize(fields.size());
    }

    void set_terms(const std::vector<uint32_t> &terms) {
        std::vector<uint32_t> tmp;
        for (auto &&t : terms) {
            auto it  = std::lower_bound(m_unique_terms.begin(), m_unique_terms.end(), t);
            auto idx = std::distance(m_unique_terms.begin(), it);
            tmp.push_back(idx);
        }
        m_terms = tmp;
    }

    void set_unique_terms(const std::vector<uint32_t> &terms) {
        m_unique_terms = terms;
        m_freqs.resize(m_unique_terms.size());
    }

    uint32_t freq(uint32_t term) const {
        auto it = std::lower_bound(m_unique_terms.begin(), m_unique_terms.end(), term);
        if (it == m_unique_terms.end()) {
            return 0;
        }
        auto idx = std::distance(m_unique_terms.begin(), it);
        return m_freqs.at(idx);
    }
    void set_freq(uint32_t term, uint32_t freq) {
        auto it      = std::lower_bound(m_unique_terms.begin(), m_unique_terms.end(), term);
        auto idx     = std::distance(m_unique_terms.begin(), it);
        m_freqs[idx] = freq;
    }

    uint32_t freq(uint16_t field_id, uint32_t term) const {
        auto it = std::lower_bound(m_unique_terms.begin(), m_unique_terms.end(), term);
        if (it == m_unique_terms.end()) {
            return 0;
        }
        auto idx  = std::distance(m_unique_terms.begin(), it);
        auto f_it = std::find(m_fields.begin(), m_fields.end(), field_id);
        if (f_it == m_fields.end()) {
            return 0;
        }
        auto idx2 = std::distance(m_fields.begin(), f_it);
        if (idx >= m_field_freqs.at(idx2).size())
            return 0;
        return m_field_freqs.at(idx2).at(idx);
    }

    void set_freq(uint16_t field_id, uint32_t term, uint32_t freq) {
        auto it   = std::lower_bound(m_unique_terms.begin(), m_unique_terms.end(), term);
        auto idx  = std::distance(m_unique_terms.begin(), it);
        auto f_it = std::find(m_fields.begin(), m_fields.end(), field_id);
        auto idx2 = std::distance(m_fields.begin(), f_it);
        m_field_freqs[idx2].resize(m_unique_terms.size());
        m_field_freqs[idx2][idx] = freq;
    }

    uint16_t tag_count(uint16_t field_id) const {
        if (m_field_stats.find(field_id) == m_field_stats.end()) {
            return 0;
        }
        return m_field_stats.at(field_id).tag_count();
    }

    void set_tag_count(uint16_t field_id, uint32_t tag_count) {
        m_field_stats[field_id].tag_count(tag_count);
    }

    uint16_t field_len(uint16_t field_id) const {
        if (m_field_stats.find(field_id) == m_field_stats.end()) {
            return 0;
        }
        return m_field_stats.at(field_id).field_len();
    }

    void set_field_len(uint16_t field_id, uint32_t field_len) {
        m_field_stats[field_id].field_len(field_len);
    }

    uint16_t field_min_len(uint16_t field_id) const {
        if (m_field_stats.find(field_id) == m_field_stats.end()) {
            return 0;
        }
        return m_field_stats.at(field_id).field_min_len();
    }

    void set_field_min_len(uint16_t field_id, uint32_t field_min_len) {
        m_field_stats[field_id].field_min_len(field_min_len);
    }

    uint16_t field_max_len(uint16_t field_id) const {
        if (m_field_stats.find(field_id) == m_field_stats.end()) {
            return 0;
        }
        return m_field_stats.at(field_id).field_max_len();
    }

    void set_field_max_len(uint16_t field_id, uint32_t field_max_len) {
        m_field_stats[field_id].field_max_len(field_max_len);
    }

    uint16_t field_len_sum_sqrs(uint16_t field_id) const {
        if (m_field_stats.find(field_id) == m_field_stats.end()) {
            return 0;
        }
        return m_field_stats.at(field_id).field_len_sum_sqrs();
    }

    void set_field_len_sum_sqrs(uint16_t field_id, uint32_t field_len_sum_sqrs) {
        m_field_stats[field_id].field_len_sum_sqrs(field_len_sum_sqrs);
    }

    void compress() {
        m_num_terms = m_terms.size();

        {
            std::vector<uint32_t> buffer(m_num_terms * 2 + 1024);
            size_t                compressedsize = m_unique_terms.size();
            Delta::deltaSIMD(m_unique_terms.data(), m_unique_terms.size());
            codec.encodeArray(
                m_unique_terms.data(), m_unique_terms.size(), buffer.data(), compressedsize);
            buffer.resize(compressedsize);
            m_unique_terms = buffer;
        }
        {
            std::vector<uint32_t> buffer(m_num_terms);
            size_t                compressedsize = m_terms.size();
            codec.encodeArray(m_terms.data(), m_terms.size(), buffer.data(), compressedsize);
            buffer.resize(compressedsize);
            m_terms = buffer;
        }
        {
            std::vector<uint32_t> buffer(m_num_terms);
            size_t                compressedsize = m_unique_terms.size();
            codec.encodeArray(m_freqs.data(), m_freqs.size(), buffer.data(), compressedsize);
            buffer.resize(compressedsize);
            m_freqs = buffer;
        }
        {
            for (auto &&ff : m_field_freqs) {
                std::vector<uint32_t> buffer(m_num_terms);
                size_t                compressedsize = ff.size();
                codec.encodeArray(ff.data(), ff.size(), buffer.data(), compressedsize);
                buffer.resize(compressedsize);
                ff = buffer;
            }
        }
    }

    void decompress() {
        {
            std::vector<uint32_t> terms(m_num_terms);
            size_t                recoveredsize = terms.size();
            codec.decodeArray(
                m_unique_terms.data(), m_unique_terms.size(), terms.data(), recoveredsize);
            terms.resize(recoveredsize);
            Delta::inverseDeltaSIMD(terms.data(), terms.size());
            m_unique_terms = terms;
        }
        {
            std::vector<uint32_t> terms(m_num_terms);
            size_t                recoveredsize = terms.size();
            codec.decodeArray(m_terms.data(), m_terms.size(), terms.data(), recoveredsize);
            terms.resize(recoveredsize);
            std::vector<uint32_t> tmp;
            for (auto &&i : terms) {
                tmp.push_back(m_unique_terms[i]);
            }
            m_terms = tmp;
        }
        {
            std::vector<uint32_t> freqs(m_num_terms);
            size_t                recoveredsize = freqs.size();
            codec.decodeArray(m_freqs.data(), m_freqs.size(), freqs.data(), recoveredsize);
            freqs.resize(recoveredsize);
            m_freqs = freqs;
        }
        {
            for (auto &&ff : m_field_freqs) {
                std::vector<uint32_t> freqs(m_num_terms);
                size_t                recoveredsize = freqs.size();
                codec.decodeArray(ff.data(), ff.size(), freqs.data(), recoveredsize);
                freqs.resize(recoveredsize);
                ff = freqs;
            }
        }
    }

    template <class Archive>
    void serialize(Archive &archive) {
        archive(m_fields,
                m_url_stats,
                m_num_terms,
                m_terms,
                m_unique_terms,
                m_freqs,
                m_field_freqs,
                m_field_stats);
    }
};

using ForwardIndex = std::vector<Document>;
