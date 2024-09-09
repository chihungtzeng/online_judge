#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  unordered_map<int, int> cache_;
  int combinationSum4(vector<int>& nums, int target) {
    if (nums.size() == 0) {
      return 0;
    }
    sort(nums.begin(), nums.end());
    return helper(nums, target);
  }
  int helper(const vector<int>& nums, int target) {
    if (target < nums[0]) {
      return 0;
    }
    if (cache_.count(target) > 0) {
      return cache_[target];
    }
    int ret = 0;
    if (std::binary_search(nums.begin(), nums.end(), target)) {
      ret = 1;
    }
    for (const auto v : nums) {
      ret += helper(nums, target - v);
    }
    cache_[target] = ret;
    return ret;
  }
};
