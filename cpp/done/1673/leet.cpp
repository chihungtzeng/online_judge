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
  vector<int> mostCompetitive(vector<int>& nums, int k) {
    const int n = nums.size();
    vector<int> stack;
    vector<int> ans;
    stack.push_back(0);
    int head = 0;
    for (int i = 1; i < n; i++) {
      while (!stack.empty() && nums[stack.back()] > nums[i]) {
        stack.pop_back();
      }
      if (stack.empty()) {
        if (n - i >= k) {
          head = i;
        }
      }
      stack.push_back(i);
    }
    ans.push_back(nums[head]);
    for (int i = head + 1; i < n; i++) {
      while (ans.back() > nums[i] && n - i + ans.size() > k) {
        ans.pop_back();
      }
      ans.push_back(nums[i]);
    }
    while (ans.size() > k) ans.pop_back();
    return ans;
  }
};
