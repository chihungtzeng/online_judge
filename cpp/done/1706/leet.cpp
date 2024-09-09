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
  vector<int> findBall(vector<vector<int>>& grid) {
    const int rows = grid.size();
    const int cols = grid[0].size();
    if (cols == 1) {
      return {-1};
    }
    vector<int> ans(cols);

    for (int c = 0; c < cols; c++) {
      int nc = c;
      bool dead_end = false;
      for (int r = 0; r < rows && !dead_end; r++) {
        if (nc == 0) {
          if (grid[r][nc] == -1) {
            dead_end = true;
          } else if (cols > 0 && grid[r][nc] == 1 && grid[r][nc + 1] == 1) {
            nc++;
          } else {
            dead_end = true;
          }
        } else if (nc == cols - 1) {
          if (grid[r][nc] == 1) {
            dead_end = true;
          } else if (cols > 0 && grid[r][nc] == -1 && grid[r][nc - 1] == -1) {
            nc--;
          } else {
            dead_end = true;
          }
        } else {
          if (grid[r][nc] == 1 && grid[r][nc + 1] == 1) {
            nc++;
          } else if (grid[r][nc] == -1 && grid[r][nc - 1] == -1) {
            nc--;
          } else {
            dead_end = true;
          }
        }
      }
      if (!dead_end) {
        ans[c] = nc;
      } else {
        ans[c] = -1;
      }
    }
    return ans;
  }
};
