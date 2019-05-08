# Quick Start Guide

Tesserae is comprised of a number of components which we will cover briefly
here to give an overview of how to setup and configure a feature extraction
pipeline.

There are two main components within the pipeline:

1. Indexing
2. Feature extraction

## Indexing
The first step is to build an index. Currently, an existing [Indri] index is
required.

[indri]: https://lemurproject.org/indri.php

Assuming you already have an Indri index at the path `qs-indri` you can build a
Tesserae index with the following:

```sh
mkdir qs.tesserae
create_lexicon qs-indri qs.tesserae/lexicon
create_inverted_index qs-indri qs.tesserae/inverted_index
create_doc_lens qs-indri qs.tesserae/doclen
create_forward_index qs-indri qs.tesserae/forward_index
generate_static_doc_features qs-indri qs.tesserae/static_doc
```

## Feature Extraction
With an index created, it is now possible to run the feature extraction
component via the `extract_features` program. To do this we need to:

1. Create a query file in the right format:

    The query format is a text file with one entry per line as
    `<query id>;<query terms>`. For example a file with three queries looks
    like:

    ```
    51;horse hooves
    52;avp
    53;discovery channel store
    ```

2. Apply stemming to the queries if the original Indri index used stemming:

    If there was no stemming configured then you can skip this step. For
    indexes that use stemming, the queries need to be stemmed manually. For
    example, if the Krovetz stemmer was used then you can use the `kstem`
    program to apply stemming:

    ```sh
    sed 's/;/ /' queryfile | kstem | sed 's/ /;/' > queryfile.kstem
    ```

3. Configuration options via INI file:

    The path to the Tesserae index and the features to be extracted are
    configured via an INI configuration file. Each available feature can be
    configured for extraction. Features must be explicitly enabled for
    extraction. See the example [configuration file](/doc/configuration.md).

4. Labels

    Instance labels need to be converted into a specific format (qrels). The
    label file is a text file with one label entry per line as 
    `<query id> 0 <docid> <label>`. For example a label file for the three
    queries mentioned earlier would look like:

    ```
    51 0 docid-1 1
    51 0 docid-2 0
    52 0 docid-7 0
    52 0 docid-2 1
    53 0 docid-1 0
    53 0 docid-8 1
    ```

5. Document list (Stage0 run):

    The feature extraction process assumes that you already have a candidate
    set of documents for each query that you wish to extract the features for.
    This is known as a run file and uses the following format
    `<query id> Q0 <docid> 0 <score> <run identifier>`.

6. Add labels to the Stage0 run file:

    ```sh
    ./script/label.awk labels.txt myrun.txt > stage0.run
    ```

7. Perform feature extraction:

    ```sh
    ./extract_features -c config.ini queryfile.kstem stage0.run output.csv
    ```
