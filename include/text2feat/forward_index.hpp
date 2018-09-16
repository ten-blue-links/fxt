#pragma once

#include "cereal/types/map.hpp"
#include "cereal/types/utility.hpp"
#include "cereal/types/vector.hpp"

#include "FastPFor/headers/codecfactory.h"
#include "FastPFor/headers/deltautil.h"

using namespace FastPForLib;
IntegerCODEC &codec = *CODECFactory::getFromName("varintgb");

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

class TermStats {
    std::vector<uint32_t>        m_positions;
    std::map<uint16_t, uint32_t> m_field_freq;

   public:
    TermStats() = default;

    uint32_t freq() const { return m_positions.size(); }

    uint32_t freq(uint16_t field) const {
        auto field_freq_it = m_field_freq.find(field);
        if (field_freq_it == m_field_freq.end()) {
            return 0;
        }
        return field_freq_it->second;
    }
    void set_freq(uint16_t field, uint32_t freq) { m_field_freq[field] = freq; }

    const std::vector<uint32_t> &positions() const { return m_positions; }
    void positions(const std::vector<uint32_t> &positions) { m_positions = positions; }

    template <class Archive>
    void serialize(Archive &archive) {
        archive(m_positions, m_field_freq);
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
    UrlStats                      m_url_stats;
    std::vector<uint32_t>         m_terms;
    size_t                        m_num_terms = 0;
    std::vector<uint32_t>         m_unique_terms;
    size_t                        m_num_unique = 0;

    std::vector<TermStats>        m_term_freqs;
    std::map<uint16_t, Field>     m_field_stats;

   public:
    Document() = default;

    uint16_t url_slash_count() const { return m_url_stats.url_slash_count(); }

    uint16_t url_length() const { return m_url_stats.url_length(); }

    void set_url_stats(const UrlStats &url_stats) { m_url_stats = url_stats; }

    uint32_t length() const { return m_terms.size(); }

    const std::vector<uint32_t> &terms() const { return m_terms; }

    void set_terms(const std::vector<uint32_t> &terms) { m_terms = terms; }

    void set_unique_terms(const std::vector<uint32_t> &terms) {
        m_unique_terms = terms;
        m_term_freqs.resize(terms.size());
    }

    uint32_t freq(uint32_t term) const {
        auto it = std::find(m_unique_terms.begin(), m_unique_terms.end(), term);
        if (it == m_unique_terms.end()) {
            return 0;
        }
        auto idx = std::distance(m_unique_terms.begin(), it);
        return m_term_freqs.at(idx).freq();
    }

    std::vector<uint32_t> positions(uint32_t term) const {
        auto it = std::find(m_unique_terms.begin(), m_unique_terms.end(), term);
        if (it == m_unique_terms.end()) {
            return {};
        }
        auto idx = std::distance(m_unique_terms.begin(), it);
        return m_term_freqs.at(idx).positions();
    }
    void set_positions(uint32_t term, std::vector<uint32_t> &positions) {
        auto it = std::find(m_unique_terms.begin(), m_unique_terms.end(), term);
        auto idx = std::distance(m_unique_terms.begin(), it);
        m_term_freqs[idx].positions(positions);
    }

    uint32_t freq(uint16_t field_id, uint32_t term) const {
        auto it = std::find(m_unique_terms.begin(), m_unique_terms.end(), term);
        if (it == m_unique_terms.end()) {
            return 0;
        }
        auto idx = std::distance(m_unique_terms.begin(), it);
        return m_term_freqs.at(idx).freq(field_id);
    }

    void set_freq(uint16_t field_id, uint32_t term, uint32_t freq) {
        auto it = std::find(m_unique_terms.begin(), m_unique_terms.end(), term);
        auto idx = std::distance(m_unique_terms.begin(), it);
        m_term_freqs[idx].set_freq(field_id, freq);
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
        std::vector<uint32_t> buffer(m_num_terms * 2);

        size_t compressedsize = m_terms.size();
        codec.encodeArray(m_terms.data(), m_terms.size(), buffer.data(), compressedsize);
        buffer.resize(compressedsize);
        buffer.shrink_to_fit();
        m_terms = buffer;
    }

    void decompress() {
        std::vector<uint32_t> terms(m_num_terms);
        size_t recoveredsize = terms.size();
        codec.decodeArray(m_terms.data(), m_terms.size(), terms.data(), recoveredsize);
        terms.resize(recoveredsize);
        m_terms =  terms;
    }


    template <class Archive>
    void serialize(Archive &archive) {
        archive(m_url_stats, m_terms, m_num_terms, m_unique_terms, m_num_unique, m_term_freqs, m_field_stats);
    }
};

using ForwardIndex = std::vector<Document>;