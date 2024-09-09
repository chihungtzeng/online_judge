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
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> parents(n);
    vector<int> outdegrees(n, 0);
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      outdegrees[i] = graph[i].size();
      for (auto j : graph[i]) {
        parents[j].push_back(i);
      }
    }
    // LOG(INFO) << outdegrees;
    vector<int> q;
    for (int i = 0; i < n; i++) {
      if (outdegrees[i] == 0) {
        // LOG(INFO) << "push " << i;
        q.push_back(i);
      }
    }
    while (!q.empty()) {
      int cur = q.back();
      q.pop_back();
      ans.push_back(cur);
      for (auto p : parents[cur]) {
        outdegrees[p]--;
        if (outdegrees[p] == 0) {
          // LOG(INFO) << "push " << p;
          q.push_back(p);
        }
      }
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};
