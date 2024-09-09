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
  int missingElement(vector<int>& nums, int k) {
    int nmiss = nums.back() - nums[0] + 1 - nums.size();
    if (k > nmiss) return nums.back() + k - nmiss;

    int left = 0, right = nums.size() - 1;
    while (left + 1 < right) {
      int mid = left + (right - left) / 2;
      int nelem = nums[mid] - nums[left] + 1;
      int nmiss = nelem - (mid - left + 1);
      if (nmiss >= k) {
        right = mid;
      } else {
        k -= nmiss;
        left = mid;
      }
    }
    return nums[left] + k;
  }
};
