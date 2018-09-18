#!/bin/bash

set -ex

SPATH="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
BASE=$SPATH/../..
BIN=$SPATH/../../build-debug/bin
INDEX=/research/remote/petabyte/users/luke/indri_indexes/gov2_fields

sed 's/;/ /' gov2.txt | $BIN/kstem | sed 's/ /;/' > gov2.kstem

awk -F\; 'BEGIN {
    print "<parameters>"
}
{
    printf "<query><number>%s</number><text>%s</text></query>\n", $1, $2
}
END {
    print "</parameters>"
}' gov2.kstem > gov2.indri

OKAPI="-baseline=okapi,k1:0.9,b:0.4,k3:0"
IndriRunQuery \
    $OKAPI \
    -index=$INDEX \
    -trecFormat=1 \
    -count=1000 \
    -stemmer.name=krovetz \
    -threads=24 \
    gov2.indri > gov2-bm25.run

../../script/label.awk gov2.qrels gov2-bm25.run > stage0.run

$BIN/generate_document_features \
    gov2.kstem \
    stage0.run \
    $INDEX \
    $BASE/build-debug/gov2.fwd \
    $BASE/build-debug/gov2.lex \
    docfeat.csv

./shuf.sh

sed -Ei 's/:\-?nan/:0.0/g' fold{1..5}.csv
for i in {1..5}; do
    $SPATH/../../script/csv2svm.awk fold${i}.csv > fold${i}.txt
done

mkdir -p f{1,2,3,4,5}

# svm
cat fold{1,2,3}.txt > f1/train.txt
cp fold4.txt f1/val.txt
cp fold5.txt f1/test.txt

cat fold{2,3,4}.txt > f2/train.txt
cp fold5.txt f2/val.txt
cp fold1.txt f2/test.txt

cat fold{3,4,5}.txt > f3/train.txt
cp fold1.txt f3/val.txt
cp fold2.txt f3/test.txt

cat fold{4,5,1}.txt > f4/train.txt
cp fold2.txt f4/val.txt
cp fold3.txt f4/test.txt

cat fold{5,1,2}.txt > f5/train.txt
cp fold3.txt f5/val.txt
cp fold4.txt f5/test.txt

# csv
cat fold{1,2,3}.csv | cut -d',' -f 3 --complement > f1/train.csv
cat fold4.csv | cut -d',' -f 3 --complement > f1/val.csv
cat fold5.csv | cut -d',' -f 3 --complement > f1/test.csv

cat fold{2,3,4}.csv | cut -d',' -f 3 --complement > f2/train.csv
cat fold5.csv | cut -d',' -f 3 --complement > f2/val.csv
cat fold1.csv | cut -d',' -f 3 --complement > f2/test.csv

cat fold{3,4,5}.csv | cut -d',' -f 3 --complement > f3/train.csv
cat fold1.csv | cut -d',' -f 3 --complement > f3/val.csv
cat fold2.csv | cut -d',' -f 3 --complement > f3/test.csv

cat fold{4,5,1}.csv | cut -d',' -f 3 --complement > f4/train.csv
cat fold2.csv | cut -d',' -f 3 --complement > f4/val.csv
cat fold3.csv | cut -d',' -f 3 --complement > f4/test.csv

cat fold{5,1,2}.csv | cut -d',' -f 3 --complement > f5/train.csv
cat fold3.csv | cut -d',' -f 3 --complement > f5/val.csv
cat fold4.csv | cut -d',' -f 3 --complement > f5/test.csv

for i in {1..5}; do
awk '{
    print $2, "0", $NF, $1
}' f${i}/test.txt | sed -e 's/qid://' -e 's/docno://' > f${i}/test.qrels
done
