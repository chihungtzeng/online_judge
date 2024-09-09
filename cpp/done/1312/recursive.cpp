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
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
    return helper(s, 0, s.size() - 1, dp);
  }

  int helper(string& s, int from, int to, vector<vector<int>>& dp) {
    // LOG(INFO) << "from: " << from << " to: " << to;
    if (from > to) return 0;
    if (dp[from][to] >= 0) {
      return dp[from][to];
    }
    int i = from, j = to;
    while (i < j && s[i] == s[j]) {
      i++;
      j--;
    }
    int ret = INT_MAX;
    if (i >= j) {
      ret = 0;
    } else {
      ret = helper(s, i + 1, j, dp) + 1;
      ret = min(ret, helper(s, i, j - 1, dp) + 1);
    }
    dp[from][to] = ret;
    return ret;
  }
};
