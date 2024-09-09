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

using epair = pair<int, double>;
class Solution {
 public:
  double maxProbability(int n, vector<vector<int>>& edges,
                        vector<double>& succProb, int start, int end) {
    vector<double> rates(n);
    vector<vector<epair>> nbrs(n);
    for (int i = 0; i < edges.size(); i++) {
      int u = edges[i][0], v = edges[i][1];
      double d = succProb[i];
      nbrs[u].push_back({v, d});
      nbrs[v].push_back({u, d});
    }
    rates[start] = 1;
    deque<int> q;
    q.push_back(start);
    while (!q.empty()) {
      int cur = q.front();
      q.pop_front();
      for (auto& [nbr, p] : nbrs[cur]) {
        double succ = rates[cur] * p;
        if (succ > rates[nbr]) {
          q.push_back(nbr);
          rates[nbr] = succ;
        }
      }
    }
    return rates[end];
  }
};
