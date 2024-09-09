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
    vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(strs.size() + 1)));
    const int nstrs = strs.size();
    int ans = 0;

    for (int i = 1; i <= nstrs; i++) {
      auto [s0, s1] = count01(strs[i - 1]);
      for (int n0 = 0; n0 <= m; n0++) {
        for (int n1 = 0; n1 <= n; n1++) {
          int t0 = n0 - s0, t1 = n1 - s1;
          if (t0 < 0 || t1 < 0) {
            dp[n0][n1][i] = dp[n0][n1][i - 1];
          } else {
            int can = 0;
            for (int k = i - 1; k >= 1; k--) {
              can = max(can, dp[t0][t1][k]);
            }
            dp[n0][n1][i] = 1 + can;
          }
          ans = max(ans, dp[n0][n1][i]);
        }
      }
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
