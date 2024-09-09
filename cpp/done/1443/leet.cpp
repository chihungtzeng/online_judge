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
  int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    vector<vector<int>> nbrs(n);
    vector<int> degrees(n);
    for (auto& edge : edges) {
      int u = edge[0], v = edge[1];
      nbrs[u].push_back(v);
      nbrs[v].push_back(u);
      degrees[u]++;
      degrees[v]++;
    }
    deque<int> q;
    for (int i = 1; i < n; i++) {
      if (degrees[i] == 1 && !hasApple[i]) q.push_back(i);
    }
    int nremoval = 0;
    while (!q.empty()) {
      auto cur = q.front();
      q.pop_front();
      nremoval++;
      for (auto nbr : nbrs[cur]) {
        if (nbr == 0) continue;
        degrees[nbr]--;
        if (degrees[nbr] == 1 && !hasApple[nbr]) {
          q.push_back(nbr);
        }
      }
    }

    return 2 * (n - nremoval - 1);

  }
};
