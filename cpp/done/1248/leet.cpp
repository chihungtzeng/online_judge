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
  int numberOfSubarrays(vector<int>& nums, int k) {
    const int n = nums.size();
    nums[0] = nums[0] & 1;
    for (int i = 1; i < n; i++) {
      nums[i] = nums[i - 1] + (nums[i] & 1);
    }
    int ans = 0;
    // handle 0:
    auto start_it = lower_bound(nums.begin(), nums.end(), k);
    auto end_it = lower_bound(nums.begin(), nums.end(), k + 1);
    int addon = end_it - start_it;
    ans += addon;
    for (int i = 1; i < n; i++) {
      auto start_it =
          lower_bound(nums.begin() + i, nums.end(), k + nums[i - 1]);
      auto end_it =
          lower_bound(nums.begin() + i, nums.end(), k + nums[i - 1] + 1);
      int addon = end_it - start_it;
      ans += addon;
    }
    return ans;
  }
};
