#!/usr/bin/awk -f

BEGIN {
    last = ""
}

{
    qid = $1
    if (qid != last) {
        last = qid
        rank = 1
    }

    print $1, $2, $3, rank++, $5, $6
}
