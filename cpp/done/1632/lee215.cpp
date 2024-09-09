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
  int n_;
  vector<int> parents_, ranks_;
  DisjointSet(int n) : n_(n), parents_(n), ranks_(n) {
    for (int i = 0; i < n; i++) {
      parents_[i] = i;
    }
  }
  int find(int u) {
    if (u != parents_[u]) {
      parents_[u] = find(parents_[u]);
    }
    return parents_[u];
  }
  void join(int u, int v) {
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
  vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    map<int, vector<int>> mp;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        mp[matrix[i][j]].push_back(i * n + j);
      }
    }

    vector<int> rank(m + n, 0);
    vector<vector<int>> res(m, vector<int>(n));

    LOG(INFO) << rank;
    for (auto& it : mp) {
      vector<int> root(m + n, 0);
      iota(begin(root), end(root), 0);

      auto& v = it.second;
      for (auto& a : v) {
        int i = a / n, j = a % n;
        int r1 = find(root, i), r2 = find(root, j + m);
        root[r1] = r2;  // make row point to column
        rank[r2] = max(rank[r1], rank[r2]);
      }

      auto rank2 = rank;
      for (auto& a : v) {
        int i = a / n, j = a % n;
        int r = find(root, i);
        res[i][j] = rank[r] + 1;
        rank2[i] = rank[r] + 1;
        rank2[j + m] = rank[r] + 1;
      }

      rank = move(rank2);
      LOG(INFO) << rank;
    }

    return res;
  }

  int find(vector<int>& root, int x) {
    if (root[x] != x) root[x] = find(root, root[x]);
    return root[x];
  }
};
