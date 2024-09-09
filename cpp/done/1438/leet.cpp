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
  int longestSubarray(vector<int>& nums, int limit) {
    deque<int> maxq, minq;
    int ans = 0, j = 0;
    for (int i = 0; i < nums.size(); i++) {
      while (!maxq.empty() && maxq.back() < nums[i]) maxq.pop_back();
      maxq.push_back(nums[i]);
      while (!minq.empty() && minq.back() > nums[i]) minq.pop_back();
      minq.push_back(nums[i]);
      while (maxq.front() - minq.front() > limit) {
        if (maxq.front() == nums[j]) maxq.pop_front();
        if (minq.front() == nums[j]) minq.pop_front();
        j++;
      }
      ans = max(ans, i - j + 1);
    }
    return ans;
  }
};
