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

const vector<int> dc{-1, 0, 1, -1, 1, -1, 0, 1}, dr{-1, -1, -1, 0, 0, 1, 1, 1};
class Solution {
 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
    deque<int> q;
    if (grid[0][0] == 0) {
      q.push_back(0);
      dist[0][0] = 1;
    }
    while (!q.empty()) {
      int pos = q.front();
      q.pop_front();
      int r = pos >> 16;
      int c = pos & 0xffff;
//      LOG(INFO) << "handle " << pair<int, int>{r, c};
      for (int i = 0; i < 8; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;

//        LOG(INFO) << "check " << pair<int, int>{nr, nc};
        if (grid[nr][nc] == 0 && dist[nr][nc] > dist[r][c] + 1) {
          dist[nr][nc] = dist[r][c] + 1;
          q.push_back((nr << 16) + nc);
        }
      }
    }
    if (dist[rows - 1][cols - 1] == INT_MAX)
      return -1;
    else
      return dist[rows - 1][cols - 1];
  }
};
