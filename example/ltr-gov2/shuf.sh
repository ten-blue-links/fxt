#!/bin/bash

set -e

SPATH="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
TMPD=querytmp

mkdir -p $TMPD

awk -F, '{ print $2 }' docfeat.csv | sort -u | shuf | shuf > qid.txt
awk -F, -v path=$TMPD '{
    print $0 > path "/" $2
}' docfeat.csv
split -d -l 30 qid.txt
for i in {0..4}; do
    n=$((i + 1))
    printf -v x "x%02d" $i
    cat $x | sed "s/^/$TMPD\//" | xargs cat > fold${n}.csv
done
rm -f x??
rm -rf $TMPD
