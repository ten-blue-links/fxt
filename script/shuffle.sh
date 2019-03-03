#!/bin/bash

set -e

SPATH="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
TMPD=querytmp

mkdir -p $TMPD

# dump query id's and shuflle
awk -F, '{ print $2 }' docfeat.csv | sort -u | shuf | shuf > qid.txt
# split data by query id
awk -F, -v path=$TMPD '{
    print $0 > path "/" $2
}' docfeat.csv
# split data into 5 folds
split -d -l 30 qid.txt
for i in {0..4}; do
    n=$((i + 1))
    printf -v x "x%02d" $i
    cat $x | sed "s/^/$TMPD\//" | xargs cat > fold${n}.csv
done
rm -f x??
rm -rf $TMPD
