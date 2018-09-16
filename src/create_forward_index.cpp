#include "indri/CompressedCollection.hpp"
#include "indri/QueryEnvironment.hpp"
#include "indri/Repository.hpp"

#include "CLI/CLI.hpp"
#include "cereal/archives/binary.hpp"

#include "text2feat/forward_index.hpp"

size_t url_slash_count(const std::string &url) {
    size_t            count       = 0;
    const std::string proto       = "://";
    const std::string param_delim = "?";
    size_t            pos         = url.find(proto);
    size_t            pos_q       = url.find(param_delim);

    if (pos_q < pos || std::string::npos == pos) {
        pos = 0;
    } else {
        pos += proto.size();
    }

    while (std::string::npos != (pos = url.find("/", pos + 1, 1))) {
        ++count;
    }

    return count;
}

static const std::vector<std::string> _fields = {"body", "title", "heading", "inlink", "a"};

int main(int argc, char const *argv[]) {
    std::string repo_path;
    std::string forward_index_file;

    CLI::App app{"Inverted index generator."};
    app.add_option("repo_path", repo_path, "Indri repo path")->required();
    app.add_option("forward_index_file", forward_index_file, "Forward index file")->required();
    CLI11_PARSE(app, argc, argv);

    std::ofstream               os(forward_index_file, std::ios::binary);
    cereal::BinaryOutputArchive archive(os);

    indri::collection::Repository repo;
    repo.openRead(repo_path);
    indri::collection::Repository::index_state state = repo.indexes();
    const auto &                               index = (*state)[0];

    indri::api::QueryEnvironment indri_env;
    indri_env.addIndex(repo_path);

    ForwardIndex fwd_idx;
    fwd_idx.push_back({});
    uint64_t                            docid = index->documentBase();
    indri::index::TermListFileIterator *iter  = index->termListFileIterator();
    iter->startIteration();

    while (!iter->finished()) {
        indri::index::TermList *list       = iter->currentEntry();
        auto &                  doc_terms  = list->terms();
        Document                document;
        auto url = indri_env.documentMetadata(std::vector<lemur::api::DOCID_T>{docid}, "url");

        document.set_url_stats({url_slash_count(url.at(0)), url.at(0).size()});

        std::set<uint32_t> unique_terms_set(doc_terms.begin(), doc_terms.end());
        std::vector<uint32_t> unique_terms(unique_terms_set.begin(), unique_terms_set.end());
        document.set_unique_terms(unique_terms);

        std::vector<uint32_t> terms(doc_terms.begin(), doc_terms.end());
        document.set_terms(terms);

        std::unordered_map<uint32_t, uint32_t> freqs;
        for (size_t i = 0; i < terms.size(); i++) {
            freqs[terms[i]] += 1;
        }

        for (auto &f : freqs) {
            document.set_freq(f.first, f.second);
        }

        auto fields = list->fields();
        for (auto &f : fields) {
            document.set_tag_count(f.id, document.tag_count(f.id) + 1);
        }

        std::vector<uint16_t> f;
        for (const std::string &field_str : _fields) {
            int field_id = index->field(field_str);
            f.push_back(field_id);
        }
        document.set_fields(f);

        for (const std::string &field_str : _fields) {
            int field_id = index->field(field_str);
            if (field_id < 1) {
                // field is not indexed
                continue;
            }
            for (auto &f : fields) {
                if (f.id != static_cast<size_t>(field_id)) {
                    continue;
                }
                auto d_len = f.end - f.begin;
                document.set_field_len(f.id, document.field_len(f.id) + d_len);
                auto field_len_sqr = d_len * d_len;
                document.set_field_len_sum_sqrs(f.id,
                                                document.field_len_sum_sqrs(f.id) + field_len_sqr);

                if (document.field_max_len(f.id) < document.field_len(f.id)) {
                    document.set_field_max_len(f.id, document.field_len(f.id));
                }

                if (document.field_min_len(f.id) < document.field_len(f.id)) {
                    document.set_field_min_len(f.id, document.field_len(f.id));
                }

                for (size_t i = f.begin; i < f.end; ++i) {
                    auto freq = document.freq(f.id, doc_terms[i]) + 1;
                    document.set_freq(f.id, doc_terms[i], freq);
                }
            }
        }
        document.compress();
        fwd_idx.push_back(document);
        iter->nextEntry();
        if (docid % 10000 == 0) {
            std::cout << "Processed " << docid << " documents." << std::endl;
        }
        ++docid;
    }
    delete iter;
    archive(fwd_idx);
    return 0;
}
