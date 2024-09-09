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

class DisjointSet {
 public:
  vector<int> ranks, parents;
  int nsets;
  DisjointSet(int n) : ranks(n), parents(n) {
    for (int i = 0; i < n; i++) {
      parents[i] = i;
    }
    nsets = n;
  }
  int find(int u) {
    if (parents[u] != u) {
      parents[u] = find(parents[u]);
    }
    return parents[u];
  }
  void join(int u, int v) {
    int ur = find(u);
    int vr = find(v);
    if (ur == vr) return;
    if (ranks[ur] < ranks[vr])
      parents[ur] = vr;
    else if (ranks[ur] == ranks[vr]) {
      parents[ur] = vr;
      ranks[vr]++;
    } else {
      parents[vr] = ur;
    }
    nsets--;
  }
};

using ipair = pair<int, int>;
class Solution {
 public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    const int n = points.size();
    if (n == 1) return 0;

    vector<ipair> dists;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int dist =
            abs(points[j][0] - points[i][0]) + abs(points[j][1] - points[i][1]);
        dists.emplace_back(ipair{dist, (i << 10) + j});
      }
    }
    priority_queue<ipair, vector<ipair>, greater<ipair>> pq(dists.begin(),
                                                            dists.end());
    DisjointSet ds(points.size());
    int ans = 0;
    while (!pq.empty()) {
      auto [dist, idx] = pq.top();
      int u = idx >> 10, v = idx & (0x3ff);

      pq.pop();
      if (ds.find(u) != ds.find(v)) {
        ans += dist;
        ds.join(u, v);
        if (ds.nsets == 1) {
          break;
        }
      }
    }
    return ans;
  }
};
