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
  int maximumRequests(int n, vector<vector<int>>& requests) {
    int ans = 0;
    vector<pair<int, int>> edges;

    for (auto& r : requests) {
      int u = r[0], v = r[1];
      if (u == v) {
        ans++;
      } else {
        edges.push_back({u, v});
      }
    }
    const int m = edges.size();
    int bound = (1 << m);
    int ret = 0;
    for (int comb = 1; comb < bound; comb++) {
      vector<int> ins(n, 0), outs(n, 0);
      int tr = 0;
      for (int i = 0; i < m; i++) {
        if (comb & (1 << i)) {
          auto [u, v] = edges[i];
          outs[u]++;
          ins[v]++;
          tr++;
        }
      }
      int neven = 0;
      int ncover = 0;

      for (int i = 0; i < n; i++) {
        if (ins[i] > 0) ncover++;
        if (ins[i] > 0 && ins[i] == outs[i]) {
          neven++;
        }
      }
      if (neven == ncover) {
        ret = max(ret, tr);
      }
    }
    return ans + ret;
  }
};
