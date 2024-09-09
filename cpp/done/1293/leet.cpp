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

using ituple = tuple<int, int, int, int>;  // distance, r, c, nrm
using ipair = pair<int, int>;
class Solution {
 public:
  const vector<pair<int, int>> offset{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  int shortestPath(vector<vector<int>>& grid, int k) {
    int rows = grid.size();
    int cols = grid[0].size();

    if (k > rows + cols) {
      return rows + cols - 2;
    }
    vector<vector<vector<int>>> dist(
        rows, vector<vector<int>>(cols, vector<int>(k + 1, INT_MAX)));
    deque<ituple> q;
    dist[0][0][0] = 0;
    q.push_back({0, 0, 0, 0});
    while (!q.empty()) {
      auto [dis, r, c, nrm] = q.front();
      //      LOG(INFO) << "handle " << ipair{r, c} << " with dist: " << dis <<
      //      " nrm: " << nrm;
      q.pop_front();
      for (int i = 0; i < 4; i++) {
        int nr = r + offset[i].first, nc = c + offset[i].second;
        if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) {
          continue;
        }
        int nnrm = nrm;
        if (grid[nr][nc] == 1) {
          nnrm++;
        }
        if (nnrm <= k && dist[nr][nc][nnrm] > dis + 1) {
          dist[nr][nc][nnrm] = dis + 1;
          q.push_back({dis + 1, nr, nc, nnrm});
        }
      }
    }
    int ans = INT_MAX;
    for (int i = 0; i <= k; i++) {
      ans = min(ans, dist[rows - 1][cols - 1][i]);
    }
    if (ans == INT_MAX)
      return -1;
    else
      return ans;
  }
};
