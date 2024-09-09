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
int64_t dp[5001][7][16] = {};
class Solution {
 public:
  int dieSimulator(int n, vector<int>& rollMax) {
    for (int i = 1; i <= 6; i++) {
      dp[1][i][1] = 1;
    }
    for (int i = 2; i <= n; i++) {
      for (int dice = 1; dice <= 6; dice++) {
        for (int rep = 1; rep <= rollMax[dice - 1]; rep++) {
          dp[i][dice][rep] = helper(rollMax, i, dice, rep);
        }
      }
    }
    int64_t ans = 0;
    for (int dice = 1; dice <= 6; dice++) {
      for (int rep = 1; rep <= rollMax[dice - 1]; rep++) {
        ans += dp[n][dice][rep];
      }
    }
    return ans % base;
  }
  int64_t helper(vector<int>& rollMax, int i, int dice, int rep) {
    if (rep == 1) {
      int64_t ret = 0;
      for (int d = 1; d <= 6; d++) {
        if (d == dice) continue;
        for (int r = 1, stop = rollMax[d - 1]; r <= stop; r++) {
          ret += dp[i - 1][d][r];
        }
      }
      ret %= base;
      return ret;
    } else {
      return dp[i - 1][dice][rep - 1];
    }
  }
};
