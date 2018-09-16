#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "CLI/CLI.hpp"
#include "cereal/archives/binary.hpp"

#include "text2feat/doc_entry.hpp"
#include "text2feat/field_id.hpp"

#include "text2feat/features/features.hpp"
#include "text2feat/forward_index.hpp"

#include "text2feat/lexicon.hpp"

#include "text2feat/query_train_file.hpp"
#include "text2feat/trec_run_file.hpp"

#include "text2feat/query_environment_adapter.hpp"

int main(int argc, char **argv) {

    std::string query_file;
    std::string trec_file;
    std::string repo_path;
    std::string forward_index_file;
    std::string lexicon_file;
    std::string output_file;

    CLI::App app{"Document features generation."};
    app.add_option("query_file", query_file, "Query file")->required();
    app.add_option("trec_file", trec_file, "TREC run file")->required();
    app.add_option("repo_path", repo_path, "Indri repo path")->required();
    app.add_option("forward_index_file", forward_index_file, "Forward index file")->required();
    app.add_option("lexicon_file", lexicon_file, "Lexicon file")->required();
    app.add_option("output_file", output_file, "Output file")->required();
    CLI11_PARSE(app, argc, argv);

    std::ofstream outfile(output_file, std::ofstream::app);
    outfile << std::fixed << std::setprecision(5);

    query_environment         indri_env;
    query_environment_adapter qry_env(&indri_env);
    qry_env.add_index(repo_path);

    indri::collection::Repository repo;
    repo.openRead(repo_path);
    auto index = (*repo.indexes())[0];

    using clock = std::chrono::high_resolution_clock;
    auto start  = clock::now();

    // load fwd_idx
    std::ifstream              ifs_fwd(forward_index_file);
    cereal::BinaryInputArchive iarchive_fwd(ifs_fwd);
    ForwardIndex               fwd_idx;
    iarchive_fwd(fwd_idx);

    auto stop      = clock::now();
    auto load_time = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cerr << "Loaded " << forward_index_file << " in " << load_time.count() << " ms"
              << std::endl;

    start = clock::now();
    // load lexicon
    std::ifstream              lexicon_f(lexicon_file);
    cereal::BinaryInputArchive iarchive_lex(lexicon_f);
    Lexicon                    lexicon;
    iarchive_lex(lexicon);

    stop      = clock::now();
    load_time = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cerr << "Loaded " << lexicon_file << " in " << load_time.count() << " ms" << std::endl;

    // load query file
    std::ifstream ifs(query_file);
    if (!ifs.is_open()) {
        std::cerr << "Could not open file: " << query_file << std::endl;
        exit(EXIT_FAILURE);
    }
    query_train_file qtfile(ifs, lexicon);
    ifs.close();
    ifs.clear();

    // load trec run file
    ifs.open(trec_file);
    trec_run_file trec_run(ifs);
    trec_run.parse();
    ifs.close();
    ifs.clear();

    FieldIdMap                     field_id_map;
    const std::vector<std::string> idx_fields = {
        "title", "heading", "mainbody", "inlink", "applet", "object", "embed"};
    for (const std::string &field_str : idx_fields) {
        int field_id = index->field(field_str);
        field_id_map.insert(std::make_pair(field_str, field_id));
    }

    document_features           features;
    doc_bm25_atire_feature      f_bm25_atire(lexicon);
    doc_bm25_trec3_feature      f_bm25_trec3(lexicon);
    doc_bm25_trec3_kmax_feature f_bm25_trec3_kmax(lexicon);
    doc_proximity_feature       prox_feature(lexicon);
    doc_lm_dir_2500_feature     f_lmds_2500(lexicon);
    doc_lm_dir_1500_feature     f_lmds_1500(lexicon);
    doc_lm_dir_1000_feature     f_lmds_1000(lexicon);
    doc_tfidf_feature           tfidf_feature(lexicon);
    doc_prob_feature            prob_feature(lexicon);
    doc_be_feature              be_feature(lexicon);
    doc_dph_feature             dph_feature(lexicon);
    doc_dfr_feature             dfr_feature(lexicon);
    doc_stream_feature          f_stream;
    doc_tpscore_feature         f_tpscore(lexicon);

    auto queries = qtfile.get_queries();
    for (auto &qry : queries) {
        std::vector<double>      stage0_scores = trec_run.get_scores(qry.id);
        std::vector<int>         docno_labels  = trec_run.get_labels(qry.id);
        std::vector<std::string> docnos        = trec_run.get_result(qry.id);
        std::vector<docid_t>     docids = qry_env.document_ids_from_metadata("docno", docnos);

        auto start = clock::now();

        for (size_t i = 0; i < docids.size(); ++i) {
            auto const docid = docids[i];
            auto const docno = docnos[i];
            auto const label = docno_labels[i];

            auto doc_idx = fwd_idx[docid];
            doc_idx.decompress();

            doc_entry doc_entry;

            auto terms = doc_idx.terms();
            std::unordered_map<uint32_t, std::vector<uint32_t>> positions;
            for (size_t i = 0; i < terms.size(); i++) {
                positions[terms[i]].push_back(i);
            }


            // set url_slash_count as feature for training
            doc_entry.url_slash_count = doc_idx.url_slash_count();
            doc_entry.url_length      = doc_idx.url_length();

            // set original run score as a feature for training
            doc_entry.stage0_score = stage0_scores[i];

            f_bm25_atire.compute(qry, doc_entry, doc_idx, field_id_map);
            f_bm25_trec3.compute(qry, doc_entry, doc_idx, field_id_map);
            f_bm25_trec3_kmax.compute(qry, doc_entry, doc_idx, field_id_map);
            f_lmds_2500.compute(qry, doc_entry, doc_idx, field_id_map);
            f_lmds_1500.compute(qry, doc_entry, doc_idx, field_id_map);
            f_lmds_1000.compute(qry, doc_entry, doc_idx, field_id_map);
            tfidf_feature.compute(qry, doc_entry, doc_idx, field_id_map);
            prob_feature.compute(qry, doc_entry, doc_idx, field_id_map);
            be_feature.compute(qry, doc_entry, doc_idx, field_id_map);
            dph_feature.compute(qry, doc_entry, doc_idx, field_id_map);
            dfr_feature.compute(qry, doc_entry, doc_idx, field_id_map);
            f_stream.compute(qry, doc_entry, doc_idx, field_id_map);
            features.compute(qry, doc_entry, doc_idx, field_id_map);
            prox_feature.compute(doc_entry, qry, doc_idx, positions);
            f_tpscore.compute(qry, doc_entry, doc_idx, field_id_map);

            outfile << label << "," << qry.id << "," << docno << doc_entry << std::endl;
        }
        auto stop      = clock::now();
        auto load_time = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        std::cerr << "qid: " << qry.id << ", " << docids.size() << " docs in " << load_time.count()
                  << " ms" << std::endl;
    }
    return 0;
}
