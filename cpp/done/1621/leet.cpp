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

constexpr int base = 1e9 + 7;
int dp[1001][1000] = {};
class Solution {
 public:
  int numberOfSets(int n, int k) { return helper(n, k); }
  int helper(int n, int k) {
    if (n == k) return 0;
    if (n < k) return 0;
    if (dp[n][k] > 0) return dp[n][k];

    if (k == 1) {
      int ans = (n * (n - 1) / 2);
      dp[n][k] = ans;
      return ans;
    }

    int ans = helper(n - 1, k);
    for (int len = 1; len <= n; len++) {
      ans = (ans + helper(n - len, k - 1)) % base;
    }
    dp[n][k] = ans;
    // LOG(INFO) << "dp[" << n << "][" << k << "]=" << ans;
    return ans;
  }
};
