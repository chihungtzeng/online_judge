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
  bool hasValidPath(vector<vector<int>>& grid) {
    const int rows = grid.size();
    const int cols = grid[0].size();
    vector<vector<bool>> vis(rows, vector<bool>(cols, false));
    vector<pair<int, int>> stack;
    stack.push_back({0, 0});
    while (!stack.empty()) {
      auto [r, c] = stack.back();
      stack.pop_back();
      vis[r][c] = true;
      for (auto [nr, nc] : next_pos(grid, r, c, rows, cols)) {
        if (vis[nr][nc] == false) {
          stack.push_back({nr, nc});
        }
      }
    }
    return vis[rows - 1][cols - 1];
  }
  vector<pair<int, int>> next_pos(vector<vector<int>>& grid, int r, int c,
                                  int rows, int cols) {
    vector<pair<int, int>> temp, ret;
    int val = grid[r][c];
    if (val == 1) {
      temp.push_back({r, c + 1});
      temp.push_back({r, c - 1});
    } else if (val == 2) {
      temp.push_back({r - 1, c});
      temp.push_back({r + 1, c});
    } else if (val == 3) {
      temp.push_back({r, c - 1});
      temp.push_back({r + 1, c});
    } else if (val == 4) {
      temp.push_back({r, c + 1});
      temp.push_back({r + 1, c});
    } else if (val == 5) {
      temp.push_back({r, c - 1});
      temp.push_back({r - 1, c});
    } else if (val == 6) {
      temp.push_back({r, c + 1});
      temp.push_back({r - 1, c});
    }
    for (auto [nr, nc] : temp) {
      if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
      if (val == 1) {
        if (nc < c &&
            (grid[nr][nc] == 1 || grid[nr][nc] == 4 || grid[nr][nc] == 6)) {
          ret.push_back({nr, nc});
        }
        if (nc > c &&
            (grid[nr][nc] == 1 || grid[nr][nc] == 3 || grid[nr][nc] == 5)) {
          ret.push_back({nr, nc});
        }
      }
      if (val == 2) {
        if (nr < r &&
            (grid[nr][nc] == 2 || grid[nr][nc] == 3 || grid[nr][nc] == 4)) {
          ret.push_back({nr, nc});
        }
        if (nr > r &&
            (grid[nr][nc] == 2 || grid[nr][nc] == 5 || grid[nr][nc] == 6)) {
          ret.push_back({nr, nc});
        }
      }
      if (val == 3) {
        if (nc < c &&
            (grid[nr][nc] == 1 || grid[nr][nc] == 4 || grid[nr][nc] == 6)) {
          ret.push_back({nr, nc});
        }
        if (nr > r &&
            (grid[nr][nc] == 2 || grid[nr][nc] == 5 || grid[nr][nc] == 6)) {
          ret.push_back({nr, nc});
        }
      }
      if (val == 4) {
        if (nc > c &&
            (grid[nr][nc] == 1 || grid[nr][nc] == 3 || grid[nr][nc] == 5)) {
          ret.push_back({nr, nc});
        }
        if (nr > r &&
            (grid[nr][nc] == 2 || grid[nr][nc] == 5 || grid[nr][nc] == 6)) {
          ret.push_back({nr, nc});
        }
      }
      if (val == 5) {
        if (nc < c &&
            (grid[nr][nc] == 1 || grid[nr][nc] == 4 || grid[nr][nc] == 6)) {
          ret.push_back({nr, nc});
        }
        if (nr < r &&
            (grid[nr][nc] == 2 || grid[nr][nc] == 3 || grid[nr][nc] == 4)) {
          ret.push_back({nr, nc});
        }
      }
      if (val == 6) {
        if (nc > c &&
            (grid[nr][nc] == 1 || grid[nr][nc] == 3 || grid[nr][nc] == 5)) {
          ret.push_back({nr, nc});
        }
        if (nr < r &&
            (grid[nr][nc] == 2 || grid[nr][nc] == 3 || grid[nr][nc] == 4)) {
          ret.push_back({nr, nc});
        }
      }
    }
    return ret;
  }
};
