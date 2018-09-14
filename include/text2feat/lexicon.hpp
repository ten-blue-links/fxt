#pragma once

#include "cereal/types/map.hpp"
#include "cereal/types/string.hpp"
#include "cereal/types/vector.hpp"
#include "cereal/types/map.hpp"

#include <limits>
#include <map>

struct Counts {
    uint64_t document_count = 0;
    uint64_t term_count     = 0;

    Counts() = default;
    Counts(uint64_t dc, uint64_t tc) : document_count(dc), term_count(tc) {}

    template <class Archive>
    void serialize(Archive &archive) {
        archive(document_count, term_count);
    }
};
using FieldCounts = std::map<uint64_t, Counts>;

class Term {
   private:
    Counts      counts;
    FieldCounts field_counts;

   public:
    Term() = default;

    Term(const Counts &c, const FieldCounts &fc) : counts(c), field_counts(fc){};

    inline uint64_t document_count() const { return counts.document_count; }

    inline uint64_t term_count() const { return counts.term_count; }

    inline uint64_t field_document_count(uint64_t field) const {
        auto it = field_counts.find(field);
        if (it == field_counts.end()) {
            return 0;
        }
        return it->second.document_count;
    }

    inline uint64_t field_term_count(uint64_t field) const {
        auto it = field_counts.find(field);
        if (it == field_counts.end()) {
            return 0;
        }
        return it->second.term_count;
    }

    template <class Archive>
    void serialize(Archive &archive) {
        archive(counts, field_counts);
    }
};

class Lexicon {
   public:
    inline uint64_t document_count() const { return counts.document_count; }

    inline uint64_t term_count() const { return counts.term_count; }

    inline const Term &operator[](size_t pos) const { return terms[pos]; }
    inline Term &      operator[](size_t pos) { return terms[pos]; }

    inline size_t term(const std::string& t) {
        auto it = term_id.find(t);
        if(it != term_id.end()){
            return it->second;
        }
        return oov_term();
    }

    inline size_t oov_term() { return std::numeric_limits<std::size_t>::max(); }

    inline bool is_oov(size_t tid) { return tid == oov_term(); }

    void push_back(const std::string &t, const Counts &c, const FieldCounts &fc) {
        auto id = terms.size();
        term_id.insert(std::make_pair(t, id));
        Term term(c, fc);
        terms.push_back(term);
    }

    void push_back(Term &&t) {
        terms.push_back(t);
    }

    Lexicon() = default;
    Lexicon(Counts c) : counts(c) {}

    template <class Archive>
    void serialize(Archive &archive) {
        archive(counts, terms, term_id);
    }

   private:
    Counts            counts;
    std::vector<Term> terms;
    std::map<std::string, size_t> term_id;
};
