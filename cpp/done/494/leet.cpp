#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using ipair = std::pair<int, int>;
class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int S) {
    if (nums.size() == 0) {
      return 0;
    }
    map<ipair, int> cache;
    return helper(nums, S, 0, cache);
  }
  int helper(vector<int>& nums, const int64_t target, const int pos,
             map<ipair, int>& cache) {
    if (pos == nums.size()) {
      if (target == 0)
        return 1;
      else
        return 0;
    }
    ipair cur{pos, target};
    auto hit = cache.find(cur);
    if (hit != cache.end()) {
      return hit->second;
    }
    auto val = helper(nums, target - nums[pos], pos + 1, cache) +
               helper(nums, target + nums[pos], pos + 1, cache);
    cache[cur] = val;
    return val;
  }
};
