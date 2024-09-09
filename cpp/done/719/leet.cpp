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
  int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.back() - nums[0];
    while (left <= right) {
      int diff = left + ((right - left) >> 1);
      auto cnt = count(nums, diff);
      if (cnt >= k)
        right = diff - 1;
      else
        left = diff + 1;
    }
    return left;
  }
  int count(vector<int>& nums, int diff) {
    int cnt = 0;
    for (int i = 0, j = 1; i < nums.size(); i++) {
      while (j < nums.size() && nums[j] - nums[i] <= diff) {
        j++;
      }
      cnt += j - i - 1;
    }
    return cnt;
  }
};
