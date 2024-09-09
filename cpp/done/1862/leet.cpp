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

constexpr int base = 1e9 + 7;
class Solution {
 public:
  int sumOfFlooredPairs(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int64_t ans = 0;
    int64_t prev_res = -1;
    int prev = 1;
    if (nums[0] == 1) {
      prev_res = accumulate(nums.begin(), nums.end(), 0ll);
    }
    const int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (nums[i] != prev) {
        prev_res = helper(nums, i);
      }
      // LOG(INFO) << "nums[i]: " << nums[i] << ", prev_res: " << prev_res;
      ans += prev_res;
      prev = nums[i];
    }
    return ans % base;
  }
  int64_t helper(vector<int>& nums, int idx) {
    int64_t factor = nums.back() / nums[idx];
    int64_t res = 0;
    auto last = nums.end();
    while (factor >= 1) {
      auto it = lower_bound(nums.begin() + idx, last, factor * nums[idx]);
      res += (last - it) * factor;
      last = it;
      factor--;
    }
    return res;
  }
};
