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
  const vector<int> dx{-1, 0, 1, 0}, dy{0, -1, 0, 1};
  int islandPerimeter(vector<vector<int>>& grid) {
    const int rows = grid.size();
    const int cols = grid[0].size();
    int edges = 0;
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (grid[r][c] == 0) continue;
        for (int i = 0; i < 4; i++) {
          int nr = r + dx[i];
          int nc = c + dy[i];
          if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) {
            edges++;
          } else if (grid[nr][nc] == 0) {
            edges++;
          }
        }
      }
    }
    return edges;
  }
};
