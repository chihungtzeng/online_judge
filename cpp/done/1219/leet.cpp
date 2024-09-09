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
  int rows, cols;
  const vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
  int getMaximumGold(vector<vector<int>>& grid) {
    rows = grid.size();
    cols = grid[0].size();
    int ans = 0;
    vector<vector<bool>> vis(rows, vector<bool>(cols, false));
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (grid[r][c] == 0) continue;

        ans = max(ans, dfs(grid, r, c, vis, 0));
      }
    }
    return ans;
  }

  int dfs(vector<vector<int>>& grid, const int r, const int c,
          vector<vector<bool>>& vis, int gold) {
    vis[r][c] = true;
    gold += grid[r][c];
    int ret = gold;
    for (int i = 0; i < 4; i++) {
      int nr = r + dx[i];
      int nc = c + dy[i];
      if (oob(nr, nc)) continue;
      if (grid[nr][nc] == 0) continue;
      if (vis[nr][nc]) continue;

      ret = max(ret, dfs(grid, nr, nc, vis, gold));
    }
    vis[r][c] = false;
    return ret;
  }

  bool oob(const int r, const int c) {
    return bool(r < 0 || r >= rows || c < 0 || c >= cols);
  }
};
