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
  bool isPrintable(vector<vector<int>>& grid) {
    const int rows = grid.size();
    const int cols = grid[0].size();
    vector<int> up(61, INT_MAX), left(61, INT_MAX), right(61, INT_MIN),
        down(61, INT_MIN);
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        int color = grid[r][c];
        up[color] = min(up[color], r);
        down[color] = max(down[color], r);
        left[color] = min(left[color], c);
        right[color] = max(right[color], c);
      }
    }
    vector<bool> valid(61, false);
    int nvalid = 0;
    bool done = false;
    while (!done) {
      bool progress = false;
      for (int color = 60; color >= 1; color--) {
        if (up[color] == INT_MAX) {
          valid[color] = true;
        }
        if (valid[color]) continue;
        bool rect = true;
        for (int r = up[color]; r <= down[color]; r++) {
          for (int c = left[color]; c <= right[color]; c++) {
            if (grid[r][c] != color && grid[r][c] != INT_MAX) rect = false;
          }
        }
        if (rect) {
          valid[color] = true;
          progress = true;

          for (int r = up[color]; r <= down[color]; r++) {
            for (int c = left[color]; c <= right[color]; c++) {
              grid[r][c] = INT_MAX;
            }
          }
        }
      }
      if (!progress) done = true;
    }
    for (int i = 1; i < 61; i++) {
      if (!valid[i]) return false;
    }

    return true;
  }
};
