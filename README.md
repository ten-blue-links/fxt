# text2feat
A large scale feature extraction tool for text-based machine learning.

## Building from Source
1. Make sure you have installed the dependencies:

    * A recent version of `g++` or `clang`
    * GNU `make`
    * `cmake` 3.0 or later
    * `git`

2. Clone the [source] with `git`:

    ```sh
    $ git clone https://github.com/rmit-ir/text2feat.git
    $ cd text2feat
    ```

[source]: https://github.com/rmit-ir/text2feat

3. Build and install:

    ```sh
    git submodule update --init --recursive --progress
    mkdir build
    cd build
    cmake ..
    make
    ```

## License
[license]: #license

text2feat is distributed under the terms of the MIT license.

See [LICENSE](LICENSE) for details.
