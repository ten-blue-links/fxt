#pragma once

#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

class trec_run_file {
    const int          k_init = -1;
    const unsigned int fields = 6;
    // docno vector mapped by topic id
    std::map<int, std::vector<std::string>> results;
    // document labels, from abuse of Q0 field in TREC run file.
    std::map<int, std::vector<int>> labels;
    // document scores
    std::map<int, std::vector<double>> scores;
    std::ifstream &                    ifs;

   public:
    trec_run_file(std::ifstream &infile) : ifs(infile) {}

    /**
     * Parse TREC run file format.
     */
    void parse() {
        std::vector<std::string> parts;
        std::string              line;
        std::vector<std::string> list;
        std::vector<int>         label_list;
        std::vector<double>      score_list;
        auto                     last_id = k_init, id = 0, rel_label = 0;
        double                   score = 0.0;

        while (std::getline(ifs, line, '\n')) {
            std::istringstream iss(line);
            std::string        str;
            while (iss >> str) {
                parts.push_back(str);
            }
            if (fields != parts.size()) {
                std::ostringstream oss;
                oss << "Required fields is " << fields << ", but got " << parts.size();
                throw std::logic_error(oss.str());
            }

            id = std::stol(parts[0]);
            if (0 == id) {
                std::ostringstream oss;
                oss << "TREC run entry QID is 0";
                throw std::runtime_error(oss.str());
            }

            // Only try to read class label if Q is missing
            if (parts[1].c_str()[0] != 'Q') {
                rel_label = std::stol(parts[1]); // Relevance label is in Q0 field
            }

            score = std::stod(parts[4]);

            if (k_init == last_id) {
                last_id = id;
            }

            if (last_id != id) {
                results.emplace(last_id, list);
                labels.emplace(last_id, label_list);
                scores.emplace(last_id, score_list);
                list.clear();
                label_list.clear();
                score_list.clear();
                last_id = id;
            }

            list.push_back(parts[2]);
            label_list.push_back(rel_label);
            score_list.push_back(score);
            parts.clear();
        }
        results.emplace(last_id, list);
        labels.emplace(last_id, label_list);
        scores.emplace(last_id, score_list);
    }

    std::vector<std::string> get_result(int id) {
        auto it = results.find(id);

        if (results.end() == it) {
            return {};
        }

        return results[id];
    }

    std::vector<int> get_labels(int id) {
        auto it = labels.find(id);

        if (labels.end() == it) {
            return {};
        }

        return labels[id];
    }

    std::vector<double> get_scores(int id) {
        auto it = scores.find(id);

        if (scores.end() == it) {
            return {};
        }

        return scores[id];
    }
};
