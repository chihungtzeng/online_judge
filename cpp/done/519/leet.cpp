#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  set<pair<int, int>> segs_;
  int n_cols_;
  int nelem_;
  Solution(int n_rows, int n_cols) {
    nelem_ = n_rows * n_cols;
    n_cols_ = n_cols;
    reset();
  }

  vector<int> flip() {
    auto seg_it = segs_.begin();
    advance(seg_it, rand() % segs_.size());
    auto seg = *seg_it;
    int seg_size = seg.second - seg.first + 1;
    int pick = seg.first + rand() % seg_size;
    // LOG(INFO) << "pick: " << pick << " segs_: " << segs_;
    segs_.erase(seg_it);
    if (pick - 1 >= seg.first) {
      segs_.insert({seg.first, pick - 1});
    }
    if (pick + 1 <= seg.second) {
      segs_.insert({pick + 1, seg.second});
    }
    // LOG(INFO) << "split segs_ into: " << segs_;
    return {pick / n_cols_, pick % n_cols_};
  }

  void reset() {
    segs_.clear();
    segs_.insert({0, nelem_ - 1});
  }
};
