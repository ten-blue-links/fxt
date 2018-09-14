#include "CLI/CLI.hpp"
#include "cereal/archives/binary.hpp"

#include "indri/QueryEnvironment.hpp"
#include "indri/Repository.hpp"

#include "text2feat/inverted_index.hpp"

int main(int argc, char const *argv[]) {
    std::string repo_path;
    std::string inverted_index_file;

    CLI::App app{"Inverted index generator."};
    app.add_option("repo_path", repo_path, "Indri repo path")->required();
    app.add_option("inverted_index_file", inverted_index_file, "Inverted index file")->required();
    CLI11_PARSE(app, argc, argv);

    std::ofstream               os(inverted_index_file, std::ios::binary);
    cereal::BinaryOutputArchive archive(os);

    indri::collection::Repository repo;
    repo.openRead(repo_path);
    indri::collection::Repository::index_state state = repo.indexes();
    const auto &                               index = (*state)[0];

    InvertedIndex inv_idx;

    indri::index::DocListFileIterator *iter = index->docListFileIterator();
    iter->startIteration();
    while (!iter->finished()) {
        indri::index::DocListFileIterator::DocListData *entry = iter->currentEntry();
        entry->iterator->startIteration();

        indri::index::TermData *termData = entry->termData;

        PostingList pl(termData->term, termData->corpus.totalCount);
        std::vector<uint32_t> docs;
        std::vector<uint32_t> freqs;

        while (!entry->iterator->finished()) {
            indri::index::DocListIterator::DocumentData *doc = entry->iterator->currentEntry();
            docs.push_back(doc->document);
            freqs.push_back(doc->positions.size());
            entry->iterator->nextEntry();
        }
        pl.add_list(docs, freqs);
        inv_idx.push_back(pl);
        iter->nextEntry();
        if(inv_idx.size() % 10000 == 0) {
            std::cout << "Processed " << inv_idx.size() << " terms." << std::endl;
        }
    }
    std::cout << "Processed " << inv_idx.size() << " terms." << std::endl;
    delete iter;
    archive(inv_idx);
    return 0;
}