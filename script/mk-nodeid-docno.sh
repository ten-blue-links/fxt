#!/bin/bash

docid2url=ClueWeb12_B13_DocID_To_URL.txt
url2nodeid=Clueweb12_url2nodeId.txt
id2docno=ClueWeb12B-ID-DOCNO.txt

test -f $id2docno && echo "file exists $id2docno, skipping" && exit 0

test ! -f $docid2url && echo "missing $docid2url" && exit 1
test ! -f $url2nodeid && echo "missing $url2nodeid" && exit 1

sed 's/,//' $docid2url > ClueWeb12_B13_DocID_To_URL.txt.sed
awk 'NR == FNR {
    urlmap[$2] = $1
    next
}

{
    if ($1 in urlmap) {
        print urlmap[$1], $2
    }
}' ClueWeb12_B13_DocID_To_URL.txt.sed $url2nodeid > ClueWeb12B-ID-DOCNO.txt
