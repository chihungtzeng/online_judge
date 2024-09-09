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
  int n;
  vector<int> parents, ranks;
  DisjointSet(int nelem) : n(nelem), parents(nelem), ranks(nelem) {
    for (int i = 0; i < n; i++) {
      parents[i] = i;
      ranks[i] = 0;
    }
  }
  int find(int u) {
    if (u != parents[u]) {
      parents[u] = find(parents[u]);
    }
    return parents[u];
  }
  void join(int u, int v) {
    int ur = find(u);
    int vr = find(v);
    if (ur == vr) return;
    if (ranks[ur] < ranks[vr]) {
      parents[ur] = vr;
    } else if (ranks[ur] == ranks[vr]) {
      parents[ur] = vr;
      ranks[vr] += 1;
    } else {
      parents[vr] = ur;
    }
  }
};

class Solution {
 public:
  vector<bool> areConnected(int n, int threshold,
                            vector<vector<int>>& queries) {
    if (threshold == 0) {
      return vector<bool>(queries.size(), true);
    }
    DisjointSet ds(n + 1);
    for (int i = threshold + 1; i <= n; i++) {
      int j = i + i;
      while (j <= n) {
        ds.join(i, j);
        j += i;
      }
    }
    vector<bool> ans;
    ans.reserve(queries.size());
    for (auto& q : queries) {
      int u = q[0], v = q[1];
      ans.push_back(ds.find(u) == ds.find(v));
    }
    return ans;
  }
};
