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
class Solution {
 public:
  int countVowelPermutation(int n) {
    vector<vector<int64_t>> dp(n + 1, vector<int64_t>(5));
    for (int i = 0; i < 5; i++) {
      dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
      int j = i - 1;
      dp[i][0] = dp[j][1] + dp[j][2] + dp[j][4];
      dp[i][1] = dp[j][0] + dp[j][2];
      dp[i][2] = dp[j][1] + dp[j][3];
      dp[i][3] = dp[j][2];
      dp[i][4] = dp[j][2] + dp[j][3];
      for (j = 0; j < 5; j++) {
        dp[i][j] %= base;
      }
    }
    int64_t ans = 0;
    for (int j = 0; j < 5; j++) {
      ans += dp[n][j];
    }
    return ans % base;
  }
};
