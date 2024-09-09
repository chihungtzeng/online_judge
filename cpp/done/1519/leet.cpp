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
  vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    vector<int> indegrees(n), parents(n), depth(n, INT_MAX);
    vector<vector<int>> nbrs(n);
    for (auto& edge : edges) {
      nbrs[edge[0]].push_back(edge[1]);
      nbrs[edge[1]].push_back(edge[0]);
    }
    depth[0] = 0;
    deque<int> q;
    q.push_back(0);
    while (!q.empty()){
      int cur = q.front();
      q.pop_front();
      for(auto nbr : nbrs[cur]){
        if (depth[nbr] > depth[cur]){
          parents[nbr] = cur;
          depth[nbr] = 1 + depth[cur];
          q.push_back(nbr);
        }
      }
    }
    for(int i=1; i<n; i++){
      auto parent = parents[i];
      indegrees[parent]++;
    }

    vector<vector<int>> subtree_labels(n, vector<int>(26));
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      if (indegrees[i] == 0) {
        q.push_back(i);
      }
    }
    while (!q.empty()) {
      int cur = q.front();
      q.pop_front();
      char label = labels[cur];
      subtree_labels[cur][label - 'a']++;
      int parent = parents[cur];
      if (parent != cur) {
        for (int i = 0; i < 26; i++) {
          subtree_labels[parent][i] += subtree_labels[cur][i];
        }
      }
#if 0
      LOG(INFO) << "cur: " << cur << " subtree_label: " << subtree_labels[cur];
      LOG(INFO) << "parent: " << parent
                << " parent subtree_label: " << subtree_labels[parent];
#endif
      ans[cur] = subtree_labels[cur][label - 'a'];
      indegrees[parent]--;
      if (indegrees[parent] == 0) {
        q.push_back(parent);
      }
    }
    return ans;
  }
};
