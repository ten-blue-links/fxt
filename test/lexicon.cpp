#include "catch2/catch.hpp"

#include "tesserae/lexicon.hpp"

TEST_CASE("oov term does not contribute to collection length") {
  Lexicon lexicon({0, 0});

  REQUIRE(0 == lexicon.length());
}

TEST_CASE("access an oov term") {
  Lexicon lexicon({0, 0});

  REQUIRE(0 == lexicon.term("xxoov"));
  REQUIRE(0 == lexicon.term("foobar"));
}
