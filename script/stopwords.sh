#!/bin/bash

DAT=/path/to/web-1t-5gram/web_5gram_d1/data/1gms/vocab_cs.gz

zcat $DAT | head -1000 \
    | awk '$1 ~ /^[A-Za-z]+$/ {print $1}' | tr [:upper:] [:lower:] > vocab.txt
sort -u vocab.txt > vocab.uniq.txt

awk 'BEGIN {
    c = 1;
}

NR == FNR {
    map[$1] = 1
    next
}

c <= 100 {
    if (map[$1] == 1) {
        print $1
        c += 1
        map[$1] = 2
    }
}' vocab.uniq.txt vocab.txt > vocab.100.txt
