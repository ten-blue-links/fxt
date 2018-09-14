#!/usr/bin/awk -f

# Label a TREC run file with relevance judgements from a qrel file. The labels
# will be placed in the iteration column (usually the column with 'Q0')

BEGIN {
    if (ARGC < 3) {
        print "usage: label.awk <qrel file> <run file>" > "/dev/stderr"
        exit 1
    }
}

NR == FNR {
    key = $1 $3
    rels[key] = $4
    next
}

{
    key = $1 $3
    label = 0
    if (rels[key])
        label = rels[key]
    print $1, label, $3, $4, $5, $6
}
