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

class Solution {
 public:
  int maxSumDivThree(vector<int>& nums) {
    vector<int> dp(3, 0);
    for (auto v : nums) {
      auto prev_dp = dp;
      for (auto p : prev_dp) {
        int idx = (p + v) % 3;
        dp[idx] = max(dp[idx], p + v);
      }
    }
    return dp[0];
  }
};
