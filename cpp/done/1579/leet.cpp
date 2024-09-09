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
  int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    vector<vector<ipair>> cedges(4);
    vector<int> parents(n + 1);
    vector<int> ranks(n + 1);
    for (auto& edge : edges) {
      int t = edge[0], u = edge[1], v = edge[2];
      cedges[t].push_back({u, v});
    }
    int tedges = build_mst(n, cedges[3], parents, ranks);
    if (cedges[1].size() < n - 1 - tedges) return -1;
    if (cedges[2].size() < n - 1 - tedges) return -1;
    int alice_edges = add_edges(cedges[1], parents, ranks);
    if (alice_edges + tedges != n - 1) return -1;
    int bob_edges = add_edges(cedges[2], parents, ranks);
    if (bob_edges + tedges != n - 1) return -1;
    return (cedges[3].size() - tedges) + (cedges[1].size() - alice_edges) +
           (cedges[2].size() - bob_edges);
  }

  int add_edges(vector<ipair>& edges, vector<int> parents, vector<int> ranks) {
    int used_edges = 0;
    for (auto& [u, v] : edges) {
      if (find(parents, u) != find(parents, v)) {
        join(parents, ranks, u, v);
        used_edges++;
      }
    }
    return used_edges;
  }

  int build_mst(const int n, vector<ipair>& edges, vector<int>& parents,
                vector<int>& ranks) {
    int used_edges = 0;
    for (int i = 1; i <= n; i++) {
      parents[i] = i;
    }
    for (auto& [u, v] : edges) {
      if (find(parents, u) != find(parents, v)) {
        join(parents, ranks, u, v);
        used_edges++;
      }
    }
    return used_edges;
  }
  int find(vector<int>& parents, const int u) {
    if (u != parents[u]) {
      parents[u] = find(parents, parents[u]);
    }
    return parents[u];
  }
  void join(vector<int>& parents, vector<int>& ranks, const int u,
            const int v) {
    int uroot = find(parents, u);
    int vroot = find(parents, v);
    if (uroot == vroot) return;
    if (ranks[uroot] < ranks[vroot]) {
      parents[uroot] = vroot;
    } else if (ranks[uroot] == ranks[vroot]) {
      parents[uroot] = vroot;
      ranks[vroot]++;
    } else {
      parents[vroot] = uroot;
    }
  }
};
