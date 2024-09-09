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

struct DisjointSet {
  int nsets;
  vector<int> parents, ranks;
  DisjointSet(int n) : nsets(n), parents(n), ranks(n) {
    for (int i = 0; i < n; i++) {
      parents[i] = i;
    }
  }
  int find(int u) {
    if (u != parents[u]) {
      parents[u] = find(parents[u]);
    }
    return parents[u];
  }
  void join(int u, int v) {
    int uroot = find(u), vroot = find(v);
    if (uroot == vroot) return;

    if (ranks[uroot] < ranks[vroot])
      parents[uroot] = vroot;
    else if (ranks[uroot] == ranks[vroot]) {
      parents[uroot] = vroot;
      ranks[vroot]++;
    } else {
      parents[vroot] = uroot;
    }
    nsets--;
  }
};

class Solution {
 public:
  int makeConnected(int n, vector<vector<int>>& conns) {
    if (conns.size() < n - 1) return -1;

    DisjointSet ds(n);
    for (auto& c : conns) {
      ds.join(c[0], c[1]);
    }
    return ds.nsets - 1;
  }
};

