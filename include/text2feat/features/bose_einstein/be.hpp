#pragma once

double calculate_be(uint32_t d_f, uint64_t c_f, uint32_t num_docs, double avg_dlen, uint32_t dlen) {
double l, r, prime, rsv;

l = std::log(1.0 + (double)c_f / num_docs);
r = std::log(1.0 + (double)num_docs / (double)c_f);
prime = d_f * std::log(1.0 + avg_dlen / (double)dlen);
rsv = (l + prime * r) / (prime + 1.0);

return rsv;
}
