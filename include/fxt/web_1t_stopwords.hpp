/*
 * Copyright 2018 The Fxt authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#pragma once

#include <string>
#include <vector>

/*
 * Top 100 alphabetic unigrams from the Web 1T 5-gram Version 1 corpus
 * https://catalog.ldc.upenn.edu/ldc2006t13 reported by Bendersky, et al.
 * WSDM (2011).
 *
 * This set has not been stemmed. Applying Krovetz stemming results in the same
 * list. Porter stemming has not been tested.
 */
const std::vector<std::string> web_1t_top_100 = {
    "the",    "of",     "and",   "to",          "a",      "in",    "for",
    "is",     "on",     "that",  "by",          "with",   "i",     "or",
    "not",    "you",    "be",    "are",         "this",   "at",    "it",
    "as",     "from",   "your",  "have",        "was",    "an",    "will",
    "all",    "can",    "more",  "has",         "home",   "we",    "one",
    "but",    "about",  "which", "new",         "do",     "their", "our",
    "search", "other",  "they",  "up",          "my",     "time",  "out",
    "if",     "page",   "any",   "information", "his",    "he",    "been",
    "were",   "news",   "may",   "no",          "only",   "who",   "would",
    "also",   "free",   "so",    "use",         "than",   "its",   "when",
    "there",  "like",   "had",   "site",        "here",   "what",  "some",
    "me",     "us",     "c",     "contact",     "into",   "first", "these",
    "over",   "them",   "view",  "pm",          "people", "get",   "web",
    "just",   "should", "click", "now",         "see",    "two",   "her",
    "such",   "jan",
};
