# forward_index
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DP_NEEDS_GNU_CXX_NAMESPACE=1")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DP_NEEDS_GNU_CXX_NAMESPACE=1")

add_executable(create_forward_index create_forward_index.cpp)
target_link_libraries(create_forward_index
    FastPFor
    indri
    pthread
    CLI11
    cereal
)

# create_doc_lens
add_executable(create_doc_lens create_doc_lens.cpp)
target_link_libraries(create_doc_lens
    FastPFor
    indri
    pthread
    CLI11
    cereal
)

# lexicon
add_executable(create_lexicon create_lexicon.cpp)
target_link_libraries(create_lexicon
    FastPFor
    indri
    pthread
    CLI11
    cereal
)

# inverted_index
add_executable(create_inverted_index create_inverted_index.cpp)
target_link_libraries(create_inverted_index
    FastPFor
    indri
    pthread
    CLI11
    cereal
)

# create_bigram_inverted_index
add_executable(create_bigram_inverted_index create_bigram_inverted_index.cpp)
target_link_libraries(create_bigram_inverted_index
    FastPFor
    indri
    pthread
    CLI11
    cereal
)

# generate_term_features
add_executable(generate_term_features generate_term_features.cpp)
target_link_libraries(generate_term_features
    FastPFor
    CLI11
    cereal
)

# pre-retrieval csv
add_executable(preret_csv preret_csv.cpp
    fgen_term_qry.cpp query_features.cpp)
target_link_libraries(preret_csv
    FastPFor
    indri
    pthread
    CLI11
    cereal
)

add_executable(generate_static_doc_features generate_static_doc_features.cpp)
target_link_libraries(generate_static_doc_features
    indri
    pthread
    CLI11
    cereal
)

add_executable(inlink_count inlink.cpp)

add_executable(outlink_count outlink.cpp)

add_executable(kstem kstem.cpp)
target_link_libraries(kstem
    indri
    pthread
)

add_executable(extract_features extract_features.cpp)
target_link_libraries(extract_features
    FastPFor
    indri
    pthread
    CLI11
    cereal
)
