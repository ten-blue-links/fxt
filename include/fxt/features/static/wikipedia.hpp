/*
 * Copyright 2019 The Fxt authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

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
