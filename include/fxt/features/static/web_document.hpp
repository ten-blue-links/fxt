/*
 * Copyright 2019 The Fxt authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#pragma once

#include "fxt/static_feature.hpp"

bool is_wikipedia_url(const std::string &url) {
  const std::string wiki = "wikipedia.org";

  if (!url.size()) {
    return false;
  }

  std::string::size_type start = url.find("://");
  if (std::string::npos == start) {
    start = 0;
  } else {
    start += 3;
  }
  std::string::size_type end = url.find_first_of("/?", start);
  if (std::string::npos == end) {
    end = url.size();
  }

  std::string u = std::string(url, start, end);
  size_t idx = u.rfind(wiki);
  if (std::string::npos == idx) {
    return false;
  }

  return true;
}

/**
 * The URL site depth. That is, the number of slashes present after the scheme
 * part.
 *
 * Excludes the common trailing slash that are often a redirect of the
 * non-trailing version on many websites.
 */
void set_url_lendep(statdoc_entry &s, const std::string &url) {
  size_t depth = 0;
  size_t idx = url.find("://");
  std::string cpy = "";

  s.url_len = 0;
  s.url_depth = 0;

  if (std::string::npos != idx) {
    idx += 3;
    cpy = std::string(url.begin() + idx, url.end());
    depth = std::count(cpy.begin(), cpy.end(), '/');
    if (cpy.size() && '/' == cpy.back()) {
      cpy.pop_back();
      depth--;
    }
  }

  s.url_len = cpy.size();
  s.url_depth = depth;
}
