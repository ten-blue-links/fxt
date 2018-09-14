#!/usr/bin/awk -f

BEGIN {
    FS = ","
}

{
    str = ""
    for (i = 4; i <= NF; ++i) {
        str = str (i-3) ":" $i " "
    }

    print $1, "qid:" $2, str "# docno:" $3
}
