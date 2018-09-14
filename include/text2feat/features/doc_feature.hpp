#pragma once

#include <cstdint>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>

#include "indri/Index.hpp"

#include "query_train_file.hpp"
#include "lexicon.hpp"

namespace {
    static const std::string              _field_title = "title";
    static const std::vector<std::string> _fields = {"body", _field_title, "heading", "inlink", "a"};
} // namespace


/**
 * Score segments of a document with a given query.
 */
class doc_feature {
   public:
    Lexicon     &lexicon;

    uint64_t     _coll_len    = 0;
    uint64_t     _num_docs    = 0;
    double       _avg_doc_len = 0.0;

    double _score_doc     = 0.0;
    double _score_body    = 0.0;
    double _score_title   = 0.0;
    double _score_heading = 0.0;
    double _score_inlink  = 0.0;
    double _score_a       = 0.0;
    // FIXME: implement url score
    double _score_url = 0.0;

    doc_feature(Lexicon &lex) : lexicon(lex) {
        _coll_len    = lexicon.term_count();
        _num_docs    = lexicon.document_count();
        _avg_doc_len = (double)_coll_len / _num_docs;
    }

    void _accumulate_score(std::string key, double val) {
        if (0 == key.compare(_fields[0])) {
            _score_body += val;
        } else if (0 == key.compare(_fields[1])) {
            _score_title += val;
        } else if (0 == key.compare(_fields[2])) {
            _score_heading += val;
        } else if (0 == key.compare(_fields[3])) {
            _score_inlink += val;
        } else if (0 == key.compare(_fields[4])) {
            _score_a += val;
        } else {
            std::ostringstream oss;
            oss << "unkown field " << key;
            throw std::invalid_argument(oss.str());
        }
    }
};
