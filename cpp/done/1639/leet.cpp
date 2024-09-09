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
  vector<vector<int>> nchar_at_pos;
  int n, m;

  int numWays(vector<string>& words, string target) {
    n = words[0].size();
    m = target.size();
    nchar_at_pos = vector<vector<int>>(128, vector<int>(n));
    for (auto& w : words) {
      for (int i = 0; i < n; i++) {
        nchar_at_pos[w[i]][i] += 1;
      }
    }
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return helper(words, target, dp, 0, 0);
  }
  int helper(vector<string>& words, string& target, vector<vector<int>>& dp,
             const int i, const int j) {
    if (j == m) return 1;
    if (i == n) return 0;
    if (dp[i][j] >= 0) return dp[i][j];
    char ch = target[j];
    int64_t ans = helper(words, target, dp, i + 1, j);
    if (nchar_at_pos[ch][i] > 0) {
      ans = ans + helper(words, target, dp, i + 1, j + 1) * static_cast<int64_t>(nchar_at_pos[ch][i]);
      // ans = ans + helper(words, target, dp, i + 1, j + 1) * nchar_at_pos[ch][i];
      ans %= base;
    }
    dp[i][j] = ans;
    return ans;
  }
};
