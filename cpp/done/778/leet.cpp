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
  int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    const int bound = n * n;
    map<ipair, ipair> parents;
    map<ipair, int> ranks;
    vector<ipair> pos(bound);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        pos[grid[i][j]] = {i, j};
        parents[{i, j}] = {i, j};
        ranks[{i, j}] = 0;
      }
    }
    for (int i = 1; i < bound; i++) {
      auto [r, c] = pos[i];
      vector<ipair> nbrs{{r + 1, c}, {r - 1, c}, {r, c + 1}, {r, c - 1}};
      for (auto [nr, nc] : nbrs) {
        if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
        if (grid[nr][nc] < grid[r][c]) {
          // LOG(INFO) << "join (" << nr << ", " << nc << ", (" << r << ", " <<
          // c << ")";
          join(parents, ranks, nr, nc, r, c);
        }
        if (find(parents, 0, 0) == find(parents, n - 1, n - 1)) {
          return i;
        }
      }
    }
    return bound;
  }
  ipair find(map<ipair, ipair>& parents, int r, int c) {
    ipair cur_parent = parents[{r, c}];
    if (cur_parent != ipair{r, c}) {
      parents[{r, c}] = find(parents, cur_parent.first, cur_parent.second);
    }
    return parents[{r, c}];
  }
  void join(map<ipair, ipair>& parents, map<ipair, int>& ranks, int u, int v,
            int x, int y) {
    ipair uroot = find(parents, u, v);
    ipair xroot = find(parents, x, y);
    if (ranks[uroot] == ranks[xroot]) {
      ranks[xroot] += 1;
      parents[uroot] = xroot;
    } else if (ranks[uroot] < ranks[xroot]) {
      parents[uroot] = xroot;
    } else {
      parents[xroot] = uroot;
    }
  }
};
