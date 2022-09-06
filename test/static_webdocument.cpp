#include "catch2/catch.hpp"

#include "fxt/static_feature.hpp"
#include "fxt/features/static/wikipedia.hpp"

TEST_CASE("empty url is false") { REQUIRE(false == is_wikipedia_url("")); }

TEST_CASE("non wikipedia.org url is false") {
  REQUIRE(false == is_wikipedia_url("example.org"));
  REQUIRE(false == is_wikipedia_url("http://example.org"));
  REQUIRE(false == is_wikipedia_url("https://example.org"));
  REQUIRE(false == is_wikipedia_url("https://wikipedia.example.org"));
  REQUIRE(false == is_wikipedia_url("https://example.org?wikipedia.org=foo"));
}

TEST_CASE("wikipedia.org domain and subdomain is true") {
  REQUIRE(true == is_wikipedia_url("wikipedia.org"));
  REQUIRE(true == is_wikipedia_url("http://wikipedia.org"));
  REQUIRE(true == is_wikipedia_url("https://wikipedia.org"));
  REQUIRE(true == is_wikipedia_url("az.wikipedia.org"));
  REQUIRE(true == is_wikipedia_url("http://az.wikipedia.org"));
  REQUIRE(true == is_wikipedia_url("https://az.wikipedia.org"));
}

TEST_CASE("set_url_lendep scheme") {
  statdoc_entry s;

  set_url_lendep(s, ":");
  REQUIRE(0 == s.url_len);
  REQUIRE(0 == s.url_depth);

  set_url_lendep(s, "/");
  REQUIRE(0 == s.url_len);
  REQUIRE(0 == s.url_depth);

  set_url_lendep(s, "//");
  REQUIRE(0 == s.url_len);
  REQUIRE(0 == s.url_depth);

  set_url_lendep(s, "://");
  REQUIRE(0 == s.url_len);
  REQUIRE(0 == s.url_depth);
}

TEST_CASE("set_url_lendep") {
  statdoc_entry s;

  set_url_lendep(s, "://one");
  REQUIRE(3 == s.url_len);
  REQUIRE(0 == s.url_depth);

  set_url_lendep(s, "://one/");
  REQUIRE(3 == s.url_len);
  REQUIRE(0 == s.url_depth);

  set_url_lendep(s, "://one/two");
  REQUIRE(7 == s.url_len);
  REQUIRE(1 == s.url_depth);
}
