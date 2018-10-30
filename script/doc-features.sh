#!/bin/bash

SPATH="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

awk 'BEGIN {n = 1} $2 ~ "x" { $2 = n; n++;} {print}' $SPATH/features.template
