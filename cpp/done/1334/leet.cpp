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

using ipair = pair<int, int>;
class Solution {
 public:
  int findTheCity(int n, vector<vector<int>>& edges, int dt) {
    vector<vector<ipair>> nbrs(n);
    for (auto& e : edges) {
      int u = e[0], v = e[1], w = e[2];
      nbrs[u].push_back({v, w});
      nbrs[v].push_back({u, w});
    }
    int least_cities = INT_MAX;
    int ans = -1;
    for (int i = n - 1; i >= 0; i--) {
      int ret = helper(n, nbrs, i, dt);
      // LOG(INFO) << "src: " << i << " ret: " << ret;
      if (ret < least_cities) {
        least_cities = ret;
        ans = i;
      }
    }
    return ans;
  }

  int helper(const int n, vector<vector<ipair>>& nbrs, const int src,
             const int dt) {
    vector<int> dist(n, INT_MAX);
    auto cmp = [](const auto& a, const auto& b) { return a.second > b.second; };

    priority_queue<ipair, vector<ipair>, decltype(cmp)> q(cmp);
    q.push({src, 0});
    dist[src] = 0;
    while (!q.empty()) {
      auto [cur, d] = q.top();
      q.pop();
      for (auto& [dst, w] : nbrs[cur]) {
        if (dist[dst] > dist[cur] + w) {
          dist[dst] = dist[cur] + w;
          q.push({dst, dist[dst]});
        }
      }
    }
    int nmatch = 0;
    for (int i = 0; i < n; i++) {
      if (dist[i] <= dt) nmatch++;
    }
    //   LOG(INFO) << "src: " << src << " dist: " << dist;
    return nmatch;
  }
};
