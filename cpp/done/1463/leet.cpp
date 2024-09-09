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
  int cherryPickup(vector<vector<int>>& grid) {
    const int n = grid.size();
    const int m = grid[0].size();
    vector<vector<vector<int>>> dp(n,
                                   vector<vector<int>>(m, vector<int>(m, -1)));
    return dfs(grid, 0, 0, m - 1, dp, n, m);
  }
  int dfs(vector<vector<int>>& grid, const int row, const int c1, const int c2,
          vector<vector<vector<int>>>& dp, const int n, const int m) {
    if (dp[row][c1][c2] >= 0) return dp[row][c1][c2];
    int ret = grid[row][c1];
    if (c1 != c2) {
      ret += grid[row][c2];
    }
    if (row == n - 1) {
      dp[row][c1][c2] = ret;
      return ret;
    }
    int best = 0;
    for (int i = -1; i <= 1; i++) {
      int next_c1 = c1 + i;
      if (next_c1 < 0 || next_c1 >= m) {
        continue;
      }
      for (int j = -1; j <= 1; j++) {
        int next_c2 = c2 + j;
        if (next_c2 < 0 || next_c2 >= m) {
          continue;
        }
        best = max(best, dfs(grid, row + 1, next_c1, next_c2, dp, n, m));
      }
    }
    ret += best;
    dp[row][c1][c2] = ret;
    return ret;
  }
};
