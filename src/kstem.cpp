/*
 * Copyright 2018 The Fxt authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#include <fstream>
#include <iostream>
#include <sstream>

#include "indri/KrovetzStemmer.hpp"

std::istream &get_stream(int argc, char **argv, std::ifstream &file) {
  if (2 == argc) {
    file.open(argv[1]);
    if (!file) {
      std::cerr << "error opening file: " << argv[1] << std::endl;
    }
    return file;
  }

  return std::cin;
}

/*
 * Stem text with the Krovetz stemmer.
 */
int main(int argc, char **argv) {
  std::ifstream inf;
  std::istream &ins = get_stream(argc, argv, inf);
  if (!ins.good()) {
    return 1;
  }

  indri::parse::KrovetzStemmer *ks = new indri::parse::KrovetzStemmer();
  std::string line;
  while (std::getline(ins, line)) {
    bool first = true;
    std::istringstream iss(line);
    std::string term;
    while (iss >> term) {
      if (!first) {
        std::cout << " ";
      }
      std::cout << ks->kstem_stemmer(&term[0]);
      if (first) {
        first = false;
      }
    }
    std::cout << std::endl;
  }

  inf.close();
  delete ks;

  return 0;
}
