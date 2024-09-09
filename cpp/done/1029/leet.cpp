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

using ipair = pair<int, int>;
class Solution {
 public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    vector<ipair> savings;
    const int m = costs.size();
    savings.reserve(m);
    for (int i = 0; i < m; i++) {
      savings.emplace_back(costs[i][0] - costs[i][1], i);
    }
    sort(savings.begin(), savings.end());
    int ans = 0;
    const int n = m >> 1;
    for (int i = 0; i < n; i++) {
      int idx = savings[i].second;
      ans += costs[idx][0];
    }
    for (int i = n; i < m; i++) {
      int idx = savings[i].second;
      ans += costs[idx][1];
    }
    return ans;
  }
};
