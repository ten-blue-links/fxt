from __future__ import print_function

import os
import sys
import argparse

from pathlib import Path

from sklearn.datasets import load_svmlight_file, dump_svmlight_file
from sklearn.model_selection import GroupKFold

if __name__ == '__main__':
  parser = argparse.ArgumentParser()
  parser.add_argument('-k', default=2, type=int)
  parser.add_argument('file', type=str, nargs=1)
  FLAGS, unparsed = parser.parse_known_args()
  FLAGS.file = FLAGS.file[0]

  print("loading input file...", file=sys.stderr)
  X, y, qid = load_svmlight_file(FLAGS.file, query_id=True)
  group_kfold = GroupKFold(n_splits=FLAGS.k)

  count = 1
  for _, test_idx in group_kfold.split(X, y, qid):
    name = "fold{}.txt".format(count)
    print("{}...".format(name), file=sys.stderr)
    dump_svmlight_file(X[test_idx], y[test_idx], name, query_id=qid[test_idx])
    count += 1
