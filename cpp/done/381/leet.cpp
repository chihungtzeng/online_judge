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
void dump_cached_idx(unordered_map<int, unordered_set<int>>& cached_idx);

class RandomizedCollection {
 public:
  unordered_map<int, unordered_set<int>> cached_idx_;
  vector<int> vals_;
  /** Initialize your data structure here. */
  RandomizedCollection() { srand(time(NULL)); }

  /** Inserts a value to the collection. Returns true if the collection did not
   * already contain the specified element. */
  bool insert(int val) {
    auto ret = bool(cached_idx_.find(val) == cached_idx_.end());
    cached_idx_[val].insert(vals_.size());
    vals_.push_back(val);
    return ret;
  }

  /** Removes a value from the collection. Returns true if the collection
   * contained the specified element. */
  bool remove(int val) {
    if (cached_idx_.find(val) == cached_idx_.end()) {
      return false;
    }
    auto idx_rm = *cached_idx_[val].begin();
    auto last = vals_.back();
    int idx_last = vals_.size() - 1;
    auto last_idxes = cached_idx_[last];

    swap(vals_[idx_rm], vals_[idx_last]);
    vals_.pop_back();
    cached_idx_[val].erase(idx_rm);
    if (cached_idx_[val].empty()) {
      cached_idx_.erase(val);
    }

    if (idx_rm != idx_last) {
      cached_idx_.find(last)->second.erase(idx_last);
      cached_idx_.find(last)->second.insert(idx_rm);
    }
    return true;
  }

  /** Get a random element from the collection. */
  int getRandom() { return vals_[rand() % vals_.size()]; }
};
