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

set(CMAKE_CXX_STANDARD 14)
remove_definitions(-Wall -Wextra)
add_definitions(-fPIC -Wno-deprecated -Wno-write-strings -Wno-deprecated-declarations)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DP_NEEDS_GNU_CXX_NAMESPACE=1")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DP_NEEDS_GNU_CXX_NAMESPACE=1")

# zlib
include_directories(indri/contrib/zlib/include)
file(GLOB SOURCES "indri/contrib/zlib/src/*.c*")
add_library(zlib SHARED ${SOURCES})
target_include_directories(zlib PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/external/indri/contrib/zlib/include>)

# xpdf
include_directories(indri/contrib/xpdf/include)
file(GLOB SOURCES "indri/contrib/xpdf/src/*.c*")
add_library(xpdf SHARED ${SOURCES})
target_include_directories(xpdf PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/external/indri/contrib/xpdf/include>)

# antrlr
include_directories(indri/contrib/antlr
                    indri/contrib/antlr/include)
file(GLOB SOURCES "indri/contrib/antlr/src/*.c*")
add_library(antlr SHARED ${SOURCES})
target_include_directories(antlr PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/external/indri/contrib/antlr/include>)

# lemur
include_directories(indri/contrib/lemur/include/lemur indri/contrib/lemur/include)
file(GLOB SOURCES "indri/contrib/lemur/src/*.c*")
add_library(lemur STATIC ${SOURCES})
target_include_directories(lemur PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/external/indri/contrib/lemur/include>)

# indri
file(GLOB SOURCES "indri/src/*.c*")
include_directories(indri/include)
add_library(indri SHARED ${SOURCES})
target_link_libraries(indri lemur antlr xpdf zlib)
target_include_directories(indri PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/external/indri/include>
)
