#pragma once

#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "indri/QueryEnvironment.hpp"

#include "lexicon.hpp"
struct query_train {
    // query id
    int id;
    // stemmed query terms
    std::vector<std::string> stems;
    // terms by id
    std::vector<uint64_t> tids;
    // query term order
    std::vector<int> pos;
    // query term frequency
    std::unordered_map<uint64_t, int> q_ft;
};

class query_train_file {
    const unsigned int       fields = 2;
    std::vector<query_train> rows;
    std::ifstream &          ifs;
    Lexicon &                lexicon;

    void parse() {
        std::vector<std::string> parts;
        std::string              line;
        while (std::getline(ifs, line, '\n')) {
            std::istringstream iss(line);
            std::string        str;
            while (std::getline(iss, str, ';')) {
                parts.push_back(str);
            }
            if (fields != parts.size()) {
                std::ostringstream oss;
                oss << "Required fields is " << fields << ", but got " << parts.size();
                throw std::logic_error(oss.str());
            }

            query_train row;
            row.id = std::stol(parts[0]);

            // query terms
            int count = 0;
            iss.clear();
            iss.str(parts[1]);
            while (iss >> str) {
                std::string stem = str;
                uint64_t    term_id =
                    lexicon.term(stem); // `Index::term` takes stemmed version of a term
                row.stems.push_back(stem);
                row.tids.push_back(term_id);
                row.pos.push_back(count++);
                row.q_ft[term_id] += 1;
            }

            rows.push_back(row);
            parts.clear();
        }
    }

   public:
    query_train_file(std::ifstream &infile, Lexicon &lex)
        : ifs(infile), lexicon(lex) {
        parse();
    }

    std::vector<query_train> &get_queries() { return rows; }
};
