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
    const int ur = find(u);
    const int vr = find(v);
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
  const vector<int> dx{1, -1, 0, 0}, dy{0, 0, -1, 1};
  vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
    const int k = positions.size();
    DisjointSet ds(m * n);
    vector<int> ans(k);
    vector<bool> land(m * n);
    int nislands = 0;
    for (int i = 0; i < k; i++) {
      const int r = positions[i][0];
      const int c = positions[i][1];
      const int cur = r * n + c;
      if (land[cur]) {
        ans[i] = nislands;
        continue;
      }
      land[cur] = true;
      nislands++;

      for (int j = 0; j < 4; j++) {
        const int nr = r + dy[j];
        const int nc = c + dx[j];
        if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
          continue;
        }
        const int nbr = nr * n + nc;
        // LOG(INFO) << "nbr: " << nbr << " nr: " << nr << " nc: " << nc;
        if (land[nbr] && ds.find(nbr) != ds.find(cur)) {
          ds.join(nbr, cur);
          nislands--;
        }
      }
      ans[i] = nislands;
    }
    return ans;
  }
};
