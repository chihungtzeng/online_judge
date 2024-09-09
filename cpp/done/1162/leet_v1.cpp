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
  const vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
  int maxDistance(vector<vector<int>>& grid) {
    const int n = grid.size();
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    deque<int> q;
    int nland = 0, nsea = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          dist[i][j] = 0;
          q.push_back((i << 8) + j);
          nland++;
        } else {
          nsea++;
        }
      }
    }
    if (nland == 0 || nsea == 0) return -1;
    int ans = 0;
    while (!q.empty()) {
      int pos = q.front();
      q.pop_front();
      int r = pos >> 8;
      int c = pos & 0xff;
      for (int i = 0; i < 4; i++) {
        int nr = r + dx[i];
        int nc = c + dy[i];
        if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
        if (dist[nr][nc] > dist[r][c] + 1) {
          dist[nr][nc] = dist[r][c] + 1;
          q.push_back((nr << 8) + nc);
          ans = dist[nr][nc];
        }
      }
    }
    return ans;
  }
};
