# Fxt
A large scale feature extraction tool for text-based machine learning.

## Building from Source
1. Make sure you have installed the dependencies:

    * A recent version of `g++` or `clang`
    * GNU `make`
    * `cmake` 3.0 or later
    * `git`

2. Clone the [source] with `git`:

    ```sh
    $ git clone https://github.com/rmit-ir/fxt.git
    $ cd fxt
    ```

[source]: https://github.com/rmit-ir/fxt

3. Build and install:

    ```sh
    git submodule update --init --recursive --progress
    mkdir build
    cd build
    cmake ..
    make
    ```

## Features
The toolkit offers a large number of text-based features that can be configured
for extraction. See the [feature list](doc/features.md) for the feature types
and descriptions.

## Documentation
For a quick tour see the [quick start](doc/quick-start.md) guide. Then refer to
the main [documentation](doc/index.md) for specific topics in more detail.

## License
[license]: #license

Tesserae is distributed under the terms of the MIT license.

See [LICENSE](LICENSE) for details.
