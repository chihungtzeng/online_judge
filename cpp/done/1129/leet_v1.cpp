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

using ituple = tuple<int, int, int>;
constexpr int red = 1;
constexpr int blue = 2;
class Solution {
 public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges,
                                       vector<vector<int>>& blue_edges) {
    vector<int> red_dist(n, INT_MAX);
    vector<int> blue_dist(n, INT_MAX);
    vector<vector<int>> red_nbrs(n), blue_nbrs(n);

    for (auto& edge : red_edges) {
      int u = edge[0], v = edge[1];
      red_nbrs[u].push_back(v);
    }
    for (auto& edge : blue_edges) {
      int u = edge[0], v = edge[1];
      blue_nbrs[u].push_back(v);
    }
    deque<ituple> q;
    blue_dist[0] = 0;
    red_dist[0] = 0;
    q.push_back({red, 0, 0});
    q.push_back({blue, 0, 0});
    while (!q.empty()) {
      auto [color, cur, dist] = q.front();
      q.pop_front();

      if (color == red) {
        for (auto nbr : blue_nbrs[cur]) {
          if (blue_dist[nbr] > dist + 1) {
            blue_dist[nbr] = dist + 1;
            q.push_back({blue, nbr, dist + 1});
            // LOG(INFO) << "push blue to " << nbr << " with dist " <<
            // blue_dist[nbr];
          }
        }
      }
      if (color == blue) {
        for (auto& nbr : red_nbrs[cur]) {
          if (red_dist[nbr] > dist + 1) {
            red_dist[nbr] = dist + 1;
            q.push_back({red, nbr, dist + 1});
            // LOG(INFO) << "push red to " << nbr << " with dist " <<
            // red_dist[nbr];
          }
        }
      }
    }
    // LOG(INFO) << red_dist;
    // LOG(INFO) << blue_dist;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      int dist = min(red_dist[i], blue_dist[i]);
      if (dist == INT_MAX) {
        ans[i] = -1;
      } else {
        ans[i] = dist;
      }
    }
    return ans;
  }
};
