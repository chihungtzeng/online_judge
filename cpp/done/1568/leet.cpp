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
  const vector<pair<int, int>> offsets{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int minDays(vector<vector<int>>& grid) {
    auto nisland = num_island_of(grid);
    if (nisland != 1) return 0;

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 0) continue;
        grid[i][j] = 0;
        if (num_island_of(grid) != 1) {
          return 1;
        }
        grid[i][j] = 1;
      }
    }
    return 2;
  }
  int near_ones(vector<vector<int>>& grid, int r, int c) {
    int cnt = 0;
    for (auto& [rdiff, cdiff] : offsets) {
      int nr = r + rdiff;
      int nc = c + cdiff;
      if (nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size())
        continue;
      if (grid[nr][nc] > 0) cnt++;
    }
    return cnt;
  }

  int num_island_of(vector<vector<int>> grid) {
    int island_id = 2;
    int num_island = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 1) {
          color_island(grid, i, j, island_id++);
          num_island++;
        }
      }
    }
    return num_island;
  }
  void color_island(vector<vector<int>>& grid, int r, int c, int color) {
    vector<pair<int, int>> stack;
    stack.push_back({r, c});
    while (!stack.empty()) {
      auto [r, c] = stack.back();
      grid[r][c] = color;
      stack.pop_back();
      for (auto& [rdiff, cdiff] : offsets) {
        int nr = r + rdiff;
        int nc = c + cdiff;
        if (nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size())
          continue;
        if (grid[nr][nc] == 1) {
          stack.push_back({nr, nc});
        }
      }
    }
  }
};
