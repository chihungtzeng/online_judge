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

using ipair = pair<int, int>;
class Solution {
 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    //    vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1,
    //    vector<int>(strs.size() + 1)));
    vector<vector<int>> dp[2];

    dp[0] = vector<vector<int>>(m + 1, vector<int>(n + 1));
    dp[1] = vector<vector<int>>(m + 1, vector<int>(n + 1));
    // int dp[101][101] = {};
    const int nstrs = strs.size();
    int ans = 0;

    int cur = 0;
    int prev = 1;
    for (int i = 1; i <= nstrs; i++) {
      auto [s0, s1] = count01(strs[i - 1]);
      for (int n0 = 0; n0 <= m; n0++) {
        for (int n1 = 0; n1 <= n; n1++) {
          int t0 = n0 - s0, t1 = n1 - s1;
          if (t0 < 0 || t1 < 0) {
            dp[cur][n0][n1] = dp[prev][n0][n1];
          } else {
            dp[cur][n0][n1] = max(dp[prev][n0][n1], 1 + dp[prev][t0][t1]);
          }
          ans = max(ans, dp[cur][n0][n1]);
        }
      }
#if 0
      LOG(INFO) << "after " << i << "-th string: " << strs[i - 1];
      for (int k = 0; k <= m; k++) {
        LOG(INFO) << dp[cur][k];
      }
#endif
      cur = 1 - cur;
      prev = 1 - prev;
    }
    return ans;
  }
  ipair count01(string& s) {
    int n0 = 0, n1 = 0;
    for (auto ch : s) {
      if (ch == '0')
        n0++;
      else
        n1++;
    }
    return ipair{n0, n1};
  }
};
