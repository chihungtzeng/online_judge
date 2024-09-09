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
  int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts,
                  int target) {
    int ans = baseCosts[0];
    for (auto base : baseCosts) {
      auto can = helper(toppingCosts, target, base, 0);
      auto cur_diff = abs(ans - target);
      auto can_diff = abs(can - target);
      if (can_diff < cur_diff || (can_diff == cur_diff && can < ans)) {
        ans = can;
      }
    }
    return ans;
  }
  int helper(vector<int>& toppings, const int target, const int cur_cost,
             const int ti) {
    if (ti == toppings.size() || cur_cost >= target) {
      return cur_cost;
    }
    int cans[3];
    for (int i = 0; i < 3; i++) {
      cans[i] = helper(toppings, target, cur_cost + toppings[ti] * i, ti + 1);
    }
    int can = cans[0];
    for (int i = 1; i < 3; i++) {
      auto cur_diff = abs(can - target);
      auto can_diff = abs(cans[i] - target);
      if (can_diff < cur_diff || (can_diff == cur_diff && cans[i] < can)) {
        can = cans[i];
      }
    }
    return can;
  }
};
