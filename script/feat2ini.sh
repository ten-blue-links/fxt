#!/bin/bash

set -e

SPATH="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
BASE=$SPATH/..

awk '$1 ~ /bool/ {
    printf "; Enable/disable feature %s\n", $2
    printf "%s = 1\n", $2
    print ""
}
END {
}' $BASE/include/text2feat/doc_entry_flag.hpp \
   $BASE/include/text2feat/statdoc_entry_flag.hpp
