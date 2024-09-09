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
  const int base = 1e9 + 7;
  int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    vector<vector<int>> dp(101, vector<int>(201, -1));
    return dfs(locations, start, finish, fuel, dp);
  }
  int dfs(vector<int>& locations, int start, int finish, int fuel,
          vector<vector<int>>& dp) {
    if (dp[start][fuel] >= 0) return dp[start][fuel];
    int ret = (start == finish) ? 1 : 0;
    for (int i = 0; i < locations.size(); i++) {
      if (i == start) continue;
      int charge = abs(locations[start] - locations[i]);
      if (fuel >= charge) {
        ret += dfs(locations, i, finish, fuel - charge, dp);
        ret = ret % base;
      }
    }

    dp[start][fuel] = ret;
    return ret;
  }
};
