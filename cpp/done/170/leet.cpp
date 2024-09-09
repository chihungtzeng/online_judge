#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
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
#define DEBUG 0

class TwoSum {
 public:
  /** Initialize your data structure here. */
  unordered_map<int64_t, int> cnt_;
  unordered_set<int> cache_;
  vector<int64_t> vals_;
  TwoSum() {
    cnt_.clear();
    vals_.clear();
    cache_.clear();
  }

  /** Add the number to an internal data structure.. */
  void add(int number) {
#if DEBUG
    LOG(INFO) << "-------------------- before adding " << number;
    for (auto& [key, val] : cnt_) {
      LOG(INFO) << key << ":" << val;
    }
#endif
    auto it = cnt_.find(number);
    if (it == cnt_.end()) {
      cnt_[number] = 1;
      vals_.push_back(number);
    } else {
      it->second += 1;
    }
#if DEBUG
    LOG(INFO) << "-------------------- after adding " << number;
    for (auto v : vals_) {
      LOG(INFO) << v << ":" << cnt_[v];
    }
#endif
  }

  /** Find if there exists any pair of numbers which sum is equal to the value.
   */
  bool find(int val) {
    auto it = cache_.find(val);
    if (it != cache_.end()){
      return true;
    }

    for (auto cur : vals_) {
      int64_t target = val - cur;
      auto it = cnt_.find(target);
      if (it == cnt_.end()) {
        continue;
      }

      if (target == cur && it->second >= 2) {
        cache_.insert(val);
        return true;
      } else if (target != cur && it->second >= 1) {
        cache_.insert(val);
        return true;
      }
    }
    return false;
  }
};
