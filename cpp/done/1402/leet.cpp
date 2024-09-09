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
  int maxSatisfaction(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());
    vector<int> dp(nums.size());
    dp[0] = max(0, nums[0]);
    int s = dp[0];
    for (int i = 1; i < nums.size(); i++) {
      if (s + nums[i] > 0) {
        dp[i] = dp[i - 1] + s + nums[i];
        s += nums[i];
      } else {
        dp[i] = dp[i - 1];
      }
    }
    return dp.back();
  }
};
