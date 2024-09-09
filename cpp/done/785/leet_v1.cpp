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
  bool isBipartite(vector<vector<int>>& graph) {
    vector<int> colors(graph.size());
    vector<int> dist(graph.size());
    for (int i = 0; i < graph.size(); i++) {
      if (colors[i] == 0) {
        auto bipartite = dfs(graph, colors, dist, i, 0);
        if (!bipartite) return false;
      }
    }
    return true;
  }
  bool dfs(vector<vector<int>>& graph, vector<int>& colors, vector<int>& dist,
           int cur, int depth) {
    colors[cur] = 1;
    dist[cur] = depth;
    for (auto nbr : graph[cur]) {
      if (colors[nbr] > 0) {
        if ((dist[cur] - dist[nbr]) % 2 == 0) return false;
      } else {
        bool bipartite = dfs(graph, colors, dist, nbr, depth + 1);
        if (!bipartite) return false;
      }
    }
    colors[cur] = 2;
    return true;
  }
};
