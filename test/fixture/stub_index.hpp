#include "tesserae/forward_index.hpp"
#include "tesserae/inverted_index.hpp"
#include "tesserae/lexicon.hpp"

namespace fixture {

Lexicon stub_lexicon() {
  Lexicon lexicon(Counts(16, 1315));
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("1", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("12", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("15", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("1999", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("2", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("20", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("23", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("24", c, fc);
  }
  {
    Counts c(2, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("32", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("33", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("34", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("35", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("36", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("37", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("38", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("39", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("43", c, fc);
  }
  {
    Counts c(4, 32);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("a", c, fc);
  }
  {
    Counts c(2, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("about", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("accelerate", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("achieve", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("action", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("actress", c, fc);
  }
  {
    Counts c(1, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(1, 1)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("adaptation", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("after", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("against", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("age", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("agenda", c, fc);
  }
  {
    Counts c(1, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(1, 1)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("agnostic", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("ahead", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("aim", c, fc);
  }
  {
    Counts c(1, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("algorithm", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("all", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("also", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("among", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("amount", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("an", c, fc);
  }
  {
    Counts c(5, 26);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("and", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("andpresent", c, fc);
  }
  {
    Counts c(2, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("any", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("anyway", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("apple", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("applicable", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("application", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("applied", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("apply", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("approach", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("aproblem", c, fc);
  }
  {
    Counts c(3, 5);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("are", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("argue", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("art", c, fc);
  }
  {
    Counts c(3, 5);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("as", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("ask", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("at", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("attention", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("basic", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("bath", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("bathtub", c, fc);
  }
  {
    Counts c(3, 5);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("be", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("because", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("been", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("beginning", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("benchmark", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("better", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("bicameral", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("bitmap", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("black", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("blazing", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("blue", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("bobbl", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("book", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("both", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("brandish", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("breakdown", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("breathe", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("bright", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("broken", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("burbclave", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("burg", c, fc);
  }
  {
    Counts c(2, 6);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("but", c, fc);
  }
  {
    Counts c(2, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("by", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("call", c, fc);
  }
  {
    Counts c(3, 7);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("can", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("cant", c, fc);
  }
  {
    Counts c(2, 5);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("car", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("card", c, fc);
  }
  {
    Counts c(2, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("case", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("cayley", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("center", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("chapter", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("circle", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("clapboard", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("class", c, fc);
  }
  {
    Counts c(1, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("classification", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("classify", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("clock", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("coming", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("command", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("compatible", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("compete", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("competition", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("complex", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("computer", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("consciousness", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("consider", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("construction", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("continuous", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("cooperation", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("corner", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("corporate", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("cosanostra", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("country", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("crap", c, fc);
  }
  {
    Counts c(2, 5);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(2, 2)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("crash", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("creative", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("creativity", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("d", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("data", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("datafrom", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("datapointssample", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(1, 1)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("deep", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("define", c, fc);
  }
  {
    Counts c(2, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("deliver", c, fc);
  }
  {
    Counts c(2, 9);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("deliverator", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("delivery", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("delvery", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("demonstrate", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("descent", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("detail", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("dickson", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("differ", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("different", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("digit", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("dinner", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("discuss", c, fc);
  }
  {
    Counts c(2, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("do", c, fc);
  }
  {
    Counts c(2, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("doesnt", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("dollar", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("domain", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("dont", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("doorway", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("dork", c, fc);
  }
  {
    Counts c(2, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("down", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("dripping", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("drive", c, fc);
  }
  {
    Counts c(1, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("driver", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("driveway", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("early", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("easy", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("education", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("effect", c, fc);
  }
  {
    Counts c(1, 8);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("eight", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("either", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("elementary", c, fc);
  }
  {
    Counts c(2, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("enzo", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("essay", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("ethic", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("even", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("evening", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("everything", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(1, 1)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("ex", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("example", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("exceptional", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(1, 1)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("excerpt", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("expectancy", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("explain", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("explicit", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("face", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("failure", c, fc);
  }
  {
    Counts c(1, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("family", c, fc);
  }
  {
    Counts c(2, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(1, 1)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("fast", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("feel", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("feet", c, fc);
  }
  {
    Counts c(1, 8);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("few", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("field", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("fifty", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("file", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("fine", c, fc);
  }
  {
    Counts c(2, 6);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("five", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("flipper", c, fc);
  }
  {
    Counts c(3, 11);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(1, 1)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("for", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("force", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("form", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("formalize", c, fc);
  }
  {
    Counts c(2, 6);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("four", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("free", c, fc);
  }
  {
    Counts c(2, 4);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(1, 1)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("from", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("fromon", c, fc);
  }
  {
    Counts c(2, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("front", c, fc);
  }
  {
    Counts c(2, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("fucking", c, fc);
  }
  {
    Counts c(1, 4);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("function", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("garage", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("general", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("generalization", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("generate", c, fc);
  }
  {
    Counts c(2, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("get", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("gibberish", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("glint", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("glowing", c, fc);
  }
  {
    Counts c(2, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("go", c, fc);
  }
  {
    Counts c(1, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("goal", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("goalmight", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("god", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("golf", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("good", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("got", c, fc);
  }
  {
    Counts c(1, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("gradient", c, fc);
  }
  {
    Counts c(2, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("granddaughter", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("grim", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("group", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("grovel", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("guy", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("had", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("happen", c, fc);
  }
  {
    Counts c(1, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("hard", c, fc);
  }
  {
    Counts c(3, 8);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("has", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("hasprevious", c, fc);
  }
  {
    Counts c(3, 6);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("have", c, fc);
  }
  {
    Counts c(2, 8);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("he", c, fc);
  }
  {
    Counts c(2, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("heard", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("high", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("hiro", c, fc);
  }
  {
    Counts c(3, 13);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("his", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("home", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("homeowner", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("honor", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("hope", c, fc);
  }
  {
    Counts c(2, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("hour", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("house", c, fc);
  }
  {
    Counts c(2, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("how", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("hurry", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("i", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("idea", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("identical", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("if", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("image", c, fc);
  }
  {
    Counts c(5, 29);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("in", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("including", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("influence", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("ing", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("innumerable", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("input", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("instantiation", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("interrupt", c, fc);
  }
  {
    Counts c(3, 5);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("into", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("involved", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("iove", c, fc);
  }
  {
    Counts c(3, 15);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("is", c, fc);
  }
  {
    Counts c(3, 10);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("it", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("jayne", c, fc);
  }
  {
    Counts c(1, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("job", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("julian", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("just", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("kind", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("kiss", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("kitchen", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("know", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("known", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("kourier", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("late", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(1, 1)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("lax", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("leads", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("learn", c, fc);
  }
  {
    Counts c(1, 14);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(1, 1)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("learning", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("led", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("lengthy", c, fc);
  }
  {
    Counts c(2, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("lie", c, fc);
  }
  {
    Counts c(1, 4);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("life", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("light", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("like", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("likewise", c, fc);
  }
  {
    Counts c(2, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("line", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("little", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("logic", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("long", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("look", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("lossfunction", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("lost", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("macintosh", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("mafia", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("main", c, fc);
  }
  {
    Counts c(2, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("make", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("making", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("maml", c, fc);
  }
  {
    Counts c(2, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("many", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("march", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("mathematics", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("maybe", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("meaning", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("mecha", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("mellow", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("mention", c, fc);
  }
  {
    Counts c(1, 6);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(1, 1)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("meta", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("method", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("microcode", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("might", c, fc);
  }
  {
    Counts c(2, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("mind", c, fc);
  }
  {
    Counts c(2, 4);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("minutes", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("mode", c, fc);
  }
  {
    Counts c(1, 10);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(1, 1)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("model", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("month", c, fc);
  }
  {
    Counts c(3, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("more", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("most", c, fc);
  }
  {
    Counts c(2, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(1, 1)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("move", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("movies", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("much", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("music", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("must", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("n", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("name", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("natural", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(1, 1)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("neal", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("needs", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(1, 1)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("network", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("neural", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("never", c, fc);
  }
  {
    Counts c(1, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("new", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("next", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("night", c, fc);
  }
  {
    Counts c(1, 9);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("nine", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("ninja", c, fc);
  }
  {
    Counts c(2, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("no", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("nobody", c, fc);
  }
  {
    Counts c(3, 5);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("not", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("novel", c, fc);
  }
  {
    Counts c(2, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("now", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("npponese", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("number", c, fc);
  }
  {
    Counts c(2, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("numbers", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("object", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("obstreperous", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("occasional", c, fc);
  }
  {
    Counts c(1, 4);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("octonion", c, fc);
  }
  {
    Counts c(4, 34);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(1, 1)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("of", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("ofa", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("off", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("often", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("oh", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("old", c, fc);
  }
  {
    Counts c(4, 13);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("on", c, fc);
  }
  {
    Counts c(5, 9);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("one", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("only", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("onlyone", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("operation", c, fc);
  }
  {
    Counts c(3, 8);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("or", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("order", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("origin", c, fc);
  }
  {
    Counts c(2, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("other", c, fc);
  }
  {
    Counts c(1, 4);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("our", c, fc);
  }
  {
    Counts c(2, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("out", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("output", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("over", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("own", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("pair", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("parameter", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("park", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("particular", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("pay", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("pepperoni", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("performance", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("ph", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("pie", c, fc);
  }
  {
    Counts c(2, 8);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("pizza", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("place", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("play", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("policy", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("pre", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("predict", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("principle", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("prior", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("private", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("problem", c, fc);
  }
  {
    Counts c(2, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("produce", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("property", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("propose", c, fc);
  }
  {
    Counts c(1, 4);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("proud", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("punk", c, fc);
  }
  {
    Counts c(2, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("put", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("quantum", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("quaternion", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("race", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("rapid", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("rat", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("red", c, fc);
  }
  {
    Counts c(1, 4);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("regress", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("rein", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("reinforcement", c, fc);
  }
  {
    Counts c(2, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("related", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("relativity", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("remember", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("report", c, fc);
  }
  {
    Counts c(2, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("result", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("rich", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("right", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("road", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("rumor", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("run", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("s", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("same", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("sample", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("say", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("school", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("scum", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("seconds", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("section", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("sedenion", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("see", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("seeing", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("seem", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("seen", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("segway", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("seiko", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("sense", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("sent", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("serving", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("set", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("setting", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("setup", c, fc);
  }
  {
    Counts c(2, 8);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("seven", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("shake", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("shallow", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("shoot", c, fc);
  }
  {
    Counts c(1, 5);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("shot", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("shoulder", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("sicilian", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("side", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("sideways", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("sign", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("similar", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("single", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("sink", c, fc);
  }
  {
    Counts c(3, 8);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("six", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("sixteen", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("skate", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("skill", c, fc);
  }
  {
    Counts c(1, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("small", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("smart", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(1, 1)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("smooth", c, fc);
  }
  {
    Counts c(2, 4);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(2, 2)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("snow", c, fc);
  }
  {
    Counts c(2, 4);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("so", c, fc);
  }
  {
    Counts c(2, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("software", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("solve", c, fc);
  }
  {
    Counts c(2, 5);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("some", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("something", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("sometimes", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("song", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("space", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("special", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("species", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("specific", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("speed", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("spice", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("stand", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("standard", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("standing", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("state", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("static", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("statistic", c, fc);
  }
  {
    Counts c(2, 4);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(1, 1)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("stephenson", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("steps", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("sticker", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("still", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("stinking", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("story", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("strawbridge", c, fc);
  }
  {
    Counts c(2, 4);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("street", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("stress", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("string", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("structure", c, fc);
  }
  {
    Counts c(2, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("studied", c, fc);
  }
  {
    Counts c(3, 4);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("such", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("suit", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("super", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("supervise", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("sure", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("surprise", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("swear", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("sweaty", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("swing", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("t", c, fc);
  }
  {
    Counts c(2, 4);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("take", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("taking", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("tall", c, fc);
  }
  {
    Counts c(1, 8);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("task", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("teaching", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("television", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("tell", c, fc);
  }
  {
    Counts c(1, 10);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("ten", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("tenure", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("term", c, fc);
  }
  {
    Counts c(2, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("than", c, fc);
  }
  {
    Counts c(4, 18);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("that", c, fc);
  }
  {
    Counts c(5, 81);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("the", c, fc);
  }
  {
    Counts c(1, 4);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("their", c, fc);
  }
  {
    Counts c(2, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("them", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("theory", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("there", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("these", c, fc);
  }
  {
    Counts c(2, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("they", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("things", c, fc);
  }
  {
    Counts c(2, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("think", c, fc);
  }
  {
    Counts c(2, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("thirty", c, fc);
  }
  {
    Counts c(3, 7);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("this", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("those", c, fc);
  }
  {
    Counts c(2, 5);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("three", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("time", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("times", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("tire", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("title", c, fc);
  }
  {
    Counts c(4, 36);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("to", c, fc);
  }
  {
    Counts c(1, 5);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("train", c, fc);
  }
  {
    Counts c(1, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("training", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("trillion", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("try", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("tune", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("turning", c, fc);
  }
  {
    Counts c(2, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("twenty", c, fc);
  }
  {
    Counts c(5, 8);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("two", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("type", c, fc);
  }
  {
    Counts c(2, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("uncle", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("uniform", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("universe", c, fc);
  }
  {
    Counts c(2, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("up", c, fc);
  }
  {
    Counts c(3, 5);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("use", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("vague", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("value", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("variety", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("vinyl", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("vise", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("vision", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("walk", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("warning", c, fc);
  }
  {
    Counts c(2, 4);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("was", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("watch", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("wave", c, fc);
  }
  {
    Counts c(1, 5);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("we", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("wear", c, fc);
  }
  {
    Counts c(3, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("well", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("were", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("wet", c, fc);
  }
  {
    Counts c(2, 4);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("what", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("whatever", c, fc);
  }
  {
    Counts c(3, 4);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("when", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("where", c, fc);
  }
  {
    Counts c(2, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("which", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("whipsaw", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("whose", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("why", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("widely", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(1, 1)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("wikipedia", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("will", c, fc);
  }
  {
    Counts c(3, 9);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("with", c, fc);
  }
  {
    Counts c(2, 4);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("work", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("working", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("would", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("wrote", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("year", c, fc);
  }
  {
    Counts c(1, 2);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("years", c, fc);
  }
  {
    Counts c(1, 1);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("yellow", c, fc);
  }
  {
    Counts c(1, 7);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("you", c, fc);
  }
  {
    Counts c(2, 7);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("your", c, fc);
  }
  {
    Counts c(2, 3);
    FieldCounts fc;
    fc.insert(std::make_pair(2, Counts(0, 0)));
    fc.insert(std::make_pair(3, Counts(0, 0)));
    fc.insert(std::make_pair(4, Counts(0, 0)));
    fc.insert(std::make_pair(5, Counts(0, 0)));
    fc.insert(std::make_pair(8, Counts(0, 0)));
    lexicon.push_back("youre", c, fc);
  }
  return lexicon;
}

ForwardIndex stub_forward_index() {
  ForwardIndex forward_index;
  const std::vector<uint16_t> doc_fields_0 = {};
  const std::vector<uint32_t> doc_terms_0 = {};
  const std::vector<uint32_t> doc_unique_terms_0 = {};
  const std::vector<uint32_t> doc_freqs_0 = {};
  const std::vector<std::vector<uint32_t>> doc_field_freqs_0 = {};
  const std::map<uint16_t, Field> doc_field_stats_0 = {};
  {
    Document doc_0(0);
    doc_0.set_fields(doc_fields_0);
    doc_0.set_terms(doc_terms_0);
    doc_0.set_freq(doc_freqs_0);
    forward_index.push_back(doc_0);
  }
  const std::vector<uint16_t> doc_fields_1 = {
      8, 4, 2, 3, 5,
  };
  const std::vector<uint32_t> doc_terms_1 = {
      341,
  };
  const std::vector<uint32_t> doc_unique_terms_1 = {
      341,
  };
  const std::vector<uint32_t> doc_freqs_1 = {
      0,
  };
  const std::vector<std::vector<uint32_t>> doc_field_freqs_1 = {
      {}, {}, {}, {}, {},
  };
  const std::map<uint16_t, Field> doc_field_stats_1 = {};
  {
    Document doc_1(1);
    doc_1.set_fields(doc_fields_1);
    doc_1.set_terms(doc_terms_1);
    doc_1.set_freq(doc_freqs_1);
    forward_index.push_back(doc_1);
  }
  const std::vector<uint16_t> doc_fields_2 = {
      8, 4, 2, 3, 5,
  };
  const std::vector<uint32_t> doc_terms_2 = {
      518,
      518,
  };
  const std::vector<uint32_t> doc_unique_terms_2 = {
      518,
  };
  const std::vector<uint32_t> doc_freqs_2 = {
      2,
  };
  const std::vector<std::vector<uint32_t>> doc_field_freqs_2 = {
      {}, {}, {}, {}, {},
  };
  const std::map<uint16_t, Field> doc_field_stats_2 = {};
  {
    Document doc_2(2);
    doc_2.set_fields(doc_fields_2);
    doc_2.set_terms(doc_terms_2);
    doc_2.set_freq(doc_freqs_2);
    forward_index.push_back(doc_2);
  }
  const std::vector<uint16_t> doc_fields_3 = {
      8, 4, 2, 3, 5,
  };
  const std::vector<uint32_t> doc_terms_3 = {
      505,
      505,
      505,
  };
  const std::vector<uint32_t> doc_unique_terms_3 = {
      505,
  };
  const std::vector<uint32_t> doc_freqs_3 = {
      3,
  };
  const std::vector<std::vector<uint32_t>> doc_field_freqs_3 = {
      {}, {}, {}, {}, {},
  };
  const std::map<uint16_t, Field> doc_field_stats_3 = {};
  {
    Document doc_3(3);
    doc_3.set_fields(doc_fields_3);
    doc_3.set_terms(doc_terms_3);
    doc_3.set_freq(doc_freqs_3);
    forward_index.push_back(doc_3);
  }
  const std::vector<uint16_t> doc_fields_4 = {
      8, 4, 2, 3, 5,
  };
  const std::vector<uint32_t> doc_terms_4 = {
      185,
      185,
      185,
      185,
  };
  const std::vector<uint32_t> doc_unique_terms_4 = {
      185,
  };
  const std::vector<uint32_t> doc_freqs_4 = {
      4,
  };
  const std::vector<std::vector<uint32_t>> doc_field_freqs_4 = {
      {}, {}, {}, {}, {},
  };
  const std::map<uint16_t, Field> doc_field_stats_4 = {};
  {
    Document doc_4(4);
    doc_4.set_fields(doc_fields_4);
    doc_4.set_terms(doc_terms_4);
    doc_4.set_freq(doc_freqs_4);
    forward_index.push_back(doc_4);
  }
  const std::vector<uint16_t> doc_fields_5 = {
      8, 4, 2, 3, 5,
  };
  const std::vector<uint32_t> doc_terms_5 = {
      179, 179, 179, 179, 179,
  };
  const std::vector<uint32_t> doc_unique_terms_5 = {
      179,
  };
  const std::vector<uint32_t> doc_freqs_5 = {
      5,
  };
  const std::vector<std::vector<uint32_t>> doc_field_freqs_5 = {
      {}, {}, {}, {}, {},
  };
  const std::map<uint16_t, Field> doc_field_stats_5 = {};
  {
    Document doc_5(5);
    doc_5.set_fields(doc_fields_5);
    doc_5.set_terms(doc_terms_5);
    doc_5.set_freq(doc_freqs_5);
    forward_index.push_back(doc_5);
  }
  const std::vector<uint16_t> doc_fields_6 = {
      8, 4, 2, 3, 5,
  };
  const std::vector<uint32_t> doc_terms_6 = {
      432, 432, 432, 432, 432, 432,
  };
  const std::vector<uint32_t> doc_unique_terms_6 = {
      432,
  };
  const std::vector<uint32_t> doc_freqs_6 = {
      6,
  };
  const std::vector<std::vector<uint32_t>> doc_field_freqs_6 = {
      {}, {}, {}, {}, {},
  };
  const std::map<uint16_t, Field> doc_field_stats_6 = {};
  {
    Document doc_6(6);
    doc_6.set_fields(doc_fields_6);
    doc_6.set_terms(doc_terms_6);
    doc_6.set_freq(doc_freqs_6);
    forward_index.push_back(doc_6);
  }
  const std::vector<uint16_t> doc_fields_7 = {
      8, 4, 2, 3, 5,
  };
  const std::vector<uint32_t> doc_terms_7 = {
      419, 419, 419, 419, 419, 419, 419,
  };
  const std::vector<uint32_t> doc_unique_terms_7 = {
      419,
  };
  const std::vector<uint32_t> doc_freqs_7 = {
      7,
  };
  const std::vector<std::vector<uint32_t>> doc_field_freqs_7 = {
      {}, {}, {}, {}, {},
  };
  const std::map<uint16_t, Field> doc_field_stats_7 = {};
  {
    Document doc_7(7);
    doc_7.set_fields(doc_fields_7);
    doc_7.set_terms(doc_terms_7);
    doc_7.set_freq(doc_freqs_7);
    forward_index.push_back(doc_7);
  }
  const std::vector<uint16_t> doc_fields_8 = {
      8, 4, 2, 3, 5,
  };
  const std::vector<uint32_t> doc_terms_8 = {
      152, 152, 152, 152, 152, 152, 152, 152,
  };
  const std::vector<uint32_t> doc_unique_terms_8 = {
      152,
  };
  const std::vector<uint32_t> doc_freqs_8 = {
      8,
  };
  const std::vector<std::vector<uint32_t>> doc_field_freqs_8 = {
      {}, {}, {}, {}, {},
  };
  const std::map<uint16_t, Field> doc_field_stats_8 = {};
  {
    Document doc_8(8);
    doc_8.set_fields(doc_fields_8);
    doc_8.set_terms(doc_terms_8);
    doc_8.set_freq(doc_freqs_8);
    forward_index.push_back(doc_8);
  }
  const std::vector<uint16_t> doc_fields_9 = {
      8, 4, 2, 3, 5,
  };
  const std::vector<uint32_t> doc_terms_9 = {
      320, 320, 320, 320, 320, 320, 320, 320, 320,
  };
  const std::vector<uint32_t> doc_unique_terms_9 = {
      320,
  };
  const std::vector<uint32_t> doc_freqs_9 = {
      9,
  };
  const std::vector<std::vector<uint32_t>> doc_field_freqs_9 = {
      {}, {}, {}, {}, {},
  };
  const std::map<uint16_t, Field> doc_field_stats_9 = {};
  {
    Document doc_9(9);
    doc_9.set_fields(doc_fields_9);
    doc_9.set_terms(doc_terms_9);
    doc_9.set_freq(doc_freqs_9);
    forward_index.push_back(doc_9);
  }
  const std::vector<uint16_t> doc_fields_10 = {
      8, 4, 2, 3, 5,
  };
  const std::vector<uint32_t> doc_terms_10 = {
      488, 488, 488, 488, 488, 488, 488, 488, 488, 488,
  };
  const std::vector<uint32_t> doc_unique_terms_10 = {
      488,
  };
  const std::vector<uint32_t> doc_freqs_10 = {
      10,
  };
  const std::vector<std::vector<uint32_t>> doc_field_freqs_10 = {
      {}, {}, {}, {}, {},
  };
  const std::map<uint16_t, Field> doc_field_stats_10 = {};
  {
    Document doc_10(10);
    doc_10.set_fields(doc_fields_10);
    doc_10.set_terms(doc_terms_10);
    doc_10.set_freq(doc_freqs_10);
    forward_index.push_back(doc_10);
  }
  const std::vector<uint16_t> doc_fields_11 = {
      8, 4, 2, 3, 5,
  };
  const std::vector<uint32_t> doc_terms_11 = {
      164, 187, 312, 459, 439, 114, 90,  518, 307, 305, 295, 441, 221, 451, 363,
      126, 493, 124, 524, 510, 282, 441, 462, 136, 445, 80,  235, 268, 539, 18,
      291, 154, 402, 397, 81,  538, 289, 150, 361, 117, 398, 493, 124, 391, 86,
      555, 401, 222, 248, 440, 76,  38,  115, 80,  313, 510, 553, 215, 340, 223,
      108, 435, 440, 326, 219, 216, 503, 348, 251, 322, 76,  345, 116, 246, 80,
      322, 108, 153, 253, 18,  430, 369, 493, 124, 453, 483, 561, 362, 237, 502,
      298, 345, 560, 83,  218, 249, 186, 422, 493, 146, 481, 223, 85,  177, 18,
      93,  22,  472, 493, 124, 216, 61,  554, 503, 251, 181, 432, 301, 18,  393,
      38,  266, 489, 81,  223, 454, 38,  216, 316, 123, 18,  363, 237, 302, 491,
      517, 341, 298, 338, 499, 524, 510, 50,  352, 507, 285, 110, 5,   146, 558,
      278, 510, 249, 225, 384, 168, 38,  478, 552, 494, 353, 267, 463, 334, 339,
      452, 38,  251, 388, 467, 455, 237, 494, 199, 559, 141, 73,  494, 412, 38,
      535, 54,  493, 96,  352, 493, 256, 431, 232, 477, 84,  560, 212, 487, 506,
      493, 124, 136, 324, 257, 181, 475, 541, 214, 510, 493, 146, 237, 471, 87,
      80,  219, 216, 220, 443, 396, 303, 363, 125, 214, 237, 493, 159, 228, 545,
      520, 155, 105, 510, 59,  223, 371, 506, 38,  230, 555, 560, 172, 235, 560,
      213, 510, 244, 134, 552, 561, 170, 237, 346, 510, 82,  443, 331, 142, 237,
      18,  78,  38,  211, 181, 18,  260, 190, 363, 520, 155, 216, 324, 378, 237,
      176, 558, 415, 223, 170, 38,  223, 112, 440, 492, 54,  493, 27,  543, 303,
      49,  365, 204, 38,  70,  494, 208, 219, 83,  196, 350, 334, 493, 58,  144,
      540, 38,  267, 143, 38,  255, 493, 173, 334, 443, 433, 557, 339, 434, 377,
      547, 359, 533, 502, 341, 298, 237, 97,  338, 203, 249, 282, 493, 124, 75,
      18,  273, 421, 253, 510, 501, 334, 493, 233, 541, 18,  190, 383, 381, 492,
      248, 111, 363, 137, 218, 40,  101, 101, 200, 26,  493, 280, 157, 560, 140,
      553, 215, 60,  562, 100, 26,  443, 234, 344, 143, 493, 466, 560, 553, 215,
      60,  160, 248, 340, 493, 272, 561, 310, 561, 226, 561, 170, 561, 268, 504,
      79,  180, 296, 218, 18,  64,  268, 165, 80,  541, 254, 334, 268, 248, 249,
      41,  560, 218, 510, 53,  563, 492, 548, 323, 324, 158, 493, 327, 83,  304,
      363, 171, 491, 111, 493, 124, 248, 376, 510, 537, 493, 521, 376, 510, 145,
      493, 85,  376, 510, 286, 523, 493, 189, 531, 334, 241, 78,  224, 18,  209,
      530, 237, 321, 67,  18,  363, 340, 223, 424, 384, 265, 133, 68,  376, 329,
      245, 493, 319, 2,   9,   345, 3,   3,   345, 493, 332, 6,   17,
  };
  const std::vector<uint32_t> doc_unique_terms_11 = {
      2,   3,   5,   6,   9,   17,  18,  22,  26,  27,  38,  40,  41,  49,  50,
      53,  54,  58,  59,  60,  61,  64,  67,  68,  70,  73,  75,  76,  78,  79,
      80,  81,  82,  83,  84,  85,  86,  87,  90,  93,  96,  97,  100, 101, 105,
      108, 110, 111, 112, 114, 115, 116, 117, 123, 124, 125, 126, 133, 134, 136,
      137, 140, 141, 142, 143, 144, 145, 146, 150, 153, 154, 155, 157, 158, 159,
      160, 164, 165, 168, 170, 171, 172, 173, 176, 177, 180, 181, 186, 187, 189,
      190, 196, 199, 200, 203, 204, 208, 209, 211, 212, 213, 214, 215, 216, 218,
      219, 220, 221, 222, 223, 224, 225, 226, 228, 230, 232, 233, 234, 235, 237,
      241, 244, 245, 246, 248, 249, 251, 253, 254, 255, 256, 257, 260, 265, 266,
      267, 268, 272, 273, 278, 280, 282, 285, 286, 289, 291, 295, 296, 298, 301,
      302, 303, 304, 305, 307, 310, 312, 313, 316, 319, 321, 322, 323, 324, 326,
      327, 329, 331, 332, 334, 338, 339, 340, 341, 344, 345, 346, 348, 350, 352,
      353, 359, 361, 362, 363, 365, 369, 371, 376, 377, 378, 381, 383, 384, 388,
      391, 393, 396, 397, 398, 401, 402, 412, 415, 421, 422, 424, 430, 431, 432,
      433, 434, 435, 439, 440, 441, 443, 445, 451, 452, 453, 454, 455, 459, 462,
      463, 466, 467, 471, 472, 475, 477, 478, 481, 483, 487, 489, 491, 492, 493,
      494, 499, 501, 502, 503, 504, 506, 507, 510, 517, 518, 520, 521, 523, 524,
      530, 531, 533, 535, 537, 538, 539, 540, 541, 543, 545, 547, 548, 552, 553,
      554, 555, 557, 558, 559, 560, 561, 562, 563,
  };
  const std::vector<uint32_t> doc_freqs_11 = {
      1, 2, 1, 1, 1, 1, 12, 1, 2, 1,  12, 1, 1, 1, 1, 1, 2, 1, 1, 2,  1, 1,
      1, 1, 1, 1, 1, 2, 2,  1, 5, 2,  1,  3, 1, 2, 1, 1, 1, 1, 1, 1,  1, 2,
      1, 2, 1, 2, 1, 1, 1,  1, 1, 1,  7,  1, 1, 1, 1, 2, 1, 1, 1, 1,  2, 1,
      1, 3, 1, 1, 1, 2, 1,  1, 1, 1,  1,  1, 1, 3, 1, 1, 1, 1, 1, 1,  3, 1,
      1, 1, 2, 1, 1, 1, 1,  1, 1, 1,  1,  1, 1, 2, 3, 5, 4, 3, 1, 1,  1, 7,
      1, 1, 1, 1, 1, 1, 1,  1, 2, 10, 1,  1, 1, 1, 5, 4, 3, 2, 1, 1,  1, 1,
      1, 1, 1, 2, 4, 1, 1,  1, 1, 2,  1,  1, 1, 1, 1, 1, 3, 1, 1, 2,  1, 1,
      1, 1, 1, 1, 1, 1, 1,  2, 1, 3,  1,  1, 1, 1, 1, 6, 2, 2, 3, 2,  1, 4,
      1, 1, 1, 2, 1, 1, 1,  1, 7, 1,  1,  1, 4, 1, 1, 1, 1, 2, 1, 1,  1, 1,
      1, 1, 1, 1, 1, 1, 1,  1, 1, 1,  1,  1, 1, 1, 1, 1, 3, 2, 4, 1,  1, 1,
      1, 1, 1, 1, 1, 1, 1,  1, 1, 1,  1,  1, 1, 1, 1, 1, 1, 2, 3, 25, 4, 1,
      1, 2, 2, 1, 2, 1, 13, 1, 1, 2,  1,  1, 2, 1, 1, 1, 1, 1, 1, 1,  1, 3,
      1, 1, 1, 1, 2, 3, 1,  2, 1, 2,  1,  7, 6, 1, 1,
  };
  const std::vector<std::vector<uint32_t>> doc_field_freqs_11 = {
      {},
      {},
      {
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      },
      {},
      {},
  };
  const std::map<uint16_t, Field> doc_field_stats_11 = {};
  {
    Document doc_11(11);
    doc_11.set_fields(doc_fields_11);
    doc_11.set_terms(doc_terms_11);
    doc_11.set_freq(doc_freqs_11);
    forward_index.push_back(doc_11);
  }
  const std::vector<uint16_t> doc_fields_12 = {
      8, 4, 2, 3, 5,
  };
  const std::vector<uint32_t> doc_terms_12 = {
      333, 49,  324, 52,  538, 258, 52,  493, 380, 38,  102, 329, 545, 49,
      306, 302, 549, 470, 38,  524, 333, 49,  388, 510, 163, 469, 237, 287,
      35,  495, 493, 163, 267, 210, 341, 518, 505, 185, 341, 518, 505, 185,
      333, 218, 44,  237, 175, 471, 52,  468, 496, 448, 389, 38,  379, 274,
      46,  493, 88,  130, 106, 510, 493, 333, 373, 493, 406,
  };
  const std::vector<uint32_t> doc_unique_terms_12 = {
      35,  38,  44,  46,  49,  52,  88,  102, 106, 130, 163, 175,
      185, 210, 218, 237, 258, 267, 274, 287, 302, 306, 324, 329,
      333, 341, 373, 379, 380, 388, 389, 406, 448, 468, 469, 470,
      471, 493, 495, 496, 505, 510, 518, 524, 538, 545, 549,
  };
  const std::vector<uint32_t> doc_freqs_12 = {
      1, 3, 1, 1, 3, 3, 1, 1, 1, 1, 2, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1,
      4, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 1, 1, 2, 2, 2, 1, 1, 1, 1,
  };
  const std::vector<std::vector<uint32_t>> doc_field_freqs_12 = {
      {}, {}, {}, {}, {},
  };
  const std::map<uint16_t, Field> doc_field_stats_12 = {};
  {
    Document doc_12(12);
    doc_12.set_fields(doc_fields_12);
    doc_12.set_terms(doc_terms_12);
    doc_12.set_freq(doc_freqs_12);
    forward_index.push_back(doc_12);
  }
  const std::vector<uint16_t> doc_fields_13 = {
      8, 4, 2, 3, 5,
  };
  const std::vector<uint32_t> doc_terms_13 = {
      438, 304, 161, 261, 493, 124, 216, 220, 334, 498, 461, 249, 481, 228, 510,
      196, 495, 336, 218, 510, 481, 493, 85,  245, 18,  129, 364, 358, 513, 334,
      138, 493, 124, 216, 518, 500, 340, 223, 28,  326, 219, 248, 200, 510, 420,
      503, 466, 403, 542, 249, 481, 38,  123, 493, 190, 363, 33,  237, 493, 447,
      334, 8,   7,   493, 318, 179, 298, 38,  502, 419, 404, 503, 248, 249, 206,
      510, 358, 302, 55,  510, 493, 395, 219, 479, 245, 493, 426, 466, 322, 532,
      227, 288, 510, 546, 493, 259, 245, 493, 466, 428, 340, 493, 109, 137, 553,
      493, 437, 341, 534, 561, 189, 508, 499, 407, 543, 562, 516, 83,  0,   480,
      476, 495, 143, 465, 364, 249, 409, 440, 275, 275, 491, 219, 390, 311, 543,
      562, 237, 18,  231, 407, 493, 198, 334, 85,  523, 30,  85,  356, 427, 510,
      493, 395, 498, 308, 59,  356, 237, 493, 91,  38,  497, 493, 229, 269, 69,
      528, 92,  518, 464, 552, 341, 464, 192, 510, 493, 426, 219, 282, 492, 147,
      493, 89,  334, 223, 522, 378, 493, 259, 350, 334, 223, 297, 514, 324, 510,
      501, 19,  520, 155, 541, 219, 136, 394, 326, 237, 493, 57,  288, 345, 482,
      18,  113, 345, 283, 247, 510, 443, 23,  345, 485, 425, 446, 510, 341, 334,
      223, 517, 432, 208,
  };
  const std::vector<uint32_t> doc_unique_terms_13 = {
      0,   7,   8,   18,  19,  23,  28,  30,  33,  38,  55,  57,  59,  69,  83,
      85,  89,  91,  92,  109, 113, 123, 124, 129, 136, 137, 138, 143, 147, 155,
      161, 179, 189, 190, 192, 196, 198, 200, 206, 208, 216, 218, 219, 220, 223,
      227, 228, 229, 231, 237, 245, 247, 248, 249, 259, 261, 269, 275, 282, 283,
      288, 297, 298, 302, 304, 308, 311, 318, 322, 324, 326, 334, 336, 340, 341,
      345, 350, 356, 358, 363, 364, 378, 390, 394, 395, 403, 404, 407, 409, 419,
      420, 425, 426, 427, 428, 432, 437, 438, 440, 443, 446, 447, 461, 464, 465,
      466, 476, 479, 480, 481, 482, 485, 491, 492, 493, 495, 497, 498, 499, 500,
      501, 502, 503, 508, 510, 513, 514, 516, 517, 518, 520, 522, 523, 528, 532,
      534, 541, 542, 543, 546, 552, 553, 561, 562,
  };
  const std::vector<uint32_t> doc_freqs_13 = {
      1, 1, 1, 3, 1,  1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 3, 1, 1, 1,  1, 1, 1, 2, 1,
      1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 5,  1, 4, 1, 1, 1,
      1, 4, 3, 1, 2,  4, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1,  1, 1, 1, 2, 7,
      1, 2, 3, 3, 1,  2, 2, 1, 2, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1,  1, 2, 1, 1, 1,
      1, 1, 1, 1, 1,  1, 1, 2, 1, 3, 1, 1, 1, 3, 1, 1, 1, 1, 20, 2, 1, 2, 1, 1,
      1, 1, 2, 1, 11, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2,  1, 1, 1, 1, 2,
  };
  const std::vector<std::vector<uint32_t>> doc_field_freqs_13 = {
      {},
      {},
      {
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
          0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      },
      {},
      {},
  };
  const std::map<uint16_t, Field> doc_field_stats_13 = {};
  {
    Document doc_13(13);
    doc_13.set_fields(doc_fields_13);
    doc_13.set_terms(doc_terms_13);
    doc_13.set_freq(doc_freqs_13);
    forward_index.push_back(doc_13);
  }
  const std::vector<uint16_t> doc_fields_14 = {
      8, 4, 2, 3, 5,
  };
  const std::vector<uint32_t> doc_terms_14 = {};
  const std::vector<uint32_t> doc_unique_terms_14 = {};
  const std::vector<uint32_t> doc_freqs_14 = {};
  const std::vector<std::vector<uint32_t>> doc_field_freqs_14 = {
      {}, {}, {}, {}, {},
  };
  const std::map<uint16_t, Field> doc_field_stats_14 = {};
  {
    Document doc_14(14);
    doc_14.set_fields(doc_fields_14);
    doc_14.set_terms(doc_terms_14);
    doc_14.set_freq(doc_freqs_14);
    forward_index.push_back(doc_14);
  }
  const std::vector<uint16_t> doc_fields_15 = {
      8, 4, 2, 3, 5,
  };
  const std::vector<uint32_t> doc_terms_15 = {
      439, 114, 550, 459, 166, 493, 509, 334, 493, 325, 237, 223, 4,   156,
      9,   237, 493, 62,  533, 493, 98,  272, 52,  223, 490, 181, 18,  357,
      441, 10,  169, 299, 340, 493, 148, 11,  42,  279, 103, 459, 556, 19,
      493, 279, 492, 543, 493, 103, 114, 38,  556, 197, 245, 493, 12,  66,
      493, 392, 533, 444, 492, 276, 525, 270, 13,  457, 340, 18,  77,  486,
      416, 18,  439, 114, 0,   459, 216, 34,  292, 492, 14,  252, 250, 71,
      15,  493, 347, 334, 104, 237, 493, 74,  334, 493, 65,  297, 533, 341,
      334, 493, 281, 239, 340, 439, 114, 16,  1,
  };
  const std::vector<uint32_t> doc_unique_terms_15 = {
      0,   1,   4,   9,   10,  11,  12,  13,  14,  15,  16,  18,  19,  34,  38,
      42,  52,  62,  65,  66,  71,  74,  77,  98,  103, 104, 114, 148, 156, 166,
      169, 181, 197, 216, 223, 237, 239, 245, 250, 252, 270, 272, 276, 279, 281,
      292, 297, 299, 325, 334, 340, 341, 347, 357, 392, 416, 439, 441, 444, 457,
      459, 486, 490, 492, 493, 509, 525, 533, 543, 550, 556,
  };
  const std::vector<uint32_t> doc_freqs_15 = {
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1, 1,
      2, 1, 4, 1, 1, 1, 1, 1, 1, 1, 2, 3, 1, 1, 1, 1, 1,  1, 1, 2, 1, 1, 1, 1,
      1, 4, 3, 1, 1, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 3, 13, 1, 1, 3, 1, 1, 2,
  };
  const std::vector<std::vector<uint32_t>> doc_field_freqs_15 = {
      {},
      {},
      {
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
      },
      {},
      {},
  };
  const std::map<uint16_t, Field> doc_field_stats_15 = {};
  {
    Document doc_15(15);
    doc_15.set_fields(doc_fields_15);
    doc_15.set_terms(doc_terms_15);
    doc_15.set_freq(doc_freqs_15);
    forward_index.push_back(doc_15);
  }
  const std::vector<uint16_t> doc_fields_16 = {
      8, 4, 2, 3, 5,
  };
  const std::vector<uint32_t> doc_terms_16 = {
      300, 29,  293, 264, 181, 171, 24,  334, 121, 314, 536, 375, 37,  32,  181,
      293, 264, 492, 248, 300, 29,  237, 493, 413, 492, 249, 248, 99,  552, 40,
      300, 511, 552, 207, 128, 38,  43,  510, 18,  527, 334, 132, 264, 372, 238,
      94,  385, 38,  387, 264, 493, 201, 334, 293, 264, 248, 510, 511, 18,  300,
      340, 18,  527, 334, 264, 484, 471, 492, 249, 83,  442, 317, 264, 484, 524,
      342, 18,  436, 328, 334, 512, 400, 237, 349, 47,  493, 355, 334, 493, 300,
      49,  167, 511, 471, 492, 18,  436, 328, 334, 207, 460, 552, 18,  436, 36,
      334, 512, 118, 187, 18,  317, 484, 551, 373, 205, 194, 360, 340, 492, 484,
      237, 151, 349, 294, 511, 493, 300, 510, 59,  149, 510, 178, 515, 536, 127,
      492, 503, 47,  262, 510, 456, 334, 493, 51,  360, 340, 518, 174, 423, 236,
      94,  63,  373, 205, 392, 340, 174, 423, 385, 38,  20,  178, 515, 181, 366,
      207, 387, 264, 552, 315, 314, 366, 300, 29,  293, 264, 536, 31,  510, 511,
      300, 492, 83,  21,  382, 24,  48,  417, 492, 248, 337, 184, 52,  174, 423,
      263, 240, 237, 503, 405, 536, 551, 122, 493, 372, 418, 39,  493, 193, 183,
      334, 349, 32,  449, 334, 284, 237, 503, 405, 536, 135, 450, 243, 334, 349,
      293, 264, 32,  181, 474, 264, 38,  386, 182, 264, 493, 139, 131, 237, 493,
      183, 334, 277, 38,  237, 230, 118, 248, 195, 81,  493, 484, 38,  367, 414,
      510, 493, 300, 80,  493, 399, 56,  24,  290, 309, 83,  59,  45,  237, 72,
      87,  474, 385, 38,  94,  174, 423, 264, 248, 538, 470, 237, 493, 139, 334,
      473, 529, 484, 544, 493, 201, 248, 510, 263, 18,  317, 191, 188, 18,  174,
      242, 351, 354, 181, 492, 484, 524, 370, 119, 429, 484, 181, 293, 264, 181,
      162, 493, 202, 59,  510, 95,  236, 334, 18,  411, 25,  408, 343, 345, 18,
      174, 162, 334, 18,  411, 552, 18,  300, 492, 217, 410, 285, 348, 519, 334,
      330, 271, 237, 174, 423, 385, 493, 201, 248, 510, 368, 493, 351, 335, 107,
      526, 191, 187, 342, 18,  174, 120, 187, 492, 191, 25,  512, 340, 285, 191,
      552, 429, 458, 374,
  };
  const std::vector<uint32_t> doc_unique_terms_16 = {
      18,  20,  21,  24,  25,  29,  31,  32,  36,  37,  38,  39,  40,  43,  45,
      47,  48,  49,  51,  52,  56,  59,  63,  72,  80,  81,  83,  87,  94,  95,
      99,  107, 118, 119, 120, 121, 122, 127, 128, 131, 132, 135, 139, 149, 151,
      162, 167, 171, 174, 178, 181, 182, 183, 184, 187, 188, 191, 193, 194, 195,
      201, 202, 205, 207, 217, 230, 236, 237, 238, 240, 242, 243, 248, 249, 262,
      263, 264, 271, 277, 284, 285, 290, 293, 294, 300, 309, 314, 315, 317, 328,
      330, 334, 335, 337, 340, 342, 343, 345, 348, 349, 351, 354, 355, 360, 366,
      367, 368, 370, 372, 373, 374, 375, 382, 385, 386, 387, 392, 399, 400, 405,
      408, 410, 411, 413, 414, 417, 418, 423, 429, 436, 442, 449, 450, 456, 458,
      460, 470, 471, 473, 474, 484, 492, 493, 503, 510, 511, 512, 515, 518, 519,
      524, 526, 527, 529, 536, 538, 544, 551, 552,
  };
  const std::vector<uint32_t> doc_freqs_16 = {
      14, 1,  1,  3, 2,  3, 1, 3,  1, 1, 7, 1,  1, 1, 1, 2, 1,  1, 1, 1,
      1,  3,  1,  1, 1,  1, 3, 1,  3, 1, 1, 1,  2, 1, 1, 1, 1,  1, 1, 1,
      1,  1,  2,  1, 1,  2, 1, 1,  8, 2, 7, 1,  2, 1, 3, 1, 4,  1, 1, 1,
      3,  1,  2,  3, 1,  1, 2, 10, 1, 1, 1, 1,  8, 2, 1, 2, 14, 1, 1, 1,
      2,  1,  6,  1, 10, 1, 2, 1,  3, 2, 1, 17, 1, 1, 5, 2, 1,  1, 1, 4,
      2,  1,  1,  2, 2,  1, 1, 1,  2, 2, 1, 1,  1, 4, 1, 2, 1,  1, 1, 2,
      1,  1,  2,  1, 1,  1, 1, 5,  2, 3, 1, 1,  1, 1, 1, 1, 1,  2, 1, 2,
      8,  11, 18, 3, 10, 5, 3, 2,  1, 1, 2, 1,  2, 1, 5, 1, 1,  2, 6,
  };
  const std::vector<std::vector<uint32_t>> doc_field_freqs_16 = {
      {},
      {},
      {
          0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      },
      {},
      {},
  };
  const std::map<uint16_t, Field> doc_field_stats_16 = {};
  {
    Document doc_16(16);
    doc_16.set_fields(doc_fields_16);
    doc_16.set_terms(doc_terms_16);
    doc_16.set_freq(doc_freqs_16);
    forward_index.push_back(doc_16);
  }
  return forward_index;
}

InvertedIndex stub_inverted_index() {
  InvertedIndex inverted_index;
  {
    PostingList pl_0("", 0);
    pl_0.coding_off();
    std::vector<uint32_t> docs = {};
    std::vector<uint32_t> freqs = {};
    pl_0.set(docs, freqs);
    inverted_index.push_back(pl_0);
  }
  {
    PostingList pl_1("1", 1);
    pl_1.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_1.set(docs, freqs);
    inverted_index.push_back(pl_1);
  }
  {
    PostingList pl_2("12", 1);
    pl_2.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_2.set(docs, freqs);
    inverted_index.push_back(pl_2);
  }
  {
    PostingList pl_3("15", 2);
    pl_3.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_3.set(docs, freqs);
    inverted_index.push_back(pl_3);
  }
  {
    PostingList pl_4("1999", 1);
    pl_4.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_4.set(docs, freqs);
    inverted_index.push_back(pl_4);
  }
  {
    PostingList pl_5("2", 1);
    pl_5.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_5.set(docs, freqs);
    inverted_index.push_back(pl_5);
  }
  {
    PostingList pl_6("20", 1);
    pl_6.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_6.set(docs, freqs);
    inverted_index.push_back(pl_6);
  }
  {
    PostingList pl_7("23", 1);
    pl_7.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_7.set(docs, freqs);
    inverted_index.push_back(pl_7);
  }
  {
    PostingList pl_8("24", 1);
    pl_8.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_8.set(docs, freqs);
    inverted_index.push_back(pl_8);
  }
  {
    PostingList pl_9("32", 2);
    pl_9.coding_off();
    std::vector<uint32_t> docs = {
        11,
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
    };
    pl_9.set(docs, freqs);
    inverted_index.push_back(pl_9);
  }
  {
    PostingList pl_10("33", 1);
    pl_10.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_10.set(docs, freqs);
    inverted_index.push_back(pl_10);
  }
  {
    PostingList pl_11("34", 1);
    pl_11.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_11.set(docs, freqs);
    inverted_index.push_back(pl_11);
  }
  {
    PostingList pl_12("35", 1);
    pl_12.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_12.set(docs, freqs);
    inverted_index.push_back(pl_12);
  }
  {
    PostingList pl_13("36", 1);
    pl_13.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_13.set(docs, freqs);
    inverted_index.push_back(pl_13);
  }
  {
    PostingList pl_14("37", 1);
    pl_14.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_14.set(docs, freqs);
    inverted_index.push_back(pl_14);
  }
  {
    PostingList pl_15("38", 1);
    pl_15.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_15.set(docs, freqs);
    inverted_index.push_back(pl_15);
  }
  {
    PostingList pl_16("39", 1);
    pl_16.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_16.set(docs, freqs);
    inverted_index.push_back(pl_16);
  }
  {
    PostingList pl_17("43", 1);
    pl_17.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_17.set(docs, freqs);
    inverted_index.push_back(pl_17);
  }
  {
    PostingList pl_18("a", 32);
    pl_18.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
        15,
        16,
    };
    std::vector<uint32_t> freqs = {
        12,
        3,
        3,
        14,
    };
    pl_18.set(docs, freqs);
    inverted_index.push_back(pl_18);
  }
  {
    PostingList pl_19("about", 2);
    pl_19.coding_off();
    std::vector<uint32_t> docs = {
        13,
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
    };
    pl_19.set(docs, freqs);
    inverted_index.push_back(pl_19);
  }
  {
    PostingList pl_20("accelerate", 1);
    pl_20.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_20.set(docs, freqs);
    inverted_index.push_back(pl_20);
  }
  {
    PostingList pl_21("achieve", 1);
    pl_21.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_21.set(docs, freqs);
    inverted_index.push_back(pl_21);
  }
  {
    PostingList pl_22("action", 1);
    pl_22.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_22.set(docs, freqs);
    inverted_index.push_back(pl_22);
  }
  {
    PostingList pl_23("actress", 1);
    pl_23.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_23.set(docs, freqs);
    inverted_index.push_back(pl_23);
  }
  {
    PostingList pl_24("adaptation", 3);
    pl_24.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        3,
    };
    pl_24.set(docs, freqs);
    inverted_index.push_back(pl_24);
  }
  {
    PostingList pl_25("after", 2);
    pl_25.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_25.set(docs, freqs);
    inverted_index.push_back(pl_25);
  }
  {
    PostingList pl_26("against", 2);
    pl_26.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_26.set(docs, freqs);
    inverted_index.push_back(pl_26);
  }
  {
    PostingList pl_27("age", 1);
    pl_27.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_27.set(docs, freqs);
    inverted_index.push_back(pl_27);
  }
  {
    PostingList pl_28("agenda", 1);
    pl_28.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_28.set(docs, freqs);
    inverted_index.push_back(pl_28);
  }
  {
    PostingList pl_29("agnostic", 3);
    pl_29.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        3,
    };
    pl_29.set(docs, freqs);
    inverted_index.push_back(pl_29);
  }
  {
    PostingList pl_30("ahead", 1);
    pl_30.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_30.set(docs, freqs);
    inverted_index.push_back(pl_30);
  }
  {
    PostingList pl_31("aim", 1);
    pl_31.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_31.set(docs, freqs);
    inverted_index.push_back(pl_31);
  }
  {
    PostingList pl_32("algorithm", 3);
    pl_32.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        3,
    };
    pl_32.set(docs, freqs);
    inverted_index.push_back(pl_32);
  }
  {
    PostingList pl_33("all", 1);
    pl_33.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_33.set(docs, freqs);
    inverted_index.push_back(pl_33);
  }
  {
    PostingList pl_34("also", 1);
    pl_34.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_34.set(docs, freqs);
    inverted_index.push_back(pl_34);
  }
  {
    PostingList pl_35("among", 1);
    pl_35.coding_off();
    std::vector<uint32_t> docs = {
        12,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_35.set(docs, freqs);
    inverted_index.push_back(pl_35);
  }
  {
    PostingList pl_36("amount", 1);
    pl_36.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_36.set(docs, freqs);
    inverted_index.push_back(pl_36);
  }
  {
    PostingList pl_37("an", 1);
    pl_37.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_37.set(docs, freqs);
    inverted_index.push_back(pl_37);
  }
  {
    PostingList pl_38("and", 26);
    pl_38.coding_off();
    std::vector<uint32_t> docs = {
        11, 12, 13, 15, 16,
    };
    std::vector<uint32_t> freqs = {
        12, 3, 3, 1, 7,
    };
    pl_38.set(docs, freqs);
    inverted_index.push_back(pl_38);
  }
  {
    PostingList pl_39("andpresent", 1);
    pl_39.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_39.set(docs, freqs);
    inverted_index.push_back(pl_39);
  }
  {
    PostingList pl_40("any", 2);
    pl_40.coding_off();
    std::vector<uint32_t> docs = {
        11,
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
    };
    pl_40.set(docs, freqs);
    inverted_index.push_back(pl_40);
  }
  {
    PostingList pl_41("anyway", 1);
    pl_41.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_41.set(docs, freqs);
    inverted_index.push_back(pl_41);
  }
  {
    PostingList pl_42("apple", 1);
    pl_42.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_42.set(docs, freqs);
    inverted_index.push_back(pl_42);
  }
  {
    PostingList pl_43("applicable", 1);
    pl_43.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_43.set(docs, freqs);
    inverted_index.push_back(pl_43);
  }
  {
    PostingList pl_44("application", 1);
    pl_44.coding_off();
    std::vector<uint32_t> docs = {
        12,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_44.set(docs, freqs);
    inverted_index.push_back(pl_44);
  }
  {
    PostingList pl_45("applied", 1);
    pl_45.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_45.set(docs, freqs);
    inverted_index.push_back(pl_45);
  }
  {
    PostingList pl_46("apply", 1);
    pl_46.coding_off();
    std::vector<uint32_t> docs = {
        12,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_46.set(docs, freqs);
    inverted_index.push_back(pl_46);
  }
  {
    PostingList pl_47("approach", 2);
    pl_47.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_47.set(docs, freqs);
    inverted_index.push_back(pl_47);
  }
  {
    PostingList pl_48("aproblem", 1);
    pl_48.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_48.set(docs, freqs);
    inverted_index.push_back(pl_48);
  }
  {
    PostingList pl_49("are", 5);
    pl_49.coding_off();
    std::vector<uint32_t> docs = {
        11,
        12,
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
        3,
        1,
    };
    pl_49.set(docs, freqs);
    inverted_index.push_back(pl_49);
  }
  {
    PostingList pl_50("argue", 1);
    pl_50.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_50.set(docs, freqs);
    inverted_index.push_back(pl_50);
  }
  {
    PostingList pl_51("art", 1);
    pl_51.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_51.set(docs, freqs);
    inverted_index.push_back(pl_51);
  }
  {
    PostingList pl_52("as", 5);
    pl_52.coding_off();
    std::vector<uint32_t> docs = {
        12,
        15,
        16,
    };
    std::vector<uint32_t> freqs = {
        3,
        1,
        1,
    };
    pl_52.set(docs, freqs);
    inverted_index.push_back(pl_52);
  }
  {
    PostingList pl_53("ask", 1);
    pl_53.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_53.set(docs, freqs);
    inverted_index.push_back(pl_53);
  }
  {
    PostingList pl_54("at", 2);
    pl_54.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_54.set(docs, freqs);
    inverted_index.push_back(pl_54);
  }
  {
    PostingList pl_55("attention", 1);
    pl_55.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_55.set(docs, freqs);
    inverted_index.push_back(pl_55);
  }
  {
    PostingList pl_56("basic", 1);
    pl_56.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_56.set(docs, freqs);
    inverted_index.push_back(pl_56);
  }
  {
    PostingList pl_57("bath", 1);
    pl_57.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_57.set(docs, freqs);
    inverted_index.push_back(pl_57);
  }
  {
    PostingList pl_58("bathtub", 1);
    pl_58.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_58.set(docs, freqs);
    inverted_index.push_back(pl_58);
  }
  {
    PostingList pl_59("be", 5);
    pl_59.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
        3,
    };
    pl_59.set(docs, freqs);
    inverted_index.push_back(pl_59);
  }
  {
    PostingList pl_60("because", 2);
    pl_60.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_60.set(docs, freqs);
    inverted_index.push_back(pl_60);
  }
  {
    PostingList pl_61("been", 1);
    pl_61.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_61.set(docs, freqs);
    inverted_index.push_back(pl_61);
  }
  {
    PostingList pl_62("beginning", 1);
    pl_62.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_62.set(docs, freqs);
    inverted_index.push_back(pl_62);
  }
  {
    PostingList pl_63("benchmark", 1);
    pl_63.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_63.set(docs, freqs);
    inverted_index.push_back(pl_63);
  }
  {
    PostingList pl_64("better", 1);
    pl_64.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_64.set(docs, freqs);
    inverted_index.push_back(pl_64);
  }
  {
    PostingList pl_65("bicameral", 1);
    pl_65.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_65.set(docs, freqs);
    inverted_index.push_back(pl_65);
  }
  {
    PostingList pl_66("bitmap", 1);
    pl_66.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_66.set(docs, freqs);
    inverted_index.push_back(pl_66);
  }
  {
    PostingList pl_67("black", 1);
    pl_67.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_67.set(docs, freqs);
    inverted_index.push_back(pl_67);
  }
  {
    PostingList pl_68("blazing", 1);
    pl_68.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_68.set(docs, freqs);
    inverted_index.push_back(pl_68);
  }
  {
    PostingList pl_69("blue", 1);
    pl_69.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_69.set(docs, freqs);
    inverted_index.push_back(pl_69);
  }
  {
    PostingList pl_70("bobbl", 1);
    pl_70.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_70.set(docs, freqs);
    inverted_index.push_back(pl_70);
  }
  {
    PostingList pl_71("book", 1);
    pl_71.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_71.set(docs, freqs);
    inverted_index.push_back(pl_71);
  }
  {
    PostingList pl_72("both", 1);
    pl_72.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_72.set(docs, freqs);
    inverted_index.push_back(pl_72);
  }
  {
    PostingList pl_73("brandish", 1);
    pl_73.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_73.set(docs, freqs);
    inverted_index.push_back(pl_73);
  }
  {
    PostingList pl_74("breakdown", 1);
    pl_74.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_74.set(docs, freqs);
    inverted_index.push_back(pl_74);
  }
  {
    PostingList pl_75("breathe", 1);
    pl_75.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_75.set(docs, freqs);
    inverted_index.push_back(pl_75);
  }
  {
    PostingList pl_76("bright", 2);
    pl_76.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_76.set(docs, freqs);
    inverted_index.push_back(pl_76);
  }
  {
    PostingList pl_77("broken", 1);
    pl_77.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_77.set(docs, freqs);
    inverted_index.push_back(pl_77);
  }
  {
    PostingList pl_78("burbclave", 2);
    pl_78.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_78.set(docs, freqs);
    inverted_index.push_back(pl_78);
  }
  {
    PostingList pl_79("burg", 1);
    pl_79.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_79.set(docs, freqs);
    inverted_index.push_back(pl_79);
  }
  {
    PostingList pl_80("but", 6);
    pl_80.coding_off();
    std::vector<uint32_t> docs = {
        11,
        16,
    };
    std::vector<uint32_t> freqs = {
        5,
        1,
    };
    pl_80.set(docs, freqs);
    inverted_index.push_back(pl_80);
  }
  {
    PostingList pl_81("by", 3);
    pl_81.coding_off();
    std::vector<uint32_t> docs = {
        11,
        16,
    };
    std::vector<uint32_t> freqs = {
        2,
        1,
    };
    pl_81.set(docs, freqs);
    inverted_index.push_back(pl_81);
  }
  {
    PostingList pl_82("call", 1);
    pl_82.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_82.set(docs, freqs);
    inverted_index.push_back(pl_82);
  }
  {
    PostingList pl_83("can", 7);
    pl_83.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
        16,
    };
    std::vector<uint32_t> freqs = {
        3,
        1,
        3,
    };
    pl_83.set(docs, freqs);
    inverted_index.push_back(pl_83);
  }
  {
    PostingList pl_84("cant", 1);
    pl_84.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_84.set(docs, freqs);
    inverted_index.push_back(pl_84);
  }
  {
    PostingList pl_85("car", 5);
    pl_85.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        2,
        3,
    };
    pl_85.set(docs, freqs);
    inverted_index.push_back(pl_85);
  }
  {
    PostingList pl_86("card", 1);
    pl_86.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_86.set(docs, freqs);
    inverted_index.push_back(pl_86);
  }
  {
    PostingList pl_87("case", 2);
    pl_87.coding_off();
    std::vector<uint32_t> docs = {
        11,
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
    };
    pl_87.set(docs, freqs);
    inverted_index.push_back(pl_87);
  }
  {
    PostingList pl_88("cayley", 1);
    pl_88.coding_off();
    std::vector<uint32_t> docs = {
        12,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_88.set(docs, freqs);
    inverted_index.push_back(pl_88);
  }
  {
    PostingList pl_89("center", 1);
    pl_89.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_89.set(docs, freqs);
    inverted_index.push_back(pl_89);
  }
  {
    PostingList pl_90("chapter", 1);
    pl_90.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_90.set(docs, freqs);
    inverted_index.push_back(pl_90);
  }
  {
    PostingList pl_91("circle", 1);
    pl_91.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_91.set(docs, freqs);
    inverted_index.push_back(pl_91);
  }
  {
    PostingList pl_92("clapboard", 1);
    pl_92.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_92.set(docs, freqs);
    inverted_index.push_back(pl_92);
  }
  {
    PostingList pl_93("class", 1);
    pl_93.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_93.set(docs, freqs);
    inverted_index.push_back(pl_93);
  }
  {
    PostingList pl_94("classification", 3);
    pl_94.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        3,
    };
    pl_94.set(docs, freqs);
    inverted_index.push_back(pl_94);
  }
  {
    PostingList pl_95("classify", 1);
    pl_95.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_95.set(docs, freqs);
    inverted_index.push_back(pl_95);
  }
  {
    PostingList pl_96("clock", 1);
    pl_96.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_96.set(docs, freqs);
    inverted_index.push_back(pl_96);
  }
  {
    PostingList pl_97("coming", 1);
    pl_97.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_97.set(docs, freqs);
    inverted_index.push_back(pl_97);
  }
  {
    PostingList pl_98("command", 1);
    pl_98.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_98.set(docs, freqs);
    inverted_index.push_back(pl_98);
  }
  {
    PostingList pl_99("compatible", 1);
    pl_99.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_99.set(docs, freqs);
    inverted_index.push_back(pl_99);
  }
  {
    PostingList pl_100("compete", 1);
    pl_100.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_100.set(docs, freqs);
    inverted_index.push_back(pl_100);
  }
  {
    PostingList pl_101("competition", 2);
    pl_101.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_101.set(docs, freqs);
    inverted_index.push_back(pl_101);
  }
  {
    PostingList pl_102("complex", 1);
    pl_102.coding_off();
    std::vector<uint32_t> docs = {
        12,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_102.set(docs, freqs);
    inverted_index.push_back(pl_102);
  }
  {
    PostingList pl_103("computer", 2);
    pl_103.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_103.set(docs, freqs);
    inverted_index.push_back(pl_103);
  }
  {
    PostingList pl_104("consciousness", 1);
    pl_104.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_104.set(docs, freqs);
    inverted_index.push_back(pl_104);
  }
  {
    PostingList pl_105("consider", 1);
    pl_105.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_105.set(docs, freqs);
    inverted_index.push_back(pl_105);
  }
  {
    PostingList pl_106("construction", 1);
    pl_106.coding_off();
    std::vector<uint32_t> docs = {
        12,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_106.set(docs, freqs);
    inverted_index.push_back(pl_106);
  }
  {
    PostingList pl_107("continuous", 1);
    pl_107.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_107.set(docs, freqs);
    inverted_index.push_back(pl_107);
  }
  {
    PostingList pl_108("cooperation", 2);
    pl_108.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_108.set(docs, freqs);
    inverted_index.push_back(pl_108);
  }
  {
    PostingList pl_109("corner", 1);
    pl_109.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_109.set(docs, freqs);
    inverted_index.push_back(pl_109);
  }
  {
    PostingList pl_110("corporate", 1);
    pl_110.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_110.set(docs, freqs);
    inverted_index.push_back(pl_110);
  }
  {
    PostingList pl_111("cosanostra", 2);
    pl_111.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_111.set(docs, freqs);
    inverted_index.push_back(pl_111);
  }
  {
    PostingList pl_112("country", 1);
    pl_112.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_112.set(docs, freqs);
    inverted_index.push_back(pl_112);
  }
  {
    PostingList pl_113("crap", 1);
    pl_113.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_113.set(docs, freqs);
    inverted_index.push_back(pl_113);
  }
  {
    PostingList pl_114("crash", 5);
    pl_114.coding_off();
    std::vector<uint32_t> docs = {
        11,
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
        4,
    };
    pl_114.set(docs, freqs);
    inverted_index.push_back(pl_114);
  }
  {
    PostingList pl_115("creative", 1);
    pl_115.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_115.set(docs, freqs);
    inverted_index.push_back(pl_115);
  }
  {
    PostingList pl_116("creativity", 1);
    pl_116.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_116.set(docs, freqs);
    inverted_index.push_back(pl_116);
  }
  {
    PostingList pl_117("d", 1);
    pl_117.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_117.set(docs, freqs);
    inverted_index.push_back(pl_117);
  }
  {
    PostingList pl_118("data", 2);
    pl_118.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_118.set(docs, freqs);
    inverted_index.push_back(pl_118);
  }
  {
    PostingList pl_119("datafrom", 1);
    pl_119.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_119.set(docs, freqs);
    inverted_index.push_back(pl_119);
  }
  {
    PostingList pl_120("datapointssample", 1);
    pl_120.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_120.set(docs, freqs);
    inverted_index.push_back(pl_120);
  }
  {
    PostingList pl_121("deep", 1);
    pl_121.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_121.set(docs, freqs);
    inverted_index.push_back(pl_121);
  }
  {
    PostingList pl_122("define", 1);
    pl_122.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_122.set(docs, freqs);
    inverted_index.push_back(pl_122);
  }
  {
    PostingList pl_123("deliver", 2);
    pl_123.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
    };
    pl_123.set(docs, freqs);
    inverted_index.push_back(pl_123);
  }
  {
    PostingList pl_124("deliverator", 9);
    pl_124.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        7,
        2,
    };
    pl_124.set(docs, freqs);
    inverted_index.push_back(pl_124);
  }
  {
    PostingList pl_125("delivery", 1);
    pl_125.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_125.set(docs, freqs);
    inverted_index.push_back(pl_125);
  }
  {
    PostingList pl_126("delvery", 1);
    pl_126.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_126.set(docs, freqs);
    inverted_index.push_back(pl_126);
  }
  {
    PostingList pl_127("demonstrate", 1);
    pl_127.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_127.set(docs, freqs);
    inverted_index.push_back(pl_127);
  }
  {
    PostingList pl_128("descent", 1);
    pl_128.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_128.set(docs, freqs);
    inverted_index.push_back(pl_128);
  }
  {
    PostingList pl_129("detail", 1);
    pl_129.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_129.set(docs, freqs);
    inverted_index.push_back(pl_129);
  }
  {
    PostingList pl_130("dickson", 1);
    pl_130.coding_off();
    std::vector<uint32_t> docs = {
        12,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_130.set(docs, freqs);
    inverted_index.push_back(pl_130);
  }
  {
    PostingList pl_131("differ", 1);
    pl_131.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_131.set(docs, freqs);
    inverted_index.push_back(pl_131);
  }
  {
    PostingList pl_132("different", 1);
    pl_132.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_132.set(docs, freqs);
    inverted_index.push_back(pl_132);
  }
  {
    PostingList pl_133("digit", 1);
    pl_133.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_133.set(docs, freqs);
    inverted_index.push_back(pl_133);
  }
  {
    PostingList pl_134("dinner", 1);
    pl_134.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_134.set(docs, freqs);
    inverted_index.push_back(pl_134);
  }
  {
    PostingList pl_135("discuss", 1);
    pl_135.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_135.set(docs, freqs);
    inverted_index.push_back(pl_135);
  }
  {
    PostingList pl_136("do", 3);
    pl_136.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        2,
        1,
    };
    pl_136.set(docs, freqs);
    inverted_index.push_back(pl_136);
  }
  {
    PostingList pl_137("doesnt", 2);
    pl_137.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
    };
    pl_137.set(docs, freqs);
    inverted_index.push_back(pl_137);
  }
  {
    PostingList pl_138("dollar", 1);
    pl_138.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_138.set(docs, freqs);
    inverted_index.push_back(pl_138);
  }
  {
    PostingList pl_139("domain", 2);
    pl_139.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_139.set(docs, freqs);
    inverted_index.push_back(pl_139);
  }
  {
    PostingList pl_140("dont", 1);
    pl_140.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_140.set(docs, freqs);
    inverted_index.push_back(pl_140);
  }
  {
    PostingList pl_141("doorway", 1);
    pl_141.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_141.set(docs, freqs);
    inverted_index.push_back(pl_141);
  }
  {
    PostingList pl_142("dork", 1);
    pl_142.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_142.set(docs, freqs);
    inverted_index.push_back(pl_142);
  }
  {
    PostingList pl_143("down", 3);
    pl_143.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        2,
        1,
    };
    pl_143.set(docs, freqs);
    inverted_index.push_back(pl_143);
  }
  {
    PostingList pl_144("dripping", 1);
    pl_144.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_144.set(docs, freqs);
    inverted_index.push_back(pl_144);
  }
  {
    PostingList pl_145("drive", 1);
    pl_145.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_145.set(docs, freqs);
    inverted_index.push_back(pl_145);
  }
  {
    PostingList pl_146("driver", 3);
    pl_146.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        3,
    };
    pl_146.set(docs, freqs);
    inverted_index.push_back(pl_146);
  }
  {
    PostingList pl_147("driveway", 1);
    pl_147.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_147.set(docs, freqs);
    inverted_index.push_back(pl_147);
  }
  {
    PostingList pl_148("early", 1);
    pl_148.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_148.set(docs, freqs);
    inverted_index.push_back(pl_148);
  }
  {
    PostingList pl_149("easy", 1);
    pl_149.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_149.set(docs, freqs);
    inverted_index.push_back(pl_149);
  }
  {
    PostingList pl_150("education", 1);
    pl_150.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_150.set(docs, freqs);
    inverted_index.push_back(pl_150);
  }
  {
    PostingList pl_151("effect", 1);
    pl_151.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_151.set(docs, freqs);
    inverted_index.push_back(pl_151);
  }
  {
    PostingList pl_152("eight", 8);
    pl_152.coding_off();
    std::vector<uint32_t> docs = {
        8,
    };
    std::vector<uint32_t> freqs = {
        8,
    };
    pl_152.set(docs, freqs);
    inverted_index.push_back(pl_152);
  }
  {
    PostingList pl_153("either", 1);
    pl_153.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_153.set(docs, freqs);
    inverted_index.push_back(pl_153);
  }
  {
    PostingList pl_154("elementary", 1);
    pl_154.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_154.set(docs, freqs);
    inverted_index.push_back(pl_154);
  }
  {
    PostingList pl_155("enzo", 3);
    pl_155.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        2,
        1,
    };
    pl_155.set(docs, freqs);
    inverted_index.push_back(pl_155);
  }
  {
    PostingList pl_156("essay", 1);
    pl_156.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_156.set(docs, freqs);
    inverted_index.push_back(pl_156);
  }
  {
    PostingList pl_157("ethic", 1);
    pl_157.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_157.set(docs, freqs);
    inverted_index.push_back(pl_157);
  }
  {
    PostingList pl_158("even", 1);
    pl_158.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_158.set(docs, freqs);
    inverted_index.push_back(pl_158);
  }
  {
    PostingList pl_159("evening", 1);
    pl_159.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_159.set(docs, freqs);
    inverted_index.push_back(pl_159);
  }
  {
    PostingList pl_160("everything", 1);
    pl_160.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_160.set(docs, freqs);
    inverted_index.push_back(pl_160);
  }
  {
    PostingList pl_161("ex", 1);
    pl_161.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_161.set(docs, freqs);
    inverted_index.push_back(pl_161);
  }
  {
    PostingList pl_162("example", 2);
    pl_162.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_162.set(docs, freqs);
    inverted_index.push_back(pl_162);
  }
  {
    PostingList pl_163("exceptional", 2);
    pl_163.coding_off();
    std::vector<uint32_t> docs = {
        12,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_163.set(docs, freqs);
    inverted_index.push_back(pl_163);
  }
  {
    PostingList pl_164("excerpt", 1);
    pl_164.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_164.set(docs, freqs);
    inverted_index.push_back(pl_164);
  }
  {
    PostingList pl_165("expectancy", 1);
    pl_165.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_165.set(docs, freqs);
    inverted_index.push_back(pl_165);
  }
  {
    PostingList pl_166("explain", 1);
    pl_166.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_166.set(docs, freqs);
    inverted_index.push_back(pl_166);
  }
  {
    PostingList pl_167("explicit", 1);
    pl_167.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_167.set(docs, freqs);
    inverted_index.push_back(pl_167);
  }
  {
    PostingList pl_168("face", 1);
    pl_168.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_168.set(docs, freqs);
    inverted_index.push_back(pl_168);
  }
  {
    PostingList pl_169("failure", 1);
    pl_169.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_169.set(docs, freqs);
    inverted_index.push_back(pl_169);
  }
  {
    PostingList pl_170("family", 3);
    pl_170.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        3,
    };
    pl_170.set(docs, freqs);
    inverted_index.push_back(pl_170);
  }
  {
    PostingList pl_171("fast", 2);
    pl_171.coding_off();
    std::vector<uint32_t> docs = {
        11,
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
    };
    pl_171.set(docs, freqs);
    inverted_index.push_back(pl_171);
  }
  {
    PostingList pl_172("feel", 1);
    pl_172.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_172.set(docs, freqs);
    inverted_index.push_back(pl_172);
  }
  {
    PostingList pl_173("feet", 1);
    pl_173.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_173.set(docs, freqs);
    inverted_index.push_back(pl_173);
  }
  {
    PostingList pl_174("few", 8);
    pl_174.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        8,
    };
    pl_174.set(docs, freqs);
    inverted_index.push_back(pl_174);
  }
  {
    PostingList pl_175("field", 1);
    pl_175.coding_off();
    std::vector<uint32_t> docs = {
        12,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_175.set(docs, freqs);
    inverted_index.push_back(pl_175);
  }
  {
    PostingList pl_176("fifty", 1);
    pl_176.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_176.set(docs, freqs);
    inverted_index.push_back(pl_176);
  }
  {
    PostingList pl_177("file", 1);
    pl_177.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_177.set(docs, freqs);
    inverted_index.push_back(pl_177);
  }
  {
    PostingList pl_178("fine", 2);
    pl_178.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_178.set(docs, freqs);
    inverted_index.push_back(pl_178);
  }
  {
    PostingList pl_179("five", 6);
    pl_179.coding_off();
    std::vector<uint32_t> docs = {
        5,
        13,
    };
    std::vector<uint32_t> freqs = {
        5,
        1,
    };
    pl_179.set(docs, freqs);
    inverted_index.push_back(pl_179);
  }
  {
    PostingList pl_180("flipper", 1);
    pl_180.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_180.set(docs, freqs);
    inverted_index.push_back(pl_180);
  }
  {
    PostingList pl_181("for", 11);
    pl_181.coding_off();
    std::vector<uint32_t> docs = {
        11,
        15,
        16,
    };
    std::vector<uint32_t> freqs = {
        3,
        1,
        7,
    };
    pl_181.set(docs, freqs);
    inverted_index.push_back(pl_181);
  }
  {
    PostingList pl_182("force", 1);
    pl_182.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_182.set(docs, freqs);
    inverted_index.push_back(pl_182);
  }
  {
    PostingList pl_183("form", 2);
    pl_183.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_183.set(docs, freqs);
    inverted_index.push_back(pl_183);
  }
  {
    PostingList pl_184("formalize", 1);
    pl_184.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_184.set(docs, freqs);
    inverted_index.push_back(pl_184);
  }
  {
    PostingList pl_185("four", 6);
    pl_185.coding_off();
    std::vector<uint32_t> docs = {
        4,
        12,
    };
    std::vector<uint32_t> freqs = {
        4,
        2,
    };
    pl_185.set(docs, freqs);
    inverted_index.push_back(pl_185);
  }
  {
    PostingList pl_186("free", 1);
    pl_186.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_186.set(docs, freqs);
    inverted_index.push_back(pl_186);
  }
  {
    PostingList pl_187("from", 4);
    pl_187.coding_off();
    std::vector<uint32_t> docs = {
        11,
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
        3,
    };
    pl_187.set(docs, freqs);
    inverted_index.push_back(pl_187);
  }
  {
    PostingList pl_188("fromon", 1);
    pl_188.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_188.set(docs, freqs);
    inverted_index.push_back(pl_188);
  }
  {
    PostingList pl_189("front", 2);
    pl_189.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
    };
    pl_189.set(docs, freqs);
    inverted_index.push_back(pl_189);
  }
  {
    PostingList pl_190("fucking", 3);
    pl_190.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        2,
        1,
    };
    pl_190.set(docs, freqs);
    inverted_index.push_back(pl_190);
  }
  {
    PostingList pl_191("function", 4);
    pl_191.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        4,
    };
    pl_191.set(docs, freqs);
    inverted_index.push_back(pl_191);
  }
  {
    PostingList pl_192("garage", 1);
    pl_192.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_192.set(docs, freqs);
    inverted_index.push_back(pl_192);
  }
  {
    PostingList pl_193("general", 1);
    pl_193.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_193.set(docs, freqs);
    inverted_index.push_back(pl_193);
  }
  {
    PostingList pl_194("generalization", 1);
    pl_194.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_194.set(docs, freqs);
    inverted_index.push_back(pl_194);
  }
  {
    PostingList pl_195("generate", 1);
    pl_195.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_195.set(docs, freqs);
    inverted_index.push_back(pl_195);
  }
  {
    PostingList pl_196("get", 2);
    pl_196.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
    };
    pl_196.set(docs, freqs);
    inverted_index.push_back(pl_196);
  }
  {
    PostingList pl_197("gibberish", 1);
    pl_197.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_197.set(docs, freqs);
    inverted_index.push_back(pl_197);
  }
  {
    PostingList pl_198("glint", 1);
    pl_198.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_198.set(docs, freqs);
    inverted_index.push_back(pl_198);
  }
  {
    PostingList pl_199("glowing", 1);
    pl_199.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_199.set(docs, freqs);
    inverted_index.push_back(pl_199);
  }
  {
    PostingList pl_200("go", 2);
    pl_200.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
    };
    pl_200.set(docs, freqs);
    inverted_index.push_back(pl_200);
  }
  {
    PostingList pl_201("goal", 3);
    pl_201.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        3,
    };
    pl_201.set(docs, freqs);
    inverted_index.push_back(pl_201);
  }
  {
    PostingList pl_202("goalmight", 1);
    pl_202.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_202.set(docs, freqs);
    inverted_index.push_back(pl_202);
  }
  {
    PostingList pl_203("god", 1);
    pl_203.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_203.set(docs, freqs);
    inverted_index.push_back(pl_203);
  }
  {
    PostingList pl_204("golf", 1);
    pl_204.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_204.set(docs, freqs);
    inverted_index.push_back(pl_204);
  }
  {
    PostingList pl_205("good", 2);
    pl_205.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_205.set(docs, freqs);
    inverted_index.push_back(pl_205);
  }
  {
    PostingList pl_206("got", 1);
    pl_206.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_206.set(docs, freqs);
    inverted_index.push_back(pl_206);
  }
  {
    PostingList pl_207("gradient", 3);
    pl_207.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        3,
    };
    pl_207.set(docs, freqs);
    inverted_index.push_back(pl_207);
  }
  {
    PostingList pl_208("granddaughter", 2);
    pl_208.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
    };
    pl_208.set(docs, freqs);
    inverted_index.push_back(pl_208);
  }
  {
    PostingList pl_209("grim", 1);
    pl_209.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_209.set(docs, freqs);
    inverted_index.push_back(pl_209);
  }
  {
    PostingList pl_210("group", 1);
    pl_210.coding_off();
    std::vector<uint32_t> docs = {
        12,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_210.set(docs, freqs);
    inverted_index.push_back(pl_210);
  }
  {
    PostingList pl_211("grovel", 1);
    pl_211.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_211.set(docs, freqs);
    inverted_index.push_back(pl_211);
  }
  {
    PostingList pl_212("guy", 1);
    pl_212.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_212.set(docs, freqs);
    inverted_index.push_back(pl_212);
  }
  {
    PostingList pl_213("had", 1);
    pl_213.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_213.set(docs, freqs);
    inverted_index.push_back(pl_213);
  }
  {
    PostingList pl_214("happen", 2);
    pl_214.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_214.set(docs, freqs);
    inverted_index.push_back(pl_214);
  }
  {
    PostingList pl_215("hard", 3);
    pl_215.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        3,
    };
    pl_215.set(docs, freqs);
    inverted_index.push_back(pl_215);
  }
  {
    PostingList pl_216("has", 8);
    pl_216.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
        15,
    };
    std::vector<uint32_t> freqs = {
        5,
        2,
        1,
    };
    pl_216.set(docs, freqs);
    inverted_index.push_back(pl_216);
  }
  {
    PostingList pl_217("hasprevious", 1);
    pl_217.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_217.set(docs, freqs);
    inverted_index.push_back(pl_217);
  }
  {
    PostingList pl_218("have", 6);
    pl_218.coding_off();
    std::vector<uint32_t> docs = {
        11,
        12,
        13,
    };
    std::vector<uint32_t> freqs = {
        4,
        1,
        1,
    };
    pl_218.set(docs, freqs);
    inverted_index.push_back(pl_218);
  }
  {
    PostingList pl_219("he", 8);
    pl_219.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        3,
        5,
    };
    pl_219.set(docs, freqs);
    inverted_index.push_back(pl_219);
  }
  {
    PostingList pl_220("heard", 2);
    pl_220.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
    };
    pl_220.set(docs, freqs);
    inverted_index.push_back(pl_220);
  }
  {
    PostingList pl_221("high", 1);
    pl_221.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_221.set(docs, freqs);
    inverted_index.push_back(pl_221);
  }
  {
    PostingList pl_222("hiro", 1);
    pl_222.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_222.set(docs, freqs);
    inverted_index.push_back(pl_222);
  }
  {
    PostingList pl_223("his", 13);
    pl_223.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
        15,
    };
    std::vector<uint32_t> freqs = {
        7,
        4,
        2,
    };
    pl_223.set(docs, freqs);
    inverted_index.push_back(pl_223);
  }
  {
    PostingList pl_224("home", 1);
    pl_224.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_224.set(docs, freqs);
    inverted_index.push_back(pl_224);
  }
  {
    PostingList pl_225("homeowner", 1);
    pl_225.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_225.set(docs, freqs);
    inverted_index.push_back(pl_225);
  }
  {
    PostingList pl_226("honor", 1);
    pl_226.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_226.set(docs, freqs);
    inverted_index.push_back(pl_226);
  }
  {
    PostingList pl_227("hope", 1);
    pl_227.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_227.set(docs, freqs);
    inverted_index.push_back(pl_227);
  }
  {
    PostingList pl_228("hour", 2);
    pl_228.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
    };
    pl_228.set(docs, freqs);
    inverted_index.push_back(pl_228);
  }
  {
    PostingList pl_229("house", 1);
    pl_229.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_229.set(docs, freqs);
    inverted_index.push_back(pl_229);
  }
  {
    PostingList pl_230("how", 2);
    pl_230.coding_off();
    std::vector<uint32_t> docs = {
        11,
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
    };
    pl_230.set(docs, freqs);
    inverted_index.push_back(pl_230);
  }
  {
    PostingList pl_231("hurry", 1);
    pl_231.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_231.set(docs, freqs);
    inverted_index.push_back(pl_231);
  }
  {
    PostingList pl_232("i", 1);
    pl_232.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_232.set(docs, freqs);
    inverted_index.push_back(pl_232);
  }
  {
    PostingList pl_233("idea", 1);
    pl_233.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_233.set(docs, freqs);
    inverted_index.push_back(pl_233);
  }
  {
    PostingList pl_234("identical", 1);
    pl_234.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_234.set(docs, freqs);
    inverted_index.push_back(pl_234);
  }
  {
    PostingList pl_235("if", 2);
    pl_235.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_235.set(docs, freqs);
    inverted_index.push_back(pl_235);
  }
  {
    PostingList pl_236("image", 2);
    pl_236.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_236.set(docs, freqs);
    inverted_index.push_back(pl_236);
  }
  {
    PostingList pl_237("in", 29);
    pl_237.coding_off();
    std::vector<uint32_t> docs = {
        11, 12, 13, 15, 16,
    };
    std::vector<uint32_t> freqs = {
        10, 2, 4, 3, 10,
    };
    pl_237.set(docs, freqs);
    inverted_index.push_back(pl_237);
  }
  {
    PostingList pl_238("including", 1);
    pl_238.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_238.set(docs, freqs);
    inverted_index.push_back(pl_238);
  }
  {
    PostingList pl_239("influence", 1);
    pl_239.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_239.set(docs, freqs);
    inverted_index.push_back(pl_239);
  }
  {
    PostingList pl_240("ing", 1);
    pl_240.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_240.set(docs, freqs);
    inverted_index.push_back(pl_240);
  }
  {
    PostingList pl_241("innumerable", 1);
    pl_241.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_241.set(docs, freqs);
    inverted_index.push_back(pl_241);
  }
  {
    PostingList pl_242("input", 1);
    pl_242.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_242.set(docs, freqs);
    inverted_index.push_back(pl_242);
  }
  {
    PostingList pl_243("instantiation", 1);
    pl_243.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_243.set(docs, freqs);
    inverted_index.push_back(pl_243);
  }
  {
    PostingList pl_244("interrupt", 1);
    pl_244.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_244.set(docs, freqs);
    inverted_index.push_back(pl_244);
  }
  {
    PostingList pl_245("into", 5);
    pl_245.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
        3,
        1,
    };
    pl_245.set(docs, freqs);
    inverted_index.push_back(pl_245);
  }
  {
    PostingList pl_246("involved", 1);
    pl_246.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_246.set(docs, freqs);
    inverted_index.push_back(pl_246);
  }
  {
    PostingList pl_247("iove", 1);
    pl_247.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_247.set(docs, freqs);
    inverted_index.push_back(pl_247);
  }
  {
    PostingList pl_248("is", 15);
    pl_248.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
        16,
    };
    std::vector<uint32_t> freqs = {
        5,
        2,
        8,
    };
    pl_248.set(docs, freqs);
    inverted_index.push_back(pl_248);
  }
  {
    PostingList pl_249("it", 10);
    pl_249.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
        16,
    };
    std::vector<uint32_t> freqs = {
        4,
        4,
        2,
    };
    pl_249.set(docs, freqs);
    inverted_index.push_back(pl_249);
  }
  {
    PostingList pl_250("jayne", 1);
    pl_250.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_250.set(docs, freqs);
    inverted_index.push_back(pl_250);
  }
  {
    PostingList pl_251("job", 3);
    pl_251.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        3,
    };
    pl_251.set(docs, freqs);
    inverted_index.push_back(pl_251);
  }
  {
    PostingList pl_252("julian", 1);
    pl_252.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_252.set(docs, freqs);
    inverted_index.push_back(pl_252);
  }
  {
    PostingList pl_253("just", 2);
    pl_253.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_253.set(docs, freqs);
    inverted_index.push_back(pl_253);
  }
  {
    PostingList pl_254("kind", 1);
    pl_254.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_254.set(docs, freqs);
    inverted_index.push_back(pl_254);
  }
  {
    PostingList pl_255("kiss", 1);
    pl_255.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_255.set(docs, freqs);
    inverted_index.push_back(pl_255);
  }
  {
    PostingList pl_256("kitchen", 1);
    pl_256.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_256.set(docs, freqs);
    inverted_index.push_back(pl_256);
  }
  {
    PostingList pl_257("know", 1);
    pl_257.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_257.set(docs, freqs);
    inverted_index.push_back(pl_257);
  }
  {
    PostingList pl_258("known", 1);
    pl_258.coding_off();
    std::vector<uint32_t> docs = {
        12,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_258.set(docs, freqs);
    inverted_index.push_back(pl_258);
  }
  {
    PostingList pl_259("kourier", 2);
    pl_259.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_259.set(docs, freqs);
    inverted_index.push_back(pl_259);
  }
  {
    PostingList pl_260("late", 1);
    pl_260.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_260.set(docs, freqs);
    inverted_index.push_back(pl_260);
  }
  {
    PostingList pl_261("lax", 1);
    pl_261.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_261.set(docs, freqs);
    inverted_index.push_back(pl_261);
  }
  {
    PostingList pl_262("leads", 1);
    pl_262.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_262.set(docs, freqs);
    inverted_index.push_back(pl_262);
  }
  {
    PostingList pl_263("learn", 2);
    pl_263.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_263.set(docs, freqs);
    inverted_index.push_back(pl_263);
  }
  {
    PostingList pl_264("learning", 14);
    pl_264.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        14,
    };
    pl_264.set(docs, freqs);
    inverted_index.push_back(pl_264);
  }
  {
    PostingList pl_265("led", 1);
    pl_265.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_265.set(docs, freqs);
    inverted_index.push_back(pl_265);
  }
  {
    PostingList pl_266("lengthy", 1);
    pl_266.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_266.set(docs, freqs);
    inverted_index.push_back(pl_266);
  }
  {
    PostingList pl_267("lie", 3);
    pl_267.coding_off();
    std::vector<uint32_t> docs = {
        11,
        12,
    };
    std::vector<uint32_t> freqs = {
        2,
        1,
    };
    pl_267.set(docs, freqs);
    inverted_index.push_back(pl_267);
  }
  {
    PostingList pl_268("life", 4);
    pl_268.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        4,
    };
    pl_268.set(docs, freqs);
    inverted_index.push_back(pl_268);
  }
  {
    PostingList pl_269("light", 1);
    pl_269.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_269.set(docs, freqs);
    inverted_index.push_back(pl_269);
  }
  {
    PostingList pl_270("like", 1);
    pl_270.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_270.set(docs, freqs);
    inverted_index.push_back(pl_270);
  }
  {
    PostingList pl_271("likewise", 1);
    pl_271.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_271.set(docs, freqs);
    inverted_index.push_back(pl_271);
  }
  {
    PostingList pl_272("line", 2);
    pl_272.coding_off();
    std::vector<uint32_t> docs = {
        11,
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
    };
    pl_272.set(docs, freqs);
    inverted_index.push_back(pl_272);
  }
  {
    PostingList pl_273("little", 1);
    pl_273.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_273.set(docs, freqs);
    inverted_index.push_back(pl_273);
  }
  {
    PostingList pl_274("logic", 1);
    pl_274.coding_off();
    std::vector<uint32_t> docs = {
        12,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_274.set(docs, freqs);
    inverted_index.push_back(pl_274);
  }
  {
    PostingList pl_275("long", 2);
    pl_275.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_275.set(docs, freqs);
    inverted_index.push_back(pl_275);
  }
  {
    PostingList pl_276("look", 1);
    pl_276.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_276.set(docs, freqs);
    inverted_index.push_back(pl_276);
  }
  {
    PostingList pl_277("lossfunction", 1);
    pl_277.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_277.set(docs, freqs);
    inverted_index.push_back(pl_277);
  }
  {
    PostingList pl_278("lost", 1);
    pl_278.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_278.set(docs, freqs);
    inverted_index.push_back(pl_278);
  }
  {
    PostingList pl_279("macintosh", 2);
    pl_279.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_279.set(docs, freqs);
    inverted_index.push_back(pl_279);
  }
  {
    PostingList pl_280("mafia", 1);
    pl_280.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_280.set(docs, freqs);
    inverted_index.push_back(pl_280);
  }
  {
    PostingList pl_281("main", 1);
    pl_281.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_281.set(docs, freqs);
    inverted_index.push_back(pl_281);
  }
  {
    PostingList pl_282("make", 3);
    pl_282.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        2,
        1,
    };
    pl_282.set(docs, freqs);
    inverted_index.push_back(pl_282);
  }
  {
    PostingList pl_283("making", 1);
    pl_283.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_283.set(docs, freqs);
    inverted_index.push_back(pl_283);
  }
  {
    PostingList pl_284("maml", 1);
    pl_284.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_284.set(docs, freqs);
    inverted_index.push_back(pl_284);
  }
  {
    PostingList pl_285("many", 3);
    pl_285.coding_off();
    std::vector<uint32_t> docs = {
        11,
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
        2,
    };
    pl_285.set(docs, freqs);
    inverted_index.push_back(pl_285);
  }
  {
    PostingList pl_286("march", 1);
    pl_286.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_286.set(docs, freqs);
    inverted_index.push_back(pl_286);
  }
  {
    PostingList pl_287("mathematics", 1);
    pl_287.coding_off();
    std::vector<uint32_t> docs = {
        12,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_287.set(docs, freqs);
    inverted_index.push_back(pl_287);
  }
  {
    PostingList pl_288("maybe", 2);
    pl_288.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_288.set(docs, freqs);
    inverted_index.push_back(pl_288);
  }
  {
    PostingList pl_289("meaning", 1);
    pl_289.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_289.set(docs, freqs);
    inverted_index.push_back(pl_289);
  }
  {
    PostingList pl_290("mecha", 1);
    pl_290.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_290.set(docs, freqs);
    inverted_index.push_back(pl_290);
  }
  {
    PostingList pl_291("mellow", 1);
    pl_291.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_291.set(docs, freqs);
    inverted_index.push_back(pl_291);
  }
  {
    PostingList pl_292("mention", 1);
    pl_292.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_292.set(docs, freqs);
    inverted_index.push_back(pl_292);
  }
  {
    PostingList pl_293("meta", 6);
    pl_293.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        6,
    };
    pl_293.set(docs, freqs);
    inverted_index.push_back(pl_293);
  }
  {
    PostingList pl_294("method", 1);
    pl_294.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_294.set(docs, freqs);
    inverted_index.push_back(pl_294);
  }
  {
    PostingList pl_295("microcode", 1);
    pl_295.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_295.set(docs, freqs);
    inverted_index.push_back(pl_295);
  }
  {
    PostingList pl_296("might", 1);
    pl_296.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_296.set(docs, freqs);
    inverted_index.push_back(pl_296);
  }
  {
    PostingList pl_297("mind", 2);
    pl_297.coding_off();
    std::vector<uint32_t> docs = {
        13,
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
    };
    pl_297.set(docs, freqs);
    inverted_index.push_back(pl_297);
  }
  {
    PostingList pl_298("minutes", 4);
    pl_298.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        3,
        1,
    };
    pl_298.set(docs, freqs);
    inverted_index.push_back(pl_298);
  }
  {
    PostingList pl_299("mode", 1);
    pl_299.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_299.set(docs, freqs);
    inverted_index.push_back(pl_299);
  }
  {
    PostingList pl_300("model", 10);
    pl_300.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        10,
    };
    pl_300.set(docs, freqs);
    inverted_index.push_back(pl_300);
  }
  {
    PostingList pl_301("month", 1);
    pl_301.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_301.set(docs, freqs);
    inverted_index.push_back(pl_301);
  }
  {
    PostingList pl_302("more", 3);
    pl_302.coding_off();
    std::vector<uint32_t> docs = {
        11,
        12,
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
        1,
    };
    pl_302.set(docs, freqs);
    inverted_index.push_back(pl_302);
  }
  {
    PostingList pl_303("most", 2);
    pl_303.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_303.set(docs, freqs);
    inverted_index.push_back(pl_303);
  }
  {
    PostingList pl_304("move", 2);
    pl_304.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
    };
    pl_304.set(docs, freqs);
    inverted_index.push_back(pl_304);
  }
  {
    PostingList pl_305("movies", 1);
    pl_305.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_305.set(docs, freqs);
    inverted_index.push_back(pl_305);
  }
  {
    PostingList pl_306("much", 1);
    pl_306.coding_off();
    std::vector<uint32_t> docs = {
        12,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_306.set(docs, freqs);
    inverted_index.push_back(pl_306);
  }
  {
    PostingList pl_307("music", 1);
    pl_307.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_307.set(docs, freqs);
    inverted_index.push_back(pl_307);
  }
  {
    PostingList pl_308("must", 1);
    pl_308.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_308.set(docs, freqs);
    inverted_index.push_back(pl_308);
  }
  {
    PostingList pl_309("n", 1);
    pl_309.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_309.set(docs, freqs);
    inverted_index.push_back(pl_309);
  }
  {
    PostingList pl_310("name", 1);
    pl_310.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_310.set(docs, freqs);
    inverted_index.push_back(pl_310);
  }
  {
    PostingList pl_311("natural", 1);
    pl_311.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_311.set(docs, freqs);
    inverted_index.push_back(pl_311);
  }
  {
    PostingList pl_312("neal", 1);
    pl_312.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_312.set(docs, freqs);
    inverted_index.push_back(pl_312);
  }
  {
    PostingList pl_313("needs", 1);
    pl_313.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_313.set(docs, freqs);
    inverted_index.push_back(pl_313);
  }
  {
    PostingList pl_314("network", 2);
    pl_314.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_314.set(docs, freqs);
    inverted_index.push_back(pl_314);
  }
  {
    PostingList pl_315("neural", 1);
    pl_315.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_315.set(docs, freqs);
    inverted_index.push_back(pl_315);
  }
  {
    PostingList pl_316("never", 1);
    pl_316.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_316.set(docs, freqs);
    inverted_index.push_back(pl_316);
  }
  {
    PostingList pl_317("new", 3);
    pl_317.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        3,
    };
    pl_317.set(docs, freqs);
    inverted_index.push_back(pl_317);
  }
  {
    PostingList pl_318("next", 1);
    pl_318.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_318.set(docs, freqs);
    inverted_index.push_back(pl_318);
  }
  {
    PostingList pl_319("night", 1);
    pl_319.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_319.set(docs, freqs);
    inverted_index.push_back(pl_319);
  }
  {
    PostingList pl_320("nine", 9);
    pl_320.coding_off();
    std::vector<uint32_t> docs = {
        9,
    };
    std::vector<uint32_t> freqs = {
        9,
    };
    pl_320.set(docs, freqs);
    inverted_index.push_back(pl_320);
  }
  {
    PostingList pl_321("ninja", 1);
    pl_321.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_321.set(docs, freqs);
    inverted_index.push_back(pl_321);
  }
  {
    PostingList pl_322("no", 3);
    pl_322.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        2,
        1,
    };
    pl_322.set(docs, freqs);
    inverted_index.push_back(pl_322);
  }
  {
    PostingList pl_323("nobody", 1);
    pl_323.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_323.set(docs, freqs);
    inverted_index.push_back(pl_323);
  }
  {
    PostingList pl_324("not", 5);
    pl_324.coding_off();
    std::vector<uint32_t> docs = {
        11,
        12,
        13,
    };
    std::vector<uint32_t> freqs = {
        3,
        1,
        1,
    };
    pl_324.set(docs, freqs);
    inverted_index.push_back(pl_324);
  }
  {
    PostingList pl_325("novel", 1);
    pl_325.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_325.set(docs, freqs);
    inverted_index.push_back(pl_325);
  }
  {
    PostingList pl_326("now", 3);
    pl_326.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
        2,
    };
    pl_326.set(docs, freqs);
    inverted_index.push_back(pl_326);
  }
  {
    PostingList pl_327("npponese", 1);
    pl_327.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_327.set(docs, freqs);
    inverted_index.push_back(pl_327);
  }
  {
    PostingList pl_328("number", 2);
    pl_328.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_328.set(docs, freqs);
    inverted_index.push_back(pl_328);
  }
  {
    PostingList pl_329("numbers", 2);
    pl_329.coding_off();
    std::vector<uint32_t> docs = {
        11,
        12,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
    };
    pl_329.set(docs, freqs);
    inverted_index.push_back(pl_329);
  }
  {
    PostingList pl_330("object", 1);
    pl_330.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_330.set(docs, freqs);
    inverted_index.push_back(pl_330);
  }
  {
    PostingList pl_331("obstreperous", 1);
    pl_331.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_331.set(docs, freqs);
    inverted_index.push_back(pl_331);
  }
  {
    PostingList pl_332("occasional", 1);
    pl_332.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_332.set(docs, freqs);
    inverted_index.push_back(pl_332);
  }
  {
    PostingList pl_333("octonion", 4);
    pl_333.coding_off();
    std::vector<uint32_t> docs = {
        12,
    };
    std::vector<uint32_t> freqs = {
        4,
    };
    pl_333.set(docs, freqs);
    inverted_index.push_back(pl_333);
  }
  {
    PostingList pl_334("of", 34);
    pl_334.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
        15,
        16,
    };
    std::vector<uint32_t> freqs = {
        6,
        7,
        4,
        17,
    };
    pl_334.set(docs, freqs);
    inverted_index.push_back(pl_334);
  }
  {
    PostingList pl_335("ofa", 1);
    pl_335.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_335.set(docs, freqs);
    inverted_index.push_back(pl_335);
  }
  {
    PostingList pl_336("off", 1);
    pl_336.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_336.set(docs, freqs);
    inverted_index.push_back(pl_336);
  }
  {
    PostingList pl_337("often", 1);
    pl_337.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_337.set(docs, freqs);
    inverted_index.push_back(pl_337);
  }
  {
    PostingList pl_338("oh", 2);
    pl_338.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_338.set(docs, freqs);
    inverted_index.push_back(pl_338);
  }
  {
    PostingList pl_339("old", 2);
    pl_339.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_339.set(docs, freqs);
    inverted_index.push_back(pl_339);
  }
  {
    PostingList pl_340("on", 13);
    pl_340.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
        15,
        16,
    };
    std::vector<uint32_t> freqs = {
        3,
        2,
        3,
        5,
    };
    pl_340.set(docs, freqs);
    inverted_index.push_back(pl_340);
  }
  {
    PostingList pl_341("one", 9);
    pl_341.coding_off();
    std::vector<uint32_t> docs = {
        1, 11, 12, 13, 15,
    };
    std::vector<uint32_t> freqs = {
        1, 2, 2, 3, 1,
    };
    pl_341.set(docs, freqs);
    inverted_index.push_back(pl_341);
  }
  {
    PostingList pl_342("only", 2);
    pl_342.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_342.set(docs, freqs);
    inverted_index.push_back(pl_342);
  }
  {
    PostingList pl_343("onlyone", 1);
    pl_343.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_343.set(docs, freqs);
    inverted_index.push_back(pl_343);
  }
  {
    PostingList pl_344("operation", 1);
    pl_344.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_344.set(docs, freqs);
    inverted_index.push_back(pl_344);
  }
  {
    PostingList pl_345("or", 8);
    pl_345.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
        16,
    };
    std::vector<uint32_t> freqs = {
        4,
        3,
        1,
    };
    pl_345.set(docs, freqs);
    inverted_index.push_back(pl_345);
  }
  {
    PostingList pl_346("order", 1);
    pl_346.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_346.set(docs, freqs);
    inverted_index.push_back(pl_346);
  }
  {
    PostingList pl_347("origin", 1);
    pl_347.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_347.set(docs, freqs);
    inverted_index.push_back(pl_347);
  }
  {
    PostingList pl_348("other", 2);
    pl_348.coding_off();
    std::vector<uint32_t> docs = {
        11,
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
    };
    pl_348.set(docs, freqs);
    inverted_index.push_back(pl_348);
  }
  {
    PostingList pl_349("our", 4);
    pl_349.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        4,
    };
    pl_349.set(docs, freqs);
    inverted_index.push_back(pl_349);
  }
  {
    PostingList pl_350("out", 2);
    pl_350.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
    };
    pl_350.set(docs, freqs);
    inverted_index.push_back(pl_350);
  }
  {
    PostingList pl_351("output", 2);
    pl_351.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_351.set(docs, freqs);
    inverted_index.push_back(pl_351);
  }
  {
    PostingList pl_352("over", 2);
    pl_352.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_352.set(docs, freqs);
    inverted_index.push_back(pl_352);
  }
  {
    PostingList pl_353("own", 1);
    pl_353.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_353.set(docs, freqs);
    inverted_index.push_back(pl_353);
  }
  {
    PostingList pl_354("pair", 1);
    pl_354.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_354.set(docs, freqs);
    inverted_index.push_back(pl_354);
  }
  {
    PostingList pl_355("parameter", 1);
    pl_355.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_355.set(docs, freqs);
    inverted_index.push_back(pl_355);
  }
  {
    PostingList pl_356("park", 2);
    pl_356.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_356.set(docs, freqs);
    inverted_index.push_back(pl_356);
  }
  {
    PostingList pl_357("particular", 1);
    pl_357.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_357.set(docs, freqs);
    inverted_index.push_back(pl_357);
  }
  {
    PostingList pl_358("pay", 2);
    pl_358.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_358.set(docs, freqs);
    inverted_index.push_back(pl_358);
  }
  {
    PostingList pl_359("pepperoni", 1);
    pl_359.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_359.set(docs, freqs);
    inverted_index.push_back(pl_359);
  }
  {
    PostingList pl_360("performance", 2);
    pl_360.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_360.set(docs, freqs);
    inverted_index.push_back(pl_360);
  }
  {
    PostingList pl_361("ph", 1);
    pl_361.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_361.set(docs, freqs);
    inverted_index.push_back(pl_361);
  }
  {
    PostingList pl_362("pie", 1);
    pl_362.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_362.set(docs, freqs);
    inverted_index.push_back(pl_362);
  }
  {
    PostingList pl_363("pizza", 8);
    pl_363.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        7,
        1,
    };
    pl_363.set(docs, freqs);
    inverted_index.push_back(pl_363);
  }
  {
    PostingList pl_364("place", 2);
    pl_364.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_364.set(docs, freqs);
    inverted_index.push_back(pl_364);
  }
  {
    PostingList pl_365("play", 1);
    pl_365.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_365.set(docs, freqs);
    inverted_index.push_back(pl_365);
  }
  {
    PostingList pl_366("policy", 2);
    pl_366.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_366.set(docs, freqs);
    inverted_index.push_back(pl_366);
  }
  {
    PostingList pl_367("pre", 1);
    pl_367.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_367.set(docs, freqs);
    inverted_index.push_back(pl_367);
  }
  {
    PostingList pl_368("predict", 1);
    pl_368.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_368.set(docs, freqs);
    inverted_index.push_back(pl_368);
  }
  {
    PostingList pl_369("principle", 1);
    pl_369.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_369.set(docs, freqs);
    inverted_index.push_back(pl_369);
  }
  {
    PostingList pl_370("prior", 1);
    pl_370.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_370.set(docs, freqs);
    inverted_index.push_back(pl_370);
  }
  {
    PostingList pl_371("private", 1);
    pl_371.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_371.set(docs, freqs);
    inverted_index.push_back(pl_371);
  }
  {
    PostingList pl_372("problem", 2);
    pl_372.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_372.set(docs, freqs);
    inverted_index.push_back(pl_372);
  }
  {
    PostingList pl_373("produce", 3);
    pl_373.coding_off();
    std::vector<uint32_t> docs = {
        12,
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
        2,
    };
    pl_373.set(docs, freqs);
    inverted_index.push_back(pl_373);
  }
  {
    PostingList pl_374("property", 1);
    pl_374.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_374.set(docs, freqs);
    inverted_index.push_back(pl_374);
  }
  {
    PostingList pl_375("propose", 1);
    pl_375.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_375.set(docs, freqs);
    inverted_index.push_back(pl_375);
  }
  {
    PostingList pl_376("proud", 4);
    pl_376.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        4,
    };
    pl_376.set(docs, freqs);
    inverted_index.push_back(pl_376);
  }
  {
    PostingList pl_377("punk", 1);
    pl_377.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_377.set(docs, freqs);
    inverted_index.push_back(pl_377);
  }
  {
    PostingList pl_378("put", 2);
    pl_378.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
    };
    pl_378.set(docs, freqs);
    inverted_index.push_back(pl_378);
  }
  {
    PostingList pl_379("quantum", 1);
    pl_379.coding_off();
    std::vector<uint32_t> docs = {
        12,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_379.set(docs, freqs);
    inverted_index.push_back(pl_379);
  }
  {
    PostingList pl_380("quaternion", 1);
    pl_380.coding_off();
    std::vector<uint32_t> docs = {
        12,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_380.set(docs, freqs);
    inverted_index.push_back(pl_380);
  }
  {
    PostingList pl_381("race", 1);
    pl_381.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_381.set(docs, freqs);
    inverted_index.push_back(pl_381);
  }
  {
    PostingList pl_382("rapid", 1);
    pl_382.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_382.set(docs, freqs);
    inverted_index.push_back(pl_382);
  }
  {
    PostingList pl_383("rat", 1);
    pl_383.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_383.set(docs, freqs);
    inverted_index.push_back(pl_383);
  }
  {
    PostingList pl_384("red", 2);
    pl_384.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_384.set(docs, freqs);
    inverted_index.push_back(pl_384);
  }
  {
    PostingList pl_385("regress", 4);
    pl_385.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        4,
    };
    pl_385.set(docs, freqs);
    inverted_index.push_back(pl_385);
  }
  {
    PostingList pl_386("rein", 1);
    pl_386.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_386.set(docs, freqs);
    inverted_index.push_back(pl_386);
  }
  {
    PostingList pl_387("reinforcement", 2);
    pl_387.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_387.set(docs, freqs);
    inverted_index.push_back(pl_387);
  }
  {
    PostingList pl_388("related", 2);
    pl_388.coding_off();
    std::vector<uint32_t> docs = {
        11,
        12,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
    };
    pl_388.set(docs, freqs);
    inverted_index.push_back(pl_388);
  }
  {
    PostingList pl_389("relativity", 1);
    pl_389.coding_off();
    std::vector<uint32_t> docs = {
        12,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_389.set(docs, freqs);
    inverted_index.push_back(pl_389);
  }
  {
    PostingList pl_390("remember", 1);
    pl_390.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_390.set(docs, freqs);
    inverted_index.push_back(pl_390);
  }
  {
    PostingList pl_391("report", 1);
    pl_391.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_391.set(docs, freqs);
    inverted_index.push_back(pl_391);
  }
  {
    PostingList pl_392("result", 2);
    pl_392.coding_off();
    std::vector<uint32_t> docs = {
        15,
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
    };
    pl_392.set(docs, freqs);
    inverted_index.push_back(pl_392);
  }
  {
    PostingList pl_393("rich", 1);
    pl_393.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_393.set(docs, freqs);
    inverted_index.push_back(pl_393);
  }
  {
    PostingList pl_394("right", 1);
    pl_394.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_394.set(docs, freqs);
    inverted_index.push_back(pl_394);
  }
  {
    PostingList pl_395("road", 2);
    pl_395.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_395.set(docs, freqs);
    inverted_index.push_back(pl_395);
  }
  {
    PostingList pl_396("rumor", 1);
    pl_396.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_396.set(docs, freqs);
    inverted_index.push_back(pl_396);
  }
  {
    PostingList pl_397("run", 1);
    pl_397.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_397.set(docs, freqs);
    inverted_index.push_back(pl_397);
  }
  {
    PostingList pl_398("s", 1);
    pl_398.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_398.set(docs, freqs);
    inverted_index.push_back(pl_398);
  }
  {
    PostingList pl_399("same", 1);
    pl_399.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_399.set(docs, freqs);
    inverted_index.push_back(pl_399);
  }
  {
    PostingList pl_400("sample", 1);
    pl_400.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_400.set(docs, freqs);
    inverted_index.push_back(pl_400);
  }
  {
    PostingList pl_401("say", 1);
    pl_401.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_401.set(docs, freqs);
    inverted_index.push_back(pl_401);
  }
  {
    PostingList pl_402("school", 1);
    pl_402.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_402.set(docs, freqs);
    inverted_index.push_back(pl_402);
  }
  {
    PostingList pl_403("scum", 1);
    pl_403.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_403.set(docs, freqs);
    inverted_index.push_back(pl_403);
  }
  {
    PostingList pl_404("seconds", 1);
    pl_404.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_404.set(docs, freqs);
    inverted_index.push_back(pl_404);
  }
  {
    PostingList pl_405("section", 2);
    pl_405.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_405.set(docs, freqs);
    inverted_index.push_back(pl_405);
  }
  {
    PostingList pl_406("sedenion", 1);
    pl_406.coding_off();
    std::vector<uint32_t> docs = {
        12,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_406.set(docs, freqs);
    inverted_index.push_back(pl_406);
  }
  {
    PostingList pl_407("see", 2);
    pl_407.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_407.set(docs, freqs);
    inverted_index.push_back(pl_407);
  }
  {
    PostingList pl_408("seeing", 1);
    pl_408.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_408.set(docs, freqs);
    inverted_index.push_back(pl_408);
  }
  {
    PostingList pl_409("seem", 1);
    pl_409.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_409.set(docs, freqs);
    inverted_index.push_back(pl_409);
  }
  {
    PostingList pl_410("seen", 1);
    pl_410.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_410.set(docs, freqs);
    inverted_index.push_back(pl_410);
  }
  {
    PostingList pl_411("segway", 2);
    pl_411.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_411.set(docs, freqs);
    inverted_index.push_back(pl_411);
  }
  {
    PostingList pl_412("seiko", 1);
    pl_412.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_412.set(docs, freqs);
    inverted_index.push_back(pl_412);
  }
  {
    PostingList pl_413("sense", 1);
    pl_413.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_413.set(docs, freqs);
    inverted_index.push_back(pl_413);
  }
  {
    PostingList pl_414("sent", 1);
    pl_414.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_414.set(docs, freqs);
    inverted_index.push_back(pl_414);
  }
  {
    PostingList pl_415("serving", 1);
    pl_415.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_415.set(docs, freqs);
    inverted_index.push_back(pl_415);
  }
  {
    PostingList pl_416("set", 1);
    pl_416.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_416.set(docs, freqs);
    inverted_index.push_back(pl_416);
  }
  {
    PostingList pl_417("setting", 1);
    pl_417.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_417.set(docs, freqs);
    inverted_index.push_back(pl_417);
  }
  {
    PostingList pl_418("setup", 1);
    pl_418.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_418.set(docs, freqs);
    inverted_index.push_back(pl_418);
  }
  {
    PostingList pl_419("seven", 8);
    pl_419.coding_off();
    std::vector<uint32_t> docs = {
        7,
        13,
    };
    std::vector<uint32_t> freqs = {
        7,
        1,
    };
    pl_419.set(docs, freqs);
    inverted_index.push_back(pl_419);
  }
  {
    PostingList pl_420("shake", 1);
    pl_420.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_420.set(docs, freqs);
    inverted_index.push_back(pl_420);
  }
  {
    PostingList pl_421("shallow", 1);
    pl_421.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_421.set(docs, freqs);
    inverted_index.push_back(pl_421);
  }
  {
    PostingList pl_422("shoot", 1);
    pl_422.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_422.set(docs, freqs);
    inverted_index.push_back(pl_422);
  }
  {
    PostingList pl_423("shot", 5);
    pl_423.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        5,
    };
    pl_423.set(docs, freqs);
    inverted_index.push_back(pl_423);
  }
  {
    PostingList pl_424("shoulder", 1);
    pl_424.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_424.set(docs, freqs);
    inverted_index.push_back(pl_424);
  }
  {
    PostingList pl_425("sicilian", 1);
    pl_425.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_425.set(docs, freqs);
    inverted_index.push_back(pl_425);
  }
  {
    PostingList pl_426("side", 2);
    pl_426.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_426.set(docs, freqs);
    inverted_index.push_back(pl_426);
  }
  {
    PostingList pl_427("sideways", 1);
    pl_427.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_427.set(docs, freqs);
    inverted_index.push_back(pl_427);
  }
  {
    PostingList pl_428("sign", 1);
    pl_428.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_428.set(docs, freqs);
    inverted_index.push_back(pl_428);
  }
  {
    PostingList pl_429("similar", 2);
    pl_429.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_429.set(docs, freqs);
    inverted_index.push_back(pl_429);
  }
  {
    PostingList pl_430("single", 1);
    pl_430.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_430.set(docs, freqs);
    inverted_index.push_back(pl_430);
  }
  {
    PostingList pl_431("sink", 1);
    pl_431.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_431.set(docs, freqs);
    inverted_index.push_back(pl_431);
  }
  {
    PostingList pl_432("six", 8);
    pl_432.coding_off();
    std::vector<uint32_t> docs = {
        6,
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        6,
        1,
        1,
    };
    pl_432.set(docs, freqs);
    inverted_index.push_back(pl_432);
  }
  {
    PostingList pl_433("sixteen", 1);
    pl_433.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_433.set(docs, freqs);
    inverted_index.push_back(pl_433);
  }
  {
    PostingList pl_434("skate", 1);
    pl_434.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_434.set(docs, freqs);
    inverted_index.push_back(pl_434);
  }
  {
    PostingList pl_435("skill", 1);
    pl_435.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_435.set(docs, freqs);
    inverted_index.push_back(pl_435);
  }
  {
    PostingList pl_436("small", 3);
    pl_436.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        3,
    };
    pl_436.set(docs, freqs);
    inverted_index.push_back(pl_436);
  }
  {
    PostingList pl_437("smart", 1);
    pl_437.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_437.set(docs, freqs);
    inverted_index.push_back(pl_437);
  }
  {
    PostingList pl_438("smooth", 1);
    pl_438.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_438.set(docs, freqs);
    inverted_index.push_back(pl_438);
  }
  {
    PostingList pl_439("snow", 4);
    pl_439.coding_off();
    std::vector<uint32_t> docs = {
        11,
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
        3,
    };
    pl_439.set(docs, freqs);
    inverted_index.push_back(pl_439);
  }
  {
    PostingList pl_440("so", 4);
    pl_440.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        3,
        1,
    };
    pl_440.set(docs, freqs);
    inverted_index.push_back(pl_440);
  }
  {
    PostingList pl_441("software", 3);
    pl_441.coding_off();
    std::vector<uint32_t> docs = {
        11,
        15,
    };
    std::vector<uint32_t> freqs = {
        2,
        1,
    };
    pl_441.set(docs, freqs);
    inverted_index.push_back(pl_441);
  }
  {
    PostingList pl_442("solve", 1);
    pl_442.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_442.set(docs, freqs);
    inverted_index.push_back(pl_442);
  }
  {
    PostingList pl_443("some", 5);
    pl_443.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        4,
        1,
    };
    pl_443.set(docs, freqs);
    inverted_index.push_back(pl_443);
  }
  {
    PostingList pl_444("something", 1);
    pl_444.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_444.set(docs, freqs);
    inverted_index.push_back(pl_444);
  }
  {
    PostingList pl_445("sometimes", 1);
    pl_445.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_445.set(docs, freqs);
    inverted_index.push_back(pl_445);
  }
  {
    PostingList pl_446("song", 1);
    pl_446.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_446.set(docs, freqs);
    inverted_index.push_back(pl_446);
  }
  {
    PostingList pl_447("space", 1);
    pl_447.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_447.set(docs, freqs);
    inverted_index.push_back(pl_447);
  }
  {
    PostingList pl_448("special", 1);
    pl_448.coding_off();
    std::vector<uint32_t> docs = {
        12,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_448.set(docs, freqs);
    inverted_index.push_back(pl_448);
  }
  {
    PostingList pl_449("species", 1);
    pl_449.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_449.set(docs, freqs);
    inverted_index.push_back(pl_449);
  }
  {
    PostingList pl_450("specific", 1);
    pl_450.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_450.set(docs, freqs);
    inverted_index.push_back(pl_450);
  }
  {
    PostingList pl_451("speed", 1);
    pl_451.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_451.set(docs, freqs);
    inverted_index.push_back(pl_451);
  }
  {
    PostingList pl_452("spice", 1);
    pl_452.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_452.set(docs, freqs);
    inverted_index.push_back(pl_452);
  }
  {
    PostingList pl_453("stand", 1);
    pl_453.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_453.set(docs, freqs);
    inverted_index.push_back(pl_453);
  }
  {
    PostingList pl_454("standard", 1);
    pl_454.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_454.set(docs, freqs);
    inverted_index.push_back(pl_454);
  }
  {
    PostingList pl_455("standing", 1);
    pl_455.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_455.set(docs, freqs);
    inverted_index.push_back(pl_455);
  }
  {
    PostingList pl_456("state", 1);
    pl_456.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_456.set(docs, freqs);
    inverted_index.push_back(pl_456);
  }
  {
    PostingList pl_457("static", 1);
    pl_457.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_457.set(docs, freqs);
    inverted_index.push_back(pl_457);
  }
  {
    PostingList pl_458("statistic", 1);
    pl_458.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_458.set(docs, freqs);
    inverted_index.push_back(pl_458);
  }
  {
    PostingList pl_459("stephenson", 4);
    pl_459.coding_off();
    std::vector<uint32_t> docs = {
        11,
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
        3,
    };
    pl_459.set(docs, freqs);
    inverted_index.push_back(pl_459);
  }
  {
    PostingList pl_460("steps", 1);
    pl_460.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_460.set(docs, freqs);
    inverted_index.push_back(pl_460);
  }
  {
    PostingList pl_461("sticker", 1);
    pl_461.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_461.set(docs, freqs);
    inverted_index.push_back(pl_461);
  }
  {
    PostingList pl_462("still", 1);
    pl_462.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_462.set(docs, freqs);
    inverted_index.push_back(pl_462);
  }
  {
    PostingList pl_463("stinking", 1);
    pl_463.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_463.set(docs, freqs);
    inverted_index.push_back(pl_463);
  }
  {
    PostingList pl_464("story", 2);
    pl_464.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_464.set(docs, freqs);
    inverted_index.push_back(pl_464);
  }
  {
    PostingList pl_465("strawbridge", 1);
    pl_465.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_465.set(docs, freqs);
    inverted_index.push_back(pl_465);
  }
  {
    PostingList pl_466("street", 4);
    pl_466.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
        3,
    };
    pl_466.set(docs, freqs);
    inverted_index.push_back(pl_466);
  }
  {
    PostingList pl_467("stress", 1);
    pl_467.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_467.set(docs, freqs);
    inverted_index.push_back(pl_467);
  }
  {
    PostingList pl_468("string", 1);
    pl_468.coding_off();
    std::vector<uint32_t> docs = {
        12,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_468.set(docs, freqs);
    inverted_index.push_back(pl_468);
  }
  {
    PostingList pl_469("structure", 1);
    pl_469.coding_off();
    std::vector<uint32_t> docs = {
        12,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_469.set(docs, freqs);
    inverted_index.push_back(pl_469);
  }
  {
    PostingList pl_470("studied", 2);
    pl_470.coding_off();
    std::vector<uint32_t> docs = {
        12,
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
    };
    pl_470.set(docs, freqs);
    inverted_index.push_back(pl_470);
  }
  {
    PostingList pl_471("such", 4);
    pl_471.coding_off();
    std::vector<uint32_t> docs = {
        11,
        12,
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
        2,
    };
    pl_471.set(docs, freqs);
    inverted_index.push_back(pl_471);
  }
  {
    PostingList pl_472("suit", 1);
    pl_472.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_472.set(docs, freqs);
    inverted_index.push_back(pl_472);
  }
  {
    PostingList pl_473("super", 1);
    pl_473.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_473.set(docs, freqs);
    inverted_index.push_back(pl_473);
  }
  {
    PostingList pl_474("supervise", 2);
    pl_474.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_474.set(docs, freqs);
    inverted_index.push_back(pl_474);
  }
  {
    PostingList pl_475("sure", 1);
    pl_475.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_475.set(docs, freqs);
    inverted_index.push_back(pl_475);
  }
  {
    PostingList pl_476("surprise", 1);
    pl_476.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_476.set(docs, freqs);
    inverted_index.push_back(pl_476);
  }
  {
    PostingList pl_477("swear", 1);
    pl_477.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_477.set(docs, freqs);
    inverted_index.push_back(pl_477);
  }
  {
    PostingList pl_478("sweaty", 1);
    pl_478.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_478.set(docs, freqs);
    inverted_index.push_back(pl_478);
  }
  {
    PostingList pl_479("swing", 1);
    pl_479.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_479.set(docs, freqs);
    inverted_index.push_back(pl_479);
  }
  {
    PostingList pl_480("t", 1);
    pl_480.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_480.set(docs, freqs);
    inverted_index.push_back(pl_480);
  }
  {
    PostingList pl_481("take", 4);
    pl_481.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
        3,
    };
    pl_481.set(docs, freqs);
    inverted_index.push_back(pl_481);
  }
  {
    PostingList pl_482("taking", 1);
    pl_482.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_482.set(docs, freqs);
    inverted_index.push_back(pl_482);
  }
  {
    PostingList pl_483("tall", 1);
    pl_483.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_483.set(docs, freqs);
    inverted_index.push_back(pl_483);
  }
  {
    PostingList pl_484("task", 8);
    pl_484.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        8,
    };
    pl_484.set(docs, freqs);
    inverted_index.push_back(pl_484);
  }
  {
    PostingList pl_485("teaching", 1);
    pl_485.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_485.set(docs, freqs);
    inverted_index.push_back(pl_485);
  }
  {
    PostingList pl_486("television", 1);
    pl_486.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_486.set(docs, freqs);
    inverted_index.push_back(pl_486);
  }
  {
    PostingList pl_487("tell", 1);
    pl_487.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_487.set(docs, freqs);
    inverted_index.push_back(pl_487);
  }
  {
    PostingList pl_488("ten", 10);
    pl_488.coding_off();
    std::vector<uint32_t> docs = {
        10,
    };
    std::vector<uint32_t> freqs = {
        10,
    };
    pl_488.set(docs, freqs);
    inverted_index.push_back(pl_488);
  }
  {
    PostingList pl_489("tenure", 1);
    pl_489.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_489.set(docs, freqs);
    inverted_index.push_back(pl_489);
  }
  {
    PostingList pl_490("term", 1);
    pl_490.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_490.set(docs, freqs);
    inverted_index.push_back(pl_490);
  }
  {
    PostingList pl_491("than", 3);
    pl_491.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        2,
        1,
    };
    pl_491.set(docs, freqs);
    inverted_index.push_back(pl_491);
  }
  {
    PostingList pl_492("that", 18);
    pl_492.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
        15,
        16,
    };
    std::vector<uint32_t> freqs = {
        3,
        1,
        3,
        11,
    };
    pl_492.set(docs, freqs);
    inverted_index.push_back(pl_492);
  }
  {
    PostingList pl_493("the", 81);
    pl_493.coding_off();
    std::vector<uint32_t> docs = {
        11, 12, 13, 15, 16,
    };
    std::vector<uint32_t> freqs = {
        25, 5, 20, 13, 18,
    };
    pl_493.set(docs, freqs);
    inverted_index.push_back(pl_493);
  }
  {
    PostingList pl_494("their", 4);
    pl_494.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        4,
    };
    pl_494.set(docs, freqs);
    inverted_index.push_back(pl_494);
  }
  {
    PostingList pl_495("them", 3);
    pl_495.coding_off();
    std::vector<uint32_t> docs = {
        12,
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
        2,
    };
    pl_495.set(docs, freqs);
    inverted_index.push_back(pl_495);
  }
  {
    PostingList pl_496("theory", 1);
    pl_496.coding_off();
    std::vector<uint32_t> docs = {
        12,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_496.set(docs, freqs);
    inverted_index.push_back(pl_496);
  }
  {
    PostingList pl_497("there", 1);
    pl_497.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_497.set(docs, freqs);
    inverted_index.push_back(pl_497);
  }
  {
    PostingList pl_498("these", 2);
    pl_498.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_498.set(docs, freqs);
    inverted_index.push_back(pl_498);
  }
  {
    PostingList pl_499("they", 2);
    pl_499.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
    };
    pl_499.set(docs, freqs);
    inverted_index.push_back(pl_499);
  }
  {
    PostingList pl_500("things", 1);
    pl_500.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_500.set(docs, freqs);
    inverted_index.push_back(pl_500);
  }
  {
    PostingList pl_501("think", 2);
    pl_501.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
    };
    pl_501.set(docs, freqs);
    inverted_index.push_back(pl_501);
  }
  {
    PostingList pl_502("thirty", 3);
    pl_502.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        2,
        1,
    };
    pl_502.set(docs, freqs);
    inverted_index.push_back(pl_502);
  }
  {
    PostingList pl_503("this", 7);
    pl_503.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
        16,
    };
    std::vector<uint32_t> freqs = {
        2,
        2,
        3,
    };
    pl_503.set(docs, freqs);
    inverted_index.push_back(pl_503);
  }
  {
    PostingList pl_504("those", 1);
    pl_504.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_504.set(docs, freqs);
    inverted_index.push_back(pl_504);
  }
  {
    PostingList pl_505("three", 5);
    pl_505.coding_off();
    std::vector<uint32_t> docs = {
        3,
        12,
    };
    std::vector<uint32_t> freqs = {
        3,
        2,
    };
    pl_505.set(docs, freqs);
    inverted_index.push_back(pl_505);
  }
  {
    PostingList pl_506("time", 2);
    pl_506.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_506.set(docs, freqs);
    inverted_index.push_back(pl_506);
  }
  {
    PostingList pl_507("times", 1);
    pl_507.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_507.set(docs, freqs);
    inverted_index.push_back(pl_507);
  }
  {
    PostingList pl_508("tire", 1);
    pl_508.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_508.set(docs, freqs);
    inverted_index.push_back(pl_508);
  }
  {
    PostingList pl_509("title", 1);
    pl_509.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_509.set(docs, freqs);
    inverted_index.push_back(pl_509);
  }
  {
    PostingList pl_510("to", 36);
    pl_510.coding_off();
    std::vector<uint32_t> docs = {
        11,
        12,
        13,
        16,
    };
    std::vector<uint32_t> freqs = {
        13,
        2,
        11,
        10,
    };
    pl_510.set(docs, freqs);
    inverted_index.push_back(pl_510);
  }
  {
    PostingList pl_511("train", 5);
    pl_511.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        5,
    };
    pl_511.set(docs, freqs);
    inverted_index.push_back(pl_511);
  }
  {
    PostingList pl_512("training", 3);
    pl_512.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        3,
    };
    pl_512.set(docs, freqs);
    inverted_index.push_back(pl_512);
  }
  {
    PostingList pl_513("trillion", 1);
    pl_513.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_513.set(docs, freqs);
    inverted_index.push_back(pl_513);
  }
  {
    PostingList pl_514("try", 1);
    pl_514.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_514.set(docs, freqs);
    inverted_index.push_back(pl_514);
  }
  {
    PostingList pl_515("tune", 2);
    pl_515.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_515.set(docs, freqs);
    inverted_index.push_back(pl_515);
  }
  {
    PostingList pl_516("turning", 1);
    pl_516.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_516.set(docs, freqs);
    inverted_index.push_back(pl_516);
  }
  {
    PostingList pl_517("twenty", 2);
    pl_517.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
    };
    pl_517.set(docs, freqs);
    inverted_index.push_back(pl_517);
  }
  {
    PostingList pl_518("two", 8);
    pl_518.coding_off();
    std::vector<uint32_t> docs = {
        2, 11, 12, 13, 16,
    };
    std::vector<uint32_t> freqs = {
        2, 1, 2, 2, 1,
    };
    pl_518.set(docs, freqs);
    inverted_index.push_back(pl_518);
  }
  {
    PostingList pl_519("type", 1);
    pl_519.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_519.set(docs, freqs);
    inverted_index.push_back(pl_519);
  }
  {
    PostingList pl_520("uncle", 3);
    pl_520.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        2,
        1,
    };
    pl_520.set(docs, freqs);
    inverted_index.push_back(pl_520);
  }
  {
    PostingList pl_521("uniform", 1);
    pl_521.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_521.set(docs, freqs);
    inverted_index.push_back(pl_521);
  }
  {
    PostingList pl_522("universe", 1);
    pl_522.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_522.set(docs, freqs);
    inverted_index.push_back(pl_522);
  }
  {
    PostingList pl_523("up", 2);
    pl_523.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
    };
    pl_523.set(docs, freqs);
    inverted_index.push_back(pl_523);
  }
  {
    PostingList pl_524("use", 5);
    pl_524.coding_off();
    std::vector<uint32_t> docs = {
        11,
        12,
        16,
    };
    std::vector<uint32_t> freqs = {
        2,
        1,
        2,
    };
    pl_524.set(docs, freqs);
    inverted_index.push_back(pl_524);
  }
  {
    PostingList pl_525("vague", 1);
    pl_525.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_525.set(docs, freqs);
    inverted_index.push_back(pl_525);
  }
  {
    PostingList pl_526("value", 1);
    pl_526.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_526.set(docs, freqs);
    inverted_index.push_back(pl_526);
  }
  {
    PostingList pl_527("variety", 2);
    pl_527.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_527.set(docs, freqs);
    inverted_index.push_back(pl_527);
  }
  {
    PostingList pl_528("vinyl", 1);
    pl_528.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_528.set(docs, freqs);
    inverted_index.push_back(pl_528);
  }
  {
    PostingList pl_529("vise", 1);
    pl_529.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_529.set(docs, freqs);
    inverted_index.push_back(pl_529);
  }
  {
    PostingList pl_530("vision", 1);
    pl_530.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_530.set(docs, freqs);
    inverted_index.push_back(pl_530);
  }
  {
    PostingList pl_531("walk", 1);
    pl_531.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_531.set(docs, freqs);
    inverted_index.push_back(pl_531);
  }
  {
    PostingList pl_532("warning", 1);
    pl_532.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_532.set(docs, freqs);
    inverted_index.push_back(pl_532);
  }
  {
    PostingList pl_533("was", 4);
    pl_533.coding_off();
    std::vector<uint32_t> docs = {
        11,
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
        3,
    };
    pl_533.set(docs, freqs);
    inverted_index.push_back(pl_533);
  }
  {
    PostingList pl_534("watch", 1);
    pl_534.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_534.set(docs, freqs);
    inverted_index.push_back(pl_534);
  }
  {
    PostingList pl_535("wave", 1);
    pl_535.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_535.set(docs, freqs);
    inverted_index.push_back(pl_535);
  }
  {
    PostingList pl_536("we", 5);
    pl_536.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        5,
    };
    pl_536.set(docs, freqs);
    inverted_index.push_back(pl_536);
  }
  {
    PostingList pl_537("wear", 1);
    pl_537.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_537.set(docs, freqs);
    inverted_index.push_back(pl_537);
  }
  {
    PostingList pl_538("well", 3);
    pl_538.coding_off();
    std::vector<uint32_t> docs = {
        11,
        12,
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
        1,
    };
    pl_538.set(docs, freqs);
    inverted_index.push_back(pl_538);
  }
  {
    PostingList pl_539("were", 1);
    pl_539.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_539.set(docs, freqs);
    inverted_index.push_back(pl_539);
  }
  {
    PostingList pl_540("wet", 1);
    pl_540.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_540.set(docs, freqs);
    inverted_index.push_back(pl_540);
  }
  {
    PostingList pl_541("what", 4);
    pl_541.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        3,
        1,
    };
    pl_541.set(docs, freqs);
    inverted_index.push_back(pl_541);
  }
  {
    PostingList pl_542("whatever", 1);
    pl_542.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_542.set(docs, freqs);
    inverted_index.push_back(pl_542);
  }
  {
    PostingList pl_543("when", 4);
    pl_543.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
        2,
        1,
    };
    pl_543.set(docs, freqs);
    inverted_index.push_back(pl_543);
  }
  {
    PostingList pl_544("where", 1);
    pl_544.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_544.set(docs, freqs);
    inverted_index.push_back(pl_544);
  }
  {
    PostingList pl_545("which", 2);
    pl_545.coding_off();
    std::vector<uint32_t> docs = {
        11,
        12,
    };
    std::vector<uint32_t> freqs = {
        1,
        1,
    };
    pl_545.set(docs, freqs);
    inverted_index.push_back(pl_545);
  }
  {
    PostingList pl_546("whipsaw", 1);
    pl_546.coding_off();
    std::vector<uint32_t> docs = {
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_546.set(docs, freqs);
    inverted_index.push_back(pl_546);
  }
  {
    PostingList pl_547("whose", 1);
    pl_547.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_547.set(docs, freqs);
    inverted_index.push_back(pl_547);
  }
  {
    PostingList pl_548("why", 1);
    pl_548.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_548.set(docs, freqs);
    inverted_index.push_back(pl_548);
  }
  {
    PostingList pl_549("widely", 1);
    pl_549.coding_off();
    std::vector<uint32_t> docs = {
        12,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_549.set(docs, freqs);
    inverted_index.push_back(pl_549);
  }
  {
    PostingList pl_550("wikipedia", 1);
    pl_550.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_550.set(docs, freqs);
    inverted_index.push_back(pl_550);
  }
  {
    PostingList pl_551("will", 2);
    pl_551.coding_off();
    std::vector<uint32_t> docs = {
        16,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_551.set(docs, freqs);
    inverted_index.push_back(pl_551);
  }
  {
    PostingList pl_552("with", 9);
    pl_552.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
        16,
    };
    std::vector<uint32_t> freqs = {
        2,
        1,
        6,
    };
    pl_552.set(docs, freqs);
    inverted_index.push_back(pl_552);
  }
  {
    PostingList pl_553("work", 4);
    pl_553.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        3,
        1,
    };
    pl_553.set(docs, freqs);
    inverted_index.push_back(pl_553);
  }
  {
    PostingList pl_554("working", 1);
    pl_554.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_554.set(docs, freqs);
    inverted_index.push_back(pl_554);
  }
  {
    PostingList pl_555("would", 2);
    pl_555.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_555.set(docs, freqs);
    inverted_index.push_back(pl_555);
  }
  {
    PostingList pl_556("wrote", 2);
    pl_556.coding_off();
    std::vector<uint32_t> docs = {
        15,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_556.set(docs, freqs);
    inverted_index.push_back(pl_556);
  }
  {
    PostingList pl_557("year", 1);
    pl_557.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_557.set(docs, freqs);
    inverted_index.push_back(pl_557);
  }
  {
    PostingList pl_558("years", 2);
    pl_558.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        2,
    };
    pl_558.set(docs, freqs);
    inverted_index.push_back(pl_558);
  }
  {
    PostingList pl_559("yellow", 1);
    pl_559.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_559.set(docs, freqs);
    inverted_index.push_back(pl_559);
  }
  {
    PostingList pl_560("you", 7);
    pl_560.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        7,
    };
    pl_560.set(docs, freqs);
    inverted_index.push_back(pl_560);
  }
  {
    PostingList pl_561("your", 7);
    pl_561.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        6,
        1,
    };
    pl_561.set(docs, freqs);
    inverted_index.push_back(pl_561);
  }
  {
    PostingList pl_562("youre", 3);
    pl_562.coding_off();
    std::vector<uint32_t> docs = {
        11,
        13,
    };
    std::vector<uint32_t> freqs = {
        1,
        2,
    };
    pl_562.set(docs, freqs);
    inverted_index.push_back(pl_562);
  }
  {
    PostingList pl_563("yourself", 1);
    pl_563.coding_off();
    std::vector<uint32_t> docs = {
        11,
    };
    std::vector<uint32_t> freqs = {
        1,
    };
    pl_563.set(docs, freqs);
    inverted_index.push_back(pl_563);
  }
  return inverted_index;
}

}  // namespace fixture
