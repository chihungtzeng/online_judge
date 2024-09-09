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

class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int total = std::accumulate(nums.begin(), nums.end(), 0);
    if (total % 2 != 0) {
      return false;
    }
    int expect = total / 2;
    vector<bool> can(expect + 1, false);
    can[0] = true;
    for (auto n : nums) {
      for (int i = expect; i >= n; i--) {
        can[i] = can[i] || can[i - n];
      }
    }
    return can[expect];
  }
};
