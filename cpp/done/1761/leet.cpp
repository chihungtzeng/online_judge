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

class Solution {
 public:
  int minTrioDegree(int n, vector<vector<int>>& edges) {
    vector<int> degrees(n + 1, 0);
    vector<vector<bool>> nbrs(n + 1, vector<bool>(n + 1, false));
    for (auto& edge : edges) {
      int u = edge[0], v = edge[1];
      degrees[u]++;
      degrees[v]++;
      nbrs[u][v] = true;
      nbrs[v][u] = true;
    }
    int ans = INT_MAX;
    for (auto& edge : edges) {
      int u = edge[0], v = edge[1];
      for (int w = 1; w <= n; w++) {
        if (nbrs[u][w] && nbrs[v][w]) {
          ans = min(ans, degrees[u] + degrees[v] + degrees[w] - 6);
        }
      }
    }
    return (ans == INT_MAX) ? -1 : ans;
  }
};
