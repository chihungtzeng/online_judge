#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class SummaryRanges {
 public:
  vector<vector<int>> segs_;
  unordered_set<int> seen_;
  /** Initialize your data structure here. */
  SummaryRanges() {}

  void addNum(int val) {
    if (seen_.find(val) != seen_.end()) {
      return;
    }
    seen_.insert(val);
    vector<int> seg{val, val};
    auto it = std::lower_bound(segs_.begin(), segs_.end(), seg);
    int index = it - segs_.begin();
    segs_.insert(it, seg);
    if (index < static_cast<int>(segs_.size()) - 1) {
      if (segs_[index + 1][0] - 1 == val) {
        segs_[index][1] = segs_[index + 1][1];
        segs_.erase(segs_.begin() + index + 1);
      }
    }
    if (index > 0) {
      if (segs_[index - 1][1] + 1 == val) {
        segs_[index - 1][1] = segs_[index][1];
        segs_.erase(segs_.begin() + index);
      }
    }
  }

  vector<vector<int>> getIntervals() { return segs_; }
};
