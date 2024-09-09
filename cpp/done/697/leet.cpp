#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
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
  int findShortestSubArray(vector<int>& nums) {
    unordered_map<int, int> mp, left, right;
    for (int i = 0; i < nums.size(); i++) {
      mp[nums[i]] = mp[nums[i]] + 1;
      if (left.find(nums[i]) == left.end()) {
        left[nums[i]] = i;
      }
      right[nums[i]] = i;
    }
    int ans = nums.size();
    int degree = 0;
    for (auto& [key, val] : mp) {
      if (degree < val) {
        degree = val;
        ans = right[key] - left[key] + 1;
      } else if (degree == val) {
        ans = min(ans, right[key] - left[key] + 1);
      }
    }
    return ans;
  }
};
