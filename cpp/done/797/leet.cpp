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
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<int> path;
    vector<vector<int>> ans;
    dfs(0, path, graph, ans);
    return ans;
  }
  void dfs(int src, vector<int>& path, vector<vector<int>>& graph,
           vector<vector<int>>& ans) {
    path.push_back(src);
    if (src == graph.size() - 1) {
      ans.push_back(path);
      path.pop_back();
      return;
    }
    for (auto nbr : graph[src]) {
      dfs(nbr, path, graph, ans);
    }
    path.pop_back();
  }
};
