#pragma once

double calculate_dfr(
    uint32_t d_f, uint64_t c_f, uint32_t c_idf, uint32_t num_docs, double avg_dlen, uint32_t dlen) {
    double fp1, ne, ir, prime, rsv;

    fp1 = c_f + 1.0;
    ne  = num_docs * (1.0 - std::pow((num_docs - 1.0) / num_docs, c_f));
    ir  = std::log2(((double)num_docs + 1.0) / (ne + 0.5));

    prime = d_f * std::log2(1.0 + (double)avg_dlen / (double)dlen);
    rsv   = prime * ir * (fp1 / ((double)c_idf * (prime + 1.0)));
    return rsv;
}
