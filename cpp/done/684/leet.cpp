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
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int> parents(n + 1), ranks(n + 1);
    for (int i = 1; i <= n; i++) parents[i] = i;

    for (auto& edge : edges) {
      int u = edge[0];
      int v = edge[1];
      if (find(parents, u) == find(parents, v)) {
        return edge;
      }
      join(parents, ranks, u, v);
    }
    return {0, 0};
  }
  int find(vector<int>& parents, int u) {
    if (parents[u] != u) {
      parents[u] = find(parents, parents[u]);
    }
    return parents[u];
  }
  void join(vector<int>& parents, vector<int>& ranks, int u, int v) {
    int uroot = find(parents, u);
    int vroot = find(parents, v);
    if (ranks[uroot] < ranks[vroot]) {
      parents[uroot] = vroot;
    } else if (ranks[uroot] > ranks[vroot]) {
      parents[vroot] = uroot;
    } else {
      parents[uroot] = vroot;
      ranks[vroot] += 1;
    }
  }
};
