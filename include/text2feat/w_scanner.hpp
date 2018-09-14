#pragma once
#include "indri/DocListIterator.hpp"
#include "lemur/IndexTypes.hpp"
#include <utility>
#include <vector>
#include "indri/greedy_vector"
#include <algorithm>
#include <bitset>


/**
 * for combine cdf use
 */
struct TermPos {
    TermPos() {
        t_pos = -1;
        t_idx = -1;
    }
    TermPos(int idx, int pos) : t_idx(idx), t_pos(pos){};
    TermPos(const TermPos &another) {
        t_idx = another.t_idx;
        t_pos = another.t_pos;
    }
    void update(const TermPos &another) {
        t_idx = another.t_idx;
        t_pos = another.t_pos;
    }

    int t_idx;
    int t_pos;

    bool operator<(const TermPos &another) const { return t_pos < another.t_pos; }
    bool operator>(const TermPos &another) const { return t_pos > another.t_pos; }
};

class WScanner {

   public:

    WScanner(int w_size) {
        _w_size         = w_size;
        _collection_cnt = 0;
    }


    //!< scanning func
    /**
     * count the unordered window
     * @param doc_iters
     * @return inv file
     */
    std::vector<std::pair<lemur::api::DOCID_T, uint64_t>> window_count(
    std::vector<indri::index::DocListIterator *> &doc_iters, size_t min_term) {
        _collection_cnt = 0;
        std::vector<std::pair<lemur::api::DOCID_T, uint64_t>> window_postings;
        if (_w_size == -1) {
            _w_size = doc_iters.size() * 4 + 1;
        }
        //!< current entry of the smallest df term
        lemur::api::DOCID_T                curr_doc = doc_iters[min_term]->currentEntry()->document;
        lemur::api::DOCID_T                max_doc  = curr_doc; //!< always keep current largest doc
        std::vector<TermPos>               position_list; //!< CDF container
        bool                               is_end   = false;
        indri::utility::greedy_vector<int> pos_list = doc_iters[min_term]->currentEntry()->positions;
        for (size_t j = 0; j < pos_list.size(); ++j) { //!< init
            position_list.push_back(TermPos(min_term, pos_list[j]));
        }
        std::make_heap(position_list.begin(), position_list.end());
        while (doc_iters[min_term]->nextEntry()) { //!< use shortest to get doc id is enough
            for (size_t i = 0; i < doc_iters.size(); ++i) {
                if (i != min_term) {
                    lemur::api::DOCID_T tmp_doc = doc_iters[i]->currentEntry()->document;
                    if (tmp_doc < max_doc) {
                        if (doc_iters[i]->nextEntry(max_doc)) {
                            //!< we only get geq entries
                            tmp_doc = doc_iters[i]->currentEntry()->document;
                            if (tmp_doc != curr_doc) {
                                position_list.clear();
                                max_doc = tmp_doc > max_doc ? tmp_doc : max_doc;
                                break;
                            }
                        } else {
                            position_list.clear();
                            is_end = true;
                            break;
                        }
                    }
                    if (tmp_doc == curr_doc) {
                        pos_list = doc_iters[i]->currentEntry()->positions;
                        for (size_t j = 0; j < pos_list.size(); ++j) {
                            position_list.push_back(TermPos(i, pos_list[j]));
                            std::push_heap(position_list.begin(), position_list.end());
                        }
                    }
                }
            }
            if (is_end)
                break;
            if (!position_list.empty()) {
                //!< create CDF, by min heap
                uint64_t w_cnt = 0;
                w_cnt = _get_uwindows(position_list, doc_iters.size());

                if (w_cnt > 0) {
                    window_postings.push_back(std::make_pair(max_doc, w_cnt));
                    _collection_cnt += w_cnt;
                }
            }
            position_list.clear();
            curr_doc = doc_iters[min_term]->currentEntry()->document;
            //!< move to next doc geq the curret maximum doc, since we are boolean
            if (curr_doc < max_doc) {
                if (!doc_iters[min_term]->nextEntry(max_doc)) {
                    break;
                }
            }
            curr_doc = doc_iters[min_term]->currentEntry()->document;
            max_doc  = curr_doc;
            pos_list = doc_iters[min_term]->currentEntry()->positions;
            for (size_t j = 0; j < pos_list.size(); ++j) {
                position_list.push_back(TermPos(min_term, pos_list[j]));
                std::push_heap(position_list.begin(), position_list.end());
            }
        }
        return window_postings;
    }

    void set_wsize(int size) { _w_size = size; }

    uint64_t collection_cnt() const { return _collection_cnt; }

   protected:
    /**
     * scan over cdf to count
     * @param cdf. *vector* of position list.
     * @return
     */
    uint64_t _get_uwindows(std::vector<TermPos> &cdf, size_t qlen) {
        uint64_t cnt = 0;
        std::sort_heap(cdf.begin(), cdf.end());
        TermPos         lhs, rhs;
        size_t          l = 0;
        size_t          r = l;
        std::bitset<32> seen; //!< track seen terms
        int             last_pos = 0;
        while (l < cdf.size()) {
            lhs = cdf[l];
            seen.set(lhs.t_idx);
            r   = l + 1;
            rhs = cdf[r];
            while (r < cdf.size() && rhs.t_pos - lhs.t_pos + 1 <= _w_size) {
                if (lhs.t_idx == rhs.t_idx) //!< this is for optimal intvl
                    break;
                if (!seen[rhs.t_idx]) {
                    seen.set(rhs.t_idx);
                }
                if (seen.count() == qlen && (rhs.t_pos - lhs.t_pos + 1) <= _w_size) {
                    cnt++;
                    last_pos = r;
                    break;
                }
                r++;
                rhs = cdf[r];
            }
            l++;
            seen.reset();
        }
        return cnt;
    }

   private:
    int      _w_size;
    uint64_t _collection_cnt;
};

