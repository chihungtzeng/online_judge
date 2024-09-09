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
  const vector<int> dr{1, -1, 0, 0};
  const vector<int> dc{0, 0, 1, -1};
  bool containsCycle(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!vis[i][j]) {
          bool has_cycle = dfs(grid, i, j, -1, -1, vis);
          if (has_cycle) return true;
        }
      }
    }
    return false;
  }

  bool dfs(vector<vector<char>>& grid, int r, int c, int pr, int pc,
           vector<vector<bool>>& vis) {
    vis[r][c] = true;
    for (int i = 0; i < 4; i++) {
      int nr = r + dr[i];
      int nc = c + dc[i];
      if (nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size())
        continue;
      if (nr == pr && nc == pc) continue;
      if (grid[nr][nc] == grid[r][c] && vis[nr][nc]) {
        return true;
      }
      if (grid[nr][nc] == grid[r][c] && !vis[nr][nc]) {
        if (dfs(grid, nr, nc, r, c, vis)) {
          return true;
        }
      }
    }
    return false;
  }
};
