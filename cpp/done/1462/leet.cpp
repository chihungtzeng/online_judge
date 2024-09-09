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
  vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites,
                                   vector<vector<int>>& queries) {
    vector<bool> ret(queries.size());
    vector<set<int>> depends(n), children(n);
    vector<int> outdegrees(n);

    for (auto& edge : prerequisites) {
      int u = edge[0], v = edge[1];
      outdegrees[v]++;
      depends[v].insert(u);
      children[u].insert(v);
    }
    deque<int> q;
    for (int i = 0; i < n; i++) {
      if (outdegrees[i] == 0) q.push_back(i);
    }
    while (!q.empty()) {
      int cur = q.front();
      q.pop_front();
      for (auto child : children[cur]) {
        for (auto d : depends[cur]) {
          depends[child].insert(d);
        }
        depends[child].insert(cur);
        outdegrees[child] -= 1;
        if (outdegrees[child] == 0) {
          q.push_back(child);
        }
      }
    }
    for (int i = 0; i < queries.size(); i++) {
      int u = queries[i][0], v = queries[i][1];
      ret[i] = bool(depends[v].count(u));
    }

    return ret;
  }
};
