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
  int maxAbsoluteSum(vector<int>& nums) {
    const int n = nums.size();
    for (int i = 1; i < n; i++) {
      nums[i] += nums[i - 1];
    }
    int cur_max = 0;
    int cur_min = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, abs(nums[i] - cur_max));
      ans = max(ans, abs(nums[i] - cur_min));
      cur_max = max(cur_max, nums[i]);
      cur_min = min(cur_min, nums[i]);
    }
    return ans;
  }
};
