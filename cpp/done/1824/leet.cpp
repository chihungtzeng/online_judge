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

using ipair = pair<int, int64_t>;
class Solution {
 public:
  int minSideJumps(vector<int>& obstacles) {
    const int n = obstacles.size();
    vector<vector<int>> dist(n, vector<int>(3, INT_MAX));
    priority_queue<ipair, vector<ipair>, greater<>> pq;
    dist[0][1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
      auto [d, pos] = pq.top();
      int64_t r = pos / n, c = pos % n;
      //      LOG(INFO) << "extend from " << r << ", " << c;
      pq.pop();
      for (int i = -2; i <= 2; i++) {
        int nc = c + i;
        if (nc < 0 || nc > 2 || nc == c) continue;
        if (obstacles[r] > 0 && obstacles[r] - 1 == nc) continue;
        if (dist[r][nc] > d + 1) {
          dist[r][nc] = d + 1;
          pq.push({dist[r][nc], r * n + nc});
        }
      }
      if (r < n - 1 && obstacles[r + 1] - 1 != c && dist[r + 1][c] > d) {
        dist[r + 1][c] = d;
        pq.push({dist[r + 1][c], (r + 1) * n + c});
      }
    }
    int ans = INT_MAX;
    for (int i = 0; i < 3; i++) {
      ans = min(ans, dist[n - 1][i]);
    }
    return ans;
  }
};
