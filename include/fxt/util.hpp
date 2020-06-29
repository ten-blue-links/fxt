/*
 * Copyright 2020 The Fxt authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#pragma once

#include <iostream>
#include <sstream>
#include <string>

class ProgressPresenter {
  size_t total_;
  size_t start_;
  size_t step_;
  size_t current_;
  std::string message_;

 public:
  ProgressPresenter() = delete;
  ProgressPresenter(size_t total, size_t start, size_t step, std::string msg)
      : total_(total),
        start_(start),
        step_(step),
        current_(start),
        message_(msg) {}

  void progress() {
    if (current_ % step_ == 0 || current_ == start_ || current_ == total_) {
      static size_t last_len = 0;
      std::ostringstream oss;
      double progress = double(current_) / double(total_);
      progress *= 100;
      std::cerr << std::string(last_len, '\b');
      oss.str("");
      oss << message_ << current_ << " (" << int(progress) << "%)";
      last_len = oss.str().size();
      std::cerr << oss.str();
    }

    if (current_ == total_) {
      std::cerr << std::endl;
    }

    ++current_;
  }
};
