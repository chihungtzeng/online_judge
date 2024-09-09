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
  vector<int> parents_, ranks_;
  DisjointSet(int n) : parents_(n), ranks_(n) {
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

using ipair = pair<int, int>;
class Solution {
 public:
  vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList,
                                         vector<vector<int>>& queries) {
    auto cmp = [](const auto& e1, const auto& e2) { return e1[2] < e2[2]; };
    sort(edgeList.begin(), edgeList.end(), cmp);
    const int nq = queries.size();
    const int nedges = edgeList.size();

    vector<bool> ans(nq);
    for (int i = 0; i < nq; i++) {
      queries[i].push_back(i);
    }
    sort(queries.begin(), queries.end(), cmp);

    DisjointSet ds(n);
    int j = 0;
    for (int i = 0; i < nq; i++) {
      while (j < nedges && edgeList[j][2] < queries[i][2]) {
        int u = edgeList[j][0], v = edgeList[j][1];
        ds.join(u, v);
        j++;
      }
      int u = queries[i][0], v = queries[i][1], idx = queries[i][3];
      ans[idx] = bool(ds.find(u) == ds.find(v));
    }
    return ans;
  }
};
