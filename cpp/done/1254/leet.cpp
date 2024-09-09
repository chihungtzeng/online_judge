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

struct DisjointSet {
  vector<int> ranks_, parents_;
  DisjointSet(int n) : ranks_(n), parents_(n) {
    for (int i = 0; i < n; i++) {
      parents_[i] = i;
    }
  }
  int find(const int u) {
    if (u != parents_[u]) {
      parents_[u] = find(parents_[u]);
    }
    return parents_[u];
  }
  void join(const int u, const int v) {
    int ur = find(u), vr = find(v);
    if (ur == vr) return;
    if (ranks_[ur] < ranks_[vr]) {
      parents_[ur] = vr;
    } else if (ranks_[ur] == ranks_[vr]) {
      parents_[ur] = vr;
      ranks_[vr]++;
    } else {
      parents_[vr] = ur;
    }
  }
};

class Solution {
 public:
  const vector<int> dr{1, 0}, dc{0, 1};
  int closedIsland(vector<vector<int>>& grid) {
    const int rows = grid.size();
    const int cols = grid[0].size();
    DisjointSet ds(rows * cols);

    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (grid[r][c] == 1) {
          // Water
          continue;
        }

        for (int i = 0; i < 2; i++) {
          int nr = r + dr[i];
          int nc = c + dc[i];

          if (nr >= rows || nc >= cols) continue;
          if (grid[nr][nc] == 0) {
            ds.join(r * cols + c, nr * cols + nc);
          }
        }
      }
    }
    unordered_map<int, bool> lands;
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (grid[r][c] == 1) continue;
        int root = ds.find(r * cols + c);
        if (lands.find(root) == lands.end()) {
          lands[root] = true;
        }
        if (lands[root] &&
            (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)) {
          lands[root] = false;
        }
      }
    }
    int ans = 0;
    for (auto& [key, closed] : lands) {
      if (closed) ans++;
    }

    return ans;
  }
};

