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

using ipair = pair<int, int>;
class Solution {
 public:
  int nrows_, ncols_;
  const vector<ipair> offsets_{{0, 1}, {1, 0}};
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    nrows_ = grid.size();
    if (nrows_ == 0) return 0;
    ncols_ = grid[0].size();
    if (ncols_ == 0) return 0;
    vector<vector<ipair>> parents(nrows_, vector<ipair>(ncols_));
    vector<vector<int>> ranks(nrows_, vector<int>(ncols_));
    for (int i = 0; i < nrows_; i++) {
      for (int j = 0; j < ncols_; j++) {
        parents[i][j] = ipair{i, j};
      }
    }
    for (int i = 0; i < nrows_; i++) {
      for (int j = 0; j < ncols_; j++) {
        for (const auto& offset : offsets_) {
          if (grid[i][j] == 0) continue;
          int r = i + offset.first;
          int c = j + offset.second;
          if (0 <= r && r < nrows_ && 0 <= c && c < ncols_ && grid[r][c] == 1) {
            join(parents, ranks, i, j, r, c);
          }
        }
      }
    }
    map<ipair, int> area;
    for (int i = 0; i < nrows_; i++) {
      for (int j = 0; j < ncols_; j++) {
        if (grid[i][j] == 0) continue;
        area[find(parents, i, j)] += 1;
      }
    }
#if 0
    for (int i = 0; i < nrows_; i++) {
      for (int j = 0; j < ncols_; j++) {
        LOG(INFO) << "parents(" << i << ", " << j << "): " << parents[i][j] << " val: " << grid[i][j];
      }
    }
#endif
    int ret = 0;
    for (auto& [key, val] : area) {
      ret = max(ret, val);
    }
    return ret;
  }
  ipair find(vector<vector<ipair>>& parents, int r, int c) {
    if (parents[r][c] != ipair{r, c}) {
      parents[r][c] = find(parents, parents[r][c].first, parents[r][c].second);
    }
    return parents[r][c];
  }
  void join(vector<vector<ipair>>& parents, vector<vector<int>>& ranks, int r1,
            int c1, int r2, int c2) {
    // LOG(INFO) << "join (" << r1 << ", " << c1 << ") with (" << r2 << ", " <<
    // c2 << ")";
    ipair p1 = find(parents, r1, c1);
    ipair p2 = find(parents, r2, c2);
    if (p1 == p2) return;
    if (ranks[p1.first][p1.second] < ranks[p2.first][p2.second]) {
      parents[p1.first][p1.second] = p2;
    } else if (ranks[p1.first][p1.second] > ranks[p2.first][p2.second]) {
      parents[p2.first][p2.second] = p1;
    } else {
      parents[p1.first][p1.second] = p2;
      ranks[p2.first][p2.second] += 1;
    }
    // LOG(INFO) << "parents(r1, c1): " << parents[r1][c1] << ",
    // parents[r2][c2]: " << parents[r2][c2];
  }
};
