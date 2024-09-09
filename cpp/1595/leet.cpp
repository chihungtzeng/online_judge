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

class Solution {
 public:
  int connectTwoGroups(vector<vector<int>>& cost) {
    int rows = cost.size();
    int cols = cost[0].size();
    vector<int> nbrs(rows, -1);
    vector<int> num_conn(cols, 0);
    int ans = 0;
    for (int i = 0; i < rows; i++) {
      auto it = min_element(cost[i].begin(), cost[i].end());
      ans += *it;
      int j = it - cost[i].begin();
      num_conn[j]++;
      nbrs[i] = j;
    }
    for (int j = 0; j < cols; j++) {
      if (num_conn[j] > 0) continue;

      int least_inc = INT_MAX;
      int best_i = -1;
      for (int r = 0; r < rows; r++) {
        int other_j = nbrs[r];
        int inc = cost[r][j];
        if (num_conn[other_j] > 1) {
          inc -= cost[r][other_j];
        }
        if (inc < least_inc) {
          least_inc = inc;
          best_i = r;
        }
      }
      ans += least_inc;
      num_conn[j] = 1;
      if (num_conn[nbrs[best_i]] > 1) {
        num_conn[nbrs[best_i]]--;
      }
      nbrs[best_i] = j;
    }
    return ans;
  }
};
