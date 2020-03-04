#include <catch2/catch.hpp>

#include "tesserae/features/lmds/lm.hpp"

TEST_CASE("Simple LMDS score") {
  REQUIRE(Approx(-5.02388) == calculate_lm(10, 100, 20, 10000, 1500));
}

