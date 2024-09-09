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
  double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
    vector<vector<int>> nbrs(n + 1);
    vector<int> arrival_time(n + 1);
    vector<bool> has_children(n + 1, false);
    vector<double> prob(n + 1, -1);

    for (auto& edge : edges) {
      int u = edge[0], v = edge[1];
      nbrs[u].push_back(v);
      nbrs[v].push_back(u);
    }
    deque<int> q;
    q.push_back(1);
    arrival_time[1] = 0;
    prob[1] = 1;
    while (!q.empty()) {
      int cur = q.front();
      q.pop_front();
      // find nnext;
      int nnext = 0;
      for (auto v : nbrs[cur]) {
        if (prob[v] < 0) {
          nnext++;
        }
      }
      double cprob = 0;
      if (nnext > 0) {
        cprob = prob[cur] / nnext;
        has_children[cur] = true;
      }
      for (auto v : nbrs[cur]) {
        if (prob[v] < 0) {
          arrival_time[v] = arrival_time[cur] + 1;
          prob[v] = cprob;
          q.push_back(v);
        }
      }
    }  // while
    if (has_children[target] && arrival_time[target] != t) return 0;
    if (arrival_time[target] > t) return 0;
    return prob[target];
  }
};
