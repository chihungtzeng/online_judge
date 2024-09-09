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

class RandomizedSet {
 public:
  std::unordered_map<int, int> v_idx_;
  std::vector<int> v_;
  /** Initialize your data structure here. */
  RandomizedSet() { srand(time(NULL)); }

  /** Inserts a value to the set. Returns true if the set did not already
   * contain the specified element. */
  bool insert(int val) {
    if (v_idx_.find(val) != v_idx_.end()) {
      return false;
    }
    v_.push_back(val);
    v_idx_[val] = v_.size() - 1;
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the
   * specified element. */
  bool remove(int val) {
    if (v_idx_.find(val) == v_idx_.end()) {
      return false;
    }
    auto idx = v_idx_[val];
    swap(v_[idx], v_[v_.size() - 1]);
    v_.pop_back();
    v_idx_[v_[idx]] = idx;
    v_idx_.erase(val);
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() { return v_[rand() % v_.size()]; }
};
