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
  int reversePairs(vector<int>& nums) {
    if (nums.size() < 2) return 0;
    vector<int64_t> nums64;
    for(auto x: nums){
      nums64.push_back(x);
    }
    return helper(nums64, 0, nums64.size() - 1);
  }
  int helper(vector<int64_t>& nums, const int left, const int right) {
    if (left >= right) return 0;
    auto mid = left + (right - left) / 2;
    auto cnt = helper(nums, left, mid) + helper(nums, mid + 1, right);
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
      if (nums[i] - nums[j] > nums[j]) {
        cnt += mid - i + 1;
        j++;
      } else {
        i++;
      }
    }

    i = left;
    j = mid + 1;
    vector<int> temp;
    while (i <= mid && j <= right) {
      if (nums[i] <= nums[j]) {
        temp.push_back(nums[i++]);
      } else {
        temp.push_back(nums[j++]);
      }
    }
    while (i <= mid) temp.push_back(nums[i++]);
    while (j <= right) temp.push_back(nums[j++]);
    copy(temp.begin(), temp.end(), nums.begin() + left);
    // LOG(INFO) << "left: " << left << " right: " << right << " cnt: " << cnt << " nums: " << nums;
    return cnt;
  }
};
