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
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int nrows = matrix.size();
    if (nrows == 0) return {};
    int ncols = matrix[0].size();
    if (ncols == 0) return {};
    vector<vector<int>> ret(nrows, vector<int>(ncols, -1));
    std::deque<vector<int>> queue;
    for (int i = 0; i < nrows; i++) {
      for (int j = 0; j < ncols; j++) {
        if (matrix[i][j] == 0) {
          queue.emplace_back(vector<int>{i, j, 0});
          ret[i][j] = 0;
        }
      }
    }
    const vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (!queue.empty()) {
      auto pv = queue.front();
      queue.pop_front();
      const int r = pv[0], c = pv[1], dist = pv[2];
      for (const auto& dir : dirs) {
        const int nr = r + dir.first;
        const int nc = c + dir.second;
        if (0 <= nr && nr < nrows && 0 <= nc && nc < ncols &&
            ret[nr][nc] == -1) {
          ret[nr][nc] = dist + 1;
          queue.emplace_back(vector<int>{nr, nc, ret[nr][nc]});
        }
      }
    }
    return ret;
  }
};
