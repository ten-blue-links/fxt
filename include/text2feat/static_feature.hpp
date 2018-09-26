/*
 * Static document feature list.
 */

#pragma once

#include <cstdint>
#include <iostream>
#include <vector>

#include "statdoc_entry.hpp"

#include "cereal/types/vector.hpp"

class StaticFeature {
public:
  statdoc_entry dentry;
  StaticFeature() = default;
  StaticFeature(const uint32_t l,
                  const uint32_t tl,
                  const uint32_t vtl,
                  const uint16_t ul,
                  const uint16_t ud,
                  const double   avgtl,
                  const double   ent,
                  const double   sc,
                  const double   fs,
                  const double   fat,
                  const double   fvt,
                  const double   ftab,
                  const double   ftd) {
    // Avoid using a constructor for `statdoc_entry` becuase we have a crude
    // code genreation process for statdoc_entry_flag.hpp and
    // doc_entry_flag.hpp. See script/feat2id.sh.
    dentry.len = l;
    dentry.title_len = tl;
    dentry.visterm_len = vtl;
    dentry.url_len = ul;
    dentry.url_depth = ud;
    dentry.avg_term_len = avgtl;
    dentry.entropy = ent;
    dentry.stop_cover = sc;
    dentry.frac_stop = fs;
    dentry.frac_anchor_text = fat;
    dentry.frac_vis_text = fvt;
    dentry.frac_table_text = ftab;
    dentry.frac_td_text = ftd;
  }
  StaticFeature(const statdoc_entry &de) : StaticFeature(
    de.len,
    de.title_len,
    de.visterm_len,
    de.url_len,
    de.url_depth,
    de.avg_term_len,
    de.entropy,
    de.stop_cover,
    de.frac_stop,
    de.frac_anchor_text,
    de.frac_vis_text,
    de.frac_table_text,
    de.frac_td_text
      ) {}

    template <class Archive>
    void serialize(Archive &archive) {
        archive(dentry.len,
                dentry.title_len,
                dentry.visterm_len,
                dentry.url_len,
                dentry.url_depth,
                dentry.avg_term_len,
                dentry.entropy,
                dentry.stop_cover,
                dentry.frac_stop,
                dentry.frac_anchor_text,
                dentry.frac_vis_text,
                dentry.frac_table_text,
                dentry.frac_td_text);
    }
};

using StaticDocFeatureList = std::vector<StaticFeature>;
