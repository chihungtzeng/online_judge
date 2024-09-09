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
  int minimumSize(vector<int>& nums, int maxOperations) {
    int hi = *max_element(nums.begin(), nums.end());
    int low = 1;
    int best = hi;
    while (low <= hi) {
      int mid = low + (hi - low) / 2;
      if (can_divide(nums, maxOperations, mid)) {
        best = min(best, mid);
        hi = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return best;
  }
  bool can_divide(vector<int>& nums, int maxOperations, int target) {
    int ops = 0;
    for (auto ball : nums) {
      ops += (ball % target == 0) ? ball / target - 1 : ball / target;
    }
    return ops <= maxOperations;
  }
};
