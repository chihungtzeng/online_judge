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

class Solution {
 public:
  bool find132pattern(vector<int>& nums) {
    if (nums.size() < 3) return false;
    vector<int> mins(nums.size());
    mins[0] = nums[0];
    for (size_t i = 1; i < nums.size(); i++) {
      mins[i] = min(mins[i - 1], nums[i]);
    }
    vector<int> stack;
    for (int j = nums.size() - 1; j >= 0; j--) {
      if (nums[j] < mins[j]) {
        continue;
      }
      while (!stack.empty() && stack.back() <= mins[j]) {
        stack.pop_back();
      }
      if (!stack.empty() && stack.back() < nums[j] && mins[j] < stack.back()) {
        return true;
      }
      stack.push_back(nums[j]);
    }
    return false;
  }
};
