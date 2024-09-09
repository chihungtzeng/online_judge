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

using ipair = pair<int, int>;
class Solution {
 public:
  const vector<pair<int, int>> dirs{{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  int minCost(vector<vector<int>>& grid) {
    const int rows = grid.size();
    const int cols = grid[0].size();
    vector<vector<int>> depth(rows, vector<int>(cols, -1));
    int nwave = 0;

    auto cur = dfs(grid, depth, {0, 0}, nwave);
    while (depth[rows - 1][cols - 1] < 0) {
      nwave++;
      vector<ipair> next_wave;
      for (auto [r, c] : cur) {
        for (int i = 1; i <= 4; i++) {
          int nr = r + dirs[i].first;
          int nc = c + dirs[i].second;
          if (0 <= nr && nr < rows && 0 <= nc && nc < cols &&
              depth[nr][nc] < 0) {
            auto temp = dfs(grid, depth, {nr, nc}, nwave);
            for (auto& item : temp) next_wave.push_back(item);
          }
        }
      }
      cur = next_wave;
    }

    return depth[rows - 1][cols - 1];
  }

  vector<ipair> dfs(vector<vector<int>>& grid, vector<vector<int>>& depth,
                    ipair start_rc, int d) {
    vector<ipair> stack;
    vector<ipair> ret;
    stack.push_back(start_rc);
    const int rows = grid.size();
    const int cols = grid[0].size();
    while (!stack.empty()) {
      auto [r, c] = stack.back();
      stack.pop_back();
      depth[r][c] = d;
      ret.push_back({r, c});

      int nr = r + dirs[grid[r][c]].first;
      int nc = c + dirs[grid[r][c]].second;
      if (0 <= nr && nr < rows && 0 <= nc && nc < cols && depth[nr][nc] < 0) {
        stack.push_back({nr, nc});
      }
    }
    return ret;
  }
};
