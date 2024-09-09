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

using ituple = tuple<int, int, int>;
class Solution {
 public:
  const vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
  int orangesRotting(vector<vector<int>>& grid) {
    const int rows = grid.size();
    const int cols = grid[0].size();
    vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
    auto cmp = [](const auto& a, const auto& b) {
      auto [d1, r1, c1] = a;
      auto [d2, r2, c2] = b;
      return d1 > d2;
    };
    priority_queue<ituple, vector<ituple>, decltype(cmp)> pq(cmp);
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (grid[r][c] == 2) {
          dist[r][c] = 0;
          pq.push({0, r, c});
        }
      }
    }

    while (!pq.empty()) {
      auto [d, r, c] = pq.top();
      pq.pop();
      for (int i = 0; i < 4; i++) {
        int nr = r + dx[i];
        int nc = c + dy[i];
        if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) {
          continue;
        }
        if (grid[nr][nc] == 1 && dist[nr][nc] > d + 1) {
          dist[nr][nc] = d + 1;
          pq.push({dist[nr][nc], nr, nc});
        }
      }
    }
    int ans = 0;
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (grid[r][c] != 0) {
          ans = max(ans, dist[r][c]);
        }
      }
    }
    if (ans == INT_MAX)
      return -1;
    else
      return ans;
  }
};

