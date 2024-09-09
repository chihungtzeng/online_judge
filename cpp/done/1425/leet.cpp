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
  int constrainedSubsetSum(vector<int>& nums, int k) {
    vector<int> dp(nums.size());
    deque<int> maxq;
    int ans = nums[0];
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
#if 0    
      LOG(INFO) << "i: " << i << " nums[i]: " << nums[i];
      LOG(INFO) << "dp: " << dp;
      LOG(INFO) << "maxq: " << maxq;
#endif
      int j = i - 1;
      while (!maxq.empty() && maxq.back() < dp[j]) maxq.pop_back();
      maxq.push_back(dp[j]);
      dp[i] = max(nums[i], maxq.front() + nums[i]);
      if (i - k >= 0 && dp[i - k] == maxq.front()) {
        maxq.pop_front();
      }
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};
