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
  int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    vector<vector<ipair>> adjlist(N + 1);
    vector<int> dist(N + 1, INT_MAX);
    for (const auto& edge : times) {
      int src = edge[0], dest = edge[1], delay = edge[2];
      adjlist[src].push_back({dest, delay});
    }
    dist[K] = 0;
    deque<int> queue;
    queue.push_back(K);
    while (!queue.empty()) {
      int cur = queue.front();
      queue.pop_front();
      for (int i = 0; i < adjlist[cur].size(); i++) {
        int nbr = adjlist[cur][i].first;
        int delay = adjlist[cur][i].second;
        if (dist[cur] + delay < dist[nbr]) {
          dist[nbr] = dist[cur] + delay;
          queue.push_back(nbr);
        }
      }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
      ans = max(ans, dist[i]);
    }
    if (ans == INT_MAX) return -1;
    return ans;
  }
};
