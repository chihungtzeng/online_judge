#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> nums_;
  int bound_;

  void dfs(int k) {
    if (k > bound_) {
      return;
    }
    nums_.push_back(k);
    int k10 = k * 10;
    for (int i = 0; i < 10; i++) {
      dfs(k10 + i);
    }
  }

  vector<int> lexicalOrder(int n) {
    nums_.clear();
    nums_.reserve(n);
    bound_ = n;
    for (int i = 1; i < 10; i++) {
      dfs(i);
    }

    return nums_;
  }
};
