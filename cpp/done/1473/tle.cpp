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
  int best_;
  int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n,
              int target) {
    best_ = INT_MAX;
    int start = next_unpainted(houses, m, 0);
    dfs(houses, cost, m, n, target, start, 0);
    if (best_ == INT_MAX) return -1;
    return best_;
  }
  void dfs(vector<int>& houses, vector<vector<int>>& cost, const int m,
           const int n, const int target, const int start, int cur_cost) {
    if (start == m) {
      if (count_nbh(houses, m) == target && cur_cost < best_) {
        // LOG(INFO) << "houses: " << houses << " cur_cost:" << cur_cost;
        best_ = cur_cost;
      }
      return;
    }
    for (int i = 0; i < n; i++) {
      houses[start] = i + 1;
      cur_cost += cost[start][i];
      if (count_nbh(houses, start + 1) <= target && cur_cost < best_) {
        auto next = next_unpainted(houses, m, start + 1);
        // LOG(INFO) << "houses: " << houses << " start: " << start << "
        // next_unpainted: " << next;
        dfs(houses, cost, m, n, target, next, cur_cost);
      }
      cur_cost -= cost[start][i];
      houses[start] = 0;
    }
  }
  int count_nbh(vector<int>& houses, int stop) {
    int ret = 1;
    for (int i = 1; i < stop; i++) {
      if (houses[i] != houses[i - 1]) ret++;
    }
    // LOG(INFO) << houses << " nbh: " << ret;
    return ret;
  }
  int next_unpainted(vector<int>& houses, int m, int start) {
    while (start < m && houses[start] > 0) start++;
    return start;
  }
};
