#pragma once
#include <vector>

struct TermPos {
    TermPos() = default;

    TermPos(size_t order, uint64_t pos) : m_order(order), m_pos(pos) {}

    size_t   m_order;
    uint64_t m_pos;
};

/**
 * Calculate the distance between two terms.
 */
class TPDist {
   public:
    static std::pair<double, double> calc_tp_dist(const indri::utility::greedy_vector<int> &pos_i,
                                                  const indri::utility::greedy_vector<int> &pos_j,
                                                  const double                              w_i,
                                                  const double                              w_j,
                                                  int                                       wsize) {
        std::pair<double, double>                          dist_scores(0.0, 0.0);
        std::pair<uint64_t, uint64_t>                      prev_rhs(0, 0);
        indri::utility::greedy_vector<int>::const_iterator curr_itrs[] = {pos_i.begin(),
                                                                          pos_j.begin()};
        indri::utility::greedy_vector<int>::const_iterator end_itrs[]  = {pos_i.end(), pos_j.end()};
        TermPos                                            lhs, rhs;
        lhs.m_order       = *curr_itrs[0] < *curr_itrs[1] ? 0 : 1;
        rhs.m_order       = lhs.m_order == 1 ? 0 : 1;
        lhs.m_pos         = *curr_itrs[lhs.m_order];
        rhs.m_pos         = *curr_itrs[rhs.m_order];
        uint64_t next_pos = INTMAX_MAX;
        TermPos  tmp;
        while (curr_itrs[lhs.m_order] != end_itrs[lhs.m_order]) {
            ++curr_itrs[lhs.m_order];
            if (curr_itrs[lhs.m_order] == end_itrs[lhs.m_order]) {
                //!< we can finish it
                _acc_dist(lhs, rhs, w_i, w_j, dist_scores, prev_rhs, wsize);
                break;
            }
            next_pos = *(curr_itrs[lhs.m_order]);
            if (next_pos > rhs.m_pos) {
                _acc_dist(lhs, rhs, w_i, w_j, dist_scores, prev_rhs, wsize);
                tmp = TermPos(lhs.m_order, next_pos);
                lhs = rhs;
                rhs = tmp;
            } else {
                lhs.m_pos = next_pos;
            }
        }
        return dist_scores;
    };

   protected:
    static void _acc_dist(TermPos                        lhs,
                          TermPos                        rhs,
                          double                         w_i,
                          double                         w_j,
                          std::pair<double, double> &    acc_dist,
                          std::pair<uint64_t, uint64_t> &prev_pos,
                          size_t                         wsize) {
        if (rhs.m_pos - lhs.m_pos + 1 > wsize)
            return;
        double dist_weight = _calculate_dist_weight(w_i, w_j, (rhs.m_pos - lhs.m_pos + 1));
        if (rhs.m_pos - lhs.m_pos == 1 && rhs.m_order - lhs.m_order == 1) {
            //!< bigram cases
            if (acc_dist.first == 0 || lhs.m_pos > prev_pos.first) {
                acc_dist.first += dist_weight;
                prev_pos.first = rhs.m_pos;
            }
        }
        if (acc_dist.second == 0 || lhs.m_pos > prev_pos.second) {
            //!< unordered term pair cases
            acc_dist.second += dist_weight;
            prev_pos.second = rhs.m_pos;
        }
    }

   private:
    static double _calculate_dist_weight(double w_i, double w_j, uint64_t dist) {
        double dist_weight = (std::min(w_i, 1.0) + std::min(w_j, 1.0)) / static_cast<double>(dist);
        dist_weight        = w_i * w_j * dist_weight * dist_weight;
        return dist_weight;
    }
};
