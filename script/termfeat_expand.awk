#!/usr/bin/awk -f

BEGIN {
    FS = ","
}

NR == FNR {
    query[$2] += 1
    next
}

{
    for (i = 0; i < query[$1]; i++) {
        print $0
    }
}
