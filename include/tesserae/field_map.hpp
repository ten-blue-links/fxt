/*
 * Copyright 2018 The Tesserae authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#pragma once

#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "field_id.hpp"

#include "indri/Index.hpp"

/*
 * Reference field names an their associated Indri field id.
 */
class FieldMap {
    FieldIdMap map;

   public:
    FieldMap() = default;

    std::vector<std::string> keys() {
        std::vector<std::string> ret;
        for (const auto &fentry : map) {
            ret.push_back(fentry.first);
        }
        return ret;
    }

    std::vector<int> values() {
        std::vector<int> ret;
        for (const auto &fentry : map) {
            ret.push_back(fentry.second);
        }
        return ret;
    }

    FieldIdMap &get() { return map; }

    void insert(indri::index::Index &idx, const std::vector<std::string> &field_names) {
        for (const auto &key : field_names) {
            if (0 == idx.field(key)) {
                std::ostringstream oss;
                oss << "the field '" << key << "' is not indexed";
                throw std::invalid_argument(oss.str());
            }
            map[key] = idx.field(key);
        }
    }
};
