#!/bin/bash

set -e

SPATH="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
BASE=$SPATH/..

awk 'BEGIN {
    print "/* The following flags for enabling features is automatically generated. */"
    print "struct doc_entry_flag query_doc_flags; struct statdoc_entry_flag static_doc_flags;"
}
{
    if (ARGIND == 1) {
        group = "Query-document features"
        type = "query_doc_flags"
    } else {
        group = "Static document features"
        type = "static_doc_flags"
    }
}
$1 ~ /bool/ {
    printf "app.add_flag(\"--%s\", %s.%s, \"Enable feature %s\")->group(\"%s\");\n", $2, type, $2, $2, group
}
END {
    print ""
}' $BASE/include/text2feat/doc_entry_flag.hpp \
   $BASE/include/text2feat/statdoc_entry_flag.hpp
