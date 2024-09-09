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
  int maxBuilding(int n, vector<vector<int>>& restrictions) {
    restrictions.push_back(vector<int>{1, 0});
    restrictions.push_back(vector<int>{n, n - 1});
    sort(restrictions.begin(), restrictions.end());
    for (int i = 1; i < restrictions.size(); i++) {
      int prev_id = restrictions[i - 1][0];
      int cur_id = restrictions[i][0];
      restrictions[i][1] =
          min(restrictions[i][1], restrictions[i - 1][1] + cur_id - prev_id);
    }
    for (int i = restrictions.size() - 2; i >= 0; i--) {
      int prev_id = restrictions[i + 1][0];
      int cur_id = restrictions[i][0];
      restrictions[i][1] =
          min(restrictions[i][1], restrictions[i + 1][1] + prev_id - cur_id);
    }

#if 0
    for (auto& r : restrictions) {
      LOG(INFO) << r;
    }
#endif
    int ans = 0;
    for (int i = 1; i < restrictions.size(); i++) {
      int cur_id = restrictions[i][0];
      int cur_limit = restrictions[i][1];

      int prev_id = restrictions[i - 1][0];
      int prev_limit = restrictions[i - 1][1];
      int ell = cur_id - prev_id - 1 - abs(cur_limit - prev_limit);
      int can = max(prev_limit, cur_limit);
      if (ell >= 1) {
        can = max(restrictions[i][1], restrictions[i - 1][1]) + (ell / 2) +
              (ell % 2);
      }
#if 0    
      LOG(INFO) << "interval " << i << " candidate: " << can << " ell:" << ell;
#endif
      ans = max(ans, can);
    }
    return ans;
  }
};
