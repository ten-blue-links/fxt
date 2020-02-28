/*
 * Copyright 2018 The Tesserae authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#pragma once

#include <cstdint>
#include <iostream>

/*
 * Static document features.
 */
struct statdoc_entry {
    uint32_t len              = 0;
    uint32_t title_len        = 0;
    uint32_t visterm_len      = 0;
    uint16_t url_len          = 0;
    uint16_t url_depth        = 0;
    double   avg_term_len     = 0;
    double   entropy          = 0;
    double   stop_cover       = 0;
    double   frac_stop        = 0;
    double   frac_anchor_text = 0;
    double   frac_vis_text    = 0;
    double   frac_table_text  = 0;
    double   frac_td_text     = 0;
    uint8_t  is_wikipedia     = 0;

    friend std::ostream &operator<<(std::ostream &os, const statdoc_entry &de);
};

std::ostream &operator<<(std::ostream &os, const statdoc_entry &de) {
    os << "," << de.len;
    os << "," << de.title_len;
    os << "," << de.visterm_len;
    os << "," << de.url_len;
    os << "," << de.url_depth;
    os << "," << de.avg_term_len;
    os << "," << de.entropy;
    os << "," << de.stop_cover;
    os << "," << de.frac_stop;
    os << "," << de.frac_anchor_text;
    os << "," << de.frac_vis_text;
    os << "," << de.frac_table_text;
    os << "," << de.frac_td_text;
    os << "," << de.is_wikipedia;

    return os;
}
