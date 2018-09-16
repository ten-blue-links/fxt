/*
 * Dump number of inlinks for each document.
 *
 * Currently this program is structured around dumping inlinks in a format from
 * the ClueWeb collections.
 *
 * See also scipt/mk-nodeid-docno.sh.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

int
main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "usage: ./outlink <doc id file>" << std::endl << std::endl
          << "For CW09B run:" << std::endl
          << "  zcat ClueWeb09_WG_50m.graph-txt.gz | ./outlink ClueB-ID-DOCNO.txt > cw09outlinks.txt"
          << std::endl << std::endl
          << "For CW12B run:" << std::endl
          << "  ./mk-nodeid-docno.sh" << std::endl
          << "  bzcat ClueWeb12_WebGraph_v2_0.txt.bz2 | ./outlink ClueWeb12B-ID-DOCNO.txt > cw12outlinks.txt"
          << std::endl << std::endl;
        return 1;
    }
    const size_t fields = 2;
    std::string infile = argv[1];
    std::unordered_map<uint64_t, std::string> node_map;

    std::cerr << "loading ID-DOCNO file...";
    std::ifstream ifs(infile);

    std::vector<std::string> parts;
    std::string line;
    while (std::getline(ifs, line, '\n')) {
      std::istringstream iss(line);
      std::string str;
      while (iss >> str) {
        parts.push_back(str);
      }
      if (fields != parts.size()) {
        std::cerr << "Required fields is " << fields << ", but got " << parts.size();
        return 1;
      }

      node_map.insert({std::stoll(parts[0]), parts[1]});
      parts.clear();
    }
    ifs.close();
    ifs.clear();
    std::cerr << "done." << std::endl;
    std::cerr << "map size: " << node_map.size() << std::endl;

    // read data from stdin
    bool once = false;
    uint64_t node_id = 0;
    while (std::getline(std::cin, line, '\n')) {
      if (!once) {
        once = true;
        continue;
      }
      std::istringstream iss(line);
      std::string str;
      uint64_t c = 0;
      while (iss >> str) {
        c++;
      }
      // dump docno and number of outlinks
      if (node_map.find(node_id) != node_map.end()) {
        std::cout << node_map[node_id] << " " << c << std::endl;
      }
      node_id++;
    }

    return 0;
}
