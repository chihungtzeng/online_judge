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
  int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<int>> nbrs(n);
    vector<vector<int>> new_edges;

    for (auto& edge : connections) {
      int p = edge[1], c = edge[0];
      nbrs[c].push_back(p);
      nbrs[p].push_back(c);
    }
    deque<int> q;
    vector<bool> visited(n, false);
    q.push_back(0);
    while (!q.empty()) {
      int cur = q.front();
      q.pop_front();
      visited[cur] = true;
      for (auto nbr : nbrs[cur]) {
        if (!visited[nbr]) {
          q.push_back(nbr);
          new_edges.emplace_back(vector<int>{nbr, cur});
        }
      }
    }
    sort(new_edges.begin(), new_edges.end());
    int ret = 0;
    for (auto& edge : connections) {
      if (!binary_search(new_edges.begin(), new_edges.end(), edge)) ret++;
    }
    return ret;
  }
};
