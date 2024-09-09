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
  const int base = 1e9 + 7;
  int kInversePairs(int n, int k) {
    vector<vector<int>> dp(1001, vector<int>(1001, -1));
    return helper(dp, n, k);
  }
  int helper(vector<vector<int>>& dp, int n, int k) {
    if (n == 0) return 0;
    if (k < 0) return 0;
    if (k == 0) return 1;
    if (k == 1) return n - 1;
    if (dp[n][k] >= 0) return dp[n][k];
    int bound = (n * (n - 1)) >> 1;
    if (k > bound) {
      dp[n][k] = 0;
      // LOG(INFO) << "dp[" << n << "][" << k << "]:" << dp[n][k];
      return 0;
    }
    if (k == bound) {
      dp[n][k] = 1;
      // LOG(INFO) << "dp[" << n << "][" << k << "]:" << dp[n][k];
      return 1;
    }
    int ans = 0;
    for (int i = k; i >= k - n + 1; i--) {
      ans = (ans + helper(dp, n - 1, i)) % base;
    }
    dp[n][k] = ans;
    // LOG(INFO) << "dp[" << n << "][" << k << "]:" << dp[n][k];
    return ans;
  }
};
