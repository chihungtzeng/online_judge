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
  int cur_rank;
  vector<vector<int>> criticalConnections(int n,
                                          vector<vector<int>>& connections) {
    vector<int> ranks(n, 0);
    vector<int> least_ranks(n, 0);
    vector<vector<int>> graph(n);
    cur_rank = 0;

    for (auto& conn : connections) {
      int u = conn[0], v = conn[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    vector<vector<int>> ans;
    dfs(graph, ranks, least_ranks, 0, -1, ans);
    return ans;
  }
  void dfs(vector<vector<int>>& graph, vector<int>& ranks,
           vector<int>& least_ranks, int src, int parent,
           vector<vector<int>>& ans) {
    cur_rank++;
    ranks[src] = cur_rank;
    least_ranks[src] = cur_rank;

    for (auto nbr : graph[src]) {
      if (nbr == parent) {
        continue;
      }

      if (ranks[nbr] == 0) {
        dfs(graph, ranks, least_ranks, nbr, src, ans);
        least_ranks[src] = min(least_ranks[src], least_ranks[nbr]);
        if (least_ranks[nbr] > ranks[src]) {
          ans.push_back({min(src, nbr), max(src, nbr)});
        }

      } else {
        least_ranks[src] = min(least_ranks[src], least_ranks[nbr]);
      }
    }
  }
};
