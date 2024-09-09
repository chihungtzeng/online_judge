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
  int longestPalindromeSubseq(string s) {
    if (s.size() == 0) return 0;
    vector<vector<int>> dp(s.size(), vector<int>(s.size()));
    for (int offset = 0; offset < s.size(); offset++) {
      for (int i = 0; i < s.size(); i++) {
        int j = i + offset;
        if (j >= s.size()) break;
        if (offset == 0)
          dp[i][i] = 1;
        else if (offset == 1 && s[i] != s[j])
          dp[i][j] = 1;
        else if (offset == 1 && s[i] == s[j])
          dp[i][j] = 2;
        else if (offset == 2 && s[i] != s[j])
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        else if (offset == 2 && s[i] == s[j])
          dp[i][j] = 3;
        else if (offset > 2 && s[i] != s[j])
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        else
          dp[i][j] = dp[i + 1][j - 1] + 2;
      }
    }
    return dp[0][s.size() - 1];
  }
};
