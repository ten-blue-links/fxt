EXECUTE_PROCESS(COMMAND git submodule update --init
                WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/..
                OUTPUT_QUIET
        )
# Add FastPFor
add_subdirectory(FastPFor EXCLUDE_FROM_ALL)

# Add CLI11
add_subdirectory(CLI11 EXCLUDE_FROM_ALL)

# Add cereal
add_subdirectory(cereal EXCLUDE_FROM_ALL)
