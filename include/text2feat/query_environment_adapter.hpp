#pragma once

#include <cstdint>

#include "indri/QueryEnvironment.hpp"

using docid_t           = lemur::api::DOCID_T;
using query_environment = indri::api::QueryEnvironment;

class query_environment_adapter {
    query_environment *env = nullptr;

   public:
    query_environment_adapter(query_environment *query_env) : env(query_env) {}

    virtual void add_index(const std::string &path) { env->addIndex(path); }

    virtual std::vector<docid_t> document_ids_from_metadata(const std::string &             name,
                                                            const std::vector<std::string> &value) {
        return env->documentIDsFromMetadata(name, value);
    }

};
