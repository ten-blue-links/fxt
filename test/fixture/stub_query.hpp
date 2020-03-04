#include "tesserae/lexicon.hpp"
#include "tesserae/query_train_file.hpp"

namespace fixture {

// Get a query that can be used for testing. Currently ignores the `pos` vector
// of query term positions.
query_train stub_query(const std::vector<std::string> terms,
                       const Lexicon& lexicon) {
  query_train qry;
  qry.id = "1";
  qry.stems = terms;

  for (const auto& t : terms) {
    uint64_t tid = lexicon.term(t);
    qry.tids.push_back(tid);
    qry.q_ft[tid] += 1;
  }

  return qry;
}

} // namespace fixture
