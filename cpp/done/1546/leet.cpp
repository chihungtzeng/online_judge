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
  int maxNonOverlapping(vector<int>& nums, int target) {
    unordered_map<int, int> psum;
    vector<int> dp(nums.size() + 1, 0);
    psum[0] = 0;
    dp[0] = 0;
    int s = 0;
    for (int i = 1; i <= nums.size(); i++) {
      s += nums[i-1];
      auto it = psum.find(s - target);
      if (it == psum.end()) {
        dp[i] = dp[i - 1];
      } else {
        dp[i] = max(dp[i - 1], dp[it->second] + 1);
      }
      psum[s] = i;
    }
    return dp.back();
  }
};
