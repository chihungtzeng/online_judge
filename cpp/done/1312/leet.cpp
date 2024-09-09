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

class Solution {
 public:
  int minInsertions(string s) {
    const int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int ell = 1; ell <= n; ell++) {
      for (int i = 0; i < n; i++) {
        int j = i + ell - 1;
        if (j >= n) continue;
        if (ell == 1) {
          dp[ell][i] = 0;
        } else if (ell == 2) {
          dp[ell][i] = (s[i] == s[j]) ? 0 : 1;
        } else {
          dp[ell][i] = (s[i] == s[j])
                           ? dp[ell - 2][i + 1]
                           : 1 + min(dp[ell - 1][i], dp[ell - 1][i + 1]);
        }
      }
    }
#if 0
    for(int ell = 0; ell <=n; ell++){
      LOG(INFO) << dp[ell];
    }
#endif
    return dp[n][0];
  }
};
