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

const vector<int> dr{0, 0, 1, -1}, dc{1, -1, 0, 0};
class Solution {
 public:
  vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    const int nrows = isWater.size();
    const int ncols = isWater[0].size();
    vector<vector<int>> height(nrows, vector<int>(ncols, INT_MAX));
    deque<int> q;

    for (int r = 0; r < nrows; r++) {
      for (int c = 0; c < ncols; c++) {
        if (isWater[r][c]) {
          height[r][c] = 0;
          q.push_back((r << 10) + c);
        }
      }
    }
    while (!q.empty()) {
      int pos = q.front();
      q.pop_front();
      const int r = pos >> 10;
      const int c = pos & 0x3ff;
      for (int i = 0; i < 4; i++) {
        const int nr = r + dr[i];
        const int nc = c + dc[i];
        if (nr < 0 || nr >= nrows || nc < 0 || nc >= ncols) continue;
        if (height[nr][nc] != INT_MAX) continue;
        height[nr][nc] = pick(height, nr, nc, nrows, ncols);
        q.push_back((nr << 10) + nc);
      }
    }
    return height;
  }
  int pick(vector<vector<int>>& height, const int r, const int c,
           const int nrows, const int ncols) {
    int m = INT_MAX;
    for (int i = 0; i < 4; i++) {
      const int nr = r + dr[i];
      const int nc = c + dc[i];
      if (nr < 0 || nr >= nrows || nc < 0 || nc >= ncols) continue;
      m = min(m, height[nr][nc]);
    }
    return m + 1;
  }
};
