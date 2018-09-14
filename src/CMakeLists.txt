# generate_term_features
add_executable(generate_term_features generate_term_features.cpp)
target_link_libraries(generate_term_features
    FastPFor
    CLI11
    cereal
)
