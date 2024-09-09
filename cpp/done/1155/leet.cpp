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
  int numRollsToTarget(int d, int f, int target) {
    vector<vector<uint64_t>> dp(d + 1, vector<uint64_t>(max(f, target) + 1));
    for (int i = 1; i <= f; i++) {
      dp[1][i] = 1;
    }
    for (int i = 2; i <= d; i++) {
      for (int j = 1; j <= target; j++) {
        for (int k = 1; k <= f; k++) {
          int lookfor = j - k;
          if (lookfor <= 0) continue;
          dp[i][j] += dp[i - 1][lookfor];
        }
        dp[i][j] %= base;
      }
    }
    return dp[d][target];
  }
};
