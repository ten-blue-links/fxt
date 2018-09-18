#!/bin/bash

set -e

SPATH="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
DEPTH=20000

awk -F, '{
    print $1, $2, $3
}' docfeat.csv | sort -k2n -k1nr | awk -v max_depth=$DEPTH '{
    qid = $2
    if (last != qid) {
        last = qid
        rank = 1
        score = max_depth
    }
    print $2, "Q0", $3, rank++, score--, "oracle-bm25"
}' > oracle.run
