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
  int minCost(int n, vector<int>& cuts) {
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(cuts.size(), vector(cuts.size(), -1));
    return helper(n, cuts, dp, 0, cuts.size() - 1, 0, n);
  }
  int helper(int n, vector<int>& cuts, vector<vector<int>>& dp, int left,
             int right, int from, int to) {
    if (left > right) return 0;
    if (dp[left][right] >= 0) return dp[left][right];
    int res = INT_MAX;
    for (int i = left; i <= right; i++) {
      int cost = to - from;
      int lmax = helper(n, cuts, dp, left, i - 1, from, cuts[i]);
      int rmax = helper(n, cuts, dp, i + 1, right, cuts[i], to);
      res = min(res, cost + lmax + rmax);
    }
    dp[left][right] = res;
    return res;
  }
};
