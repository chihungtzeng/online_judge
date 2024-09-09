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
  const vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
  int rows, cols;
  int numDistinctIslands(vector<vector<int>>& grid) {
    rows = grid.size();
    cols = grid[0].size();
    unordered_set<string> shapes;
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (grid[r][c] == 1) {
          auto shape = dfs(grid, r, c);
          LOG(INFO) << shape;
          auto it = shapes.find(shape);
          if (it == shapes.end()) {
            shapes.insert(shape);
          }
        }
      }
    }
    return shapes.size();
  }
  string dfs(vector<vector<int>>& grid, int r, int c) {
    string ret;
    grid[r][c] = 0;
    for (int i = 0; i < 4; i++) {
      int nr = r + dx[i];
      int nc = c + dy[i];
      if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;

      if (grid[nr][nc] == 1) {
        ret.push_back(i + '0');
        ret += dfs(grid, nr, nc);
      }
    }
    ret.push_back('b');
    return ret;
  }
};
