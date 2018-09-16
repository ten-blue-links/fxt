# text2feat
A large scale feature extraction tool for text-based machine learning

[![Build Status](https://travis-ci.org/rmit-ir/text2feat.svg?branch=master)](https://travis-ci.org/rmit-ir/text2feat)

## Building the code
The code is tested on Linux with GCC 7.3.0 and Clang 5.0.

To build the code:

```
$ mkdir build
$ cd build
$ cmake .. -DCMAKE_BUILD_TYPE=Release
$ make
```

## Usage


```
make all INDRI_INDEX=<indri index path> QUERIES=<queries file> STAGE0=<TREC run>
```
