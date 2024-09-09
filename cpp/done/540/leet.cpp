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
  int singleNonDuplicate(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    if (right == 0) return nums[0];
    int mid = 0;
    while (left <= right) {
      if (right - left == 2) {
        return nums[left] ^ nums[left + 1] ^ nums[right];
      }
      mid = left + (right - left) / 2;
      auto lsize = mid - left;
      auto rsize = right - mid;
      if (mid >= 1 && nums[mid] == nums[mid - 1]) {
        if ((lsize - 1) % 2 == 0) {
          left = mid + 1;
        } else {
          right = mid - 2;
        }
      } else if (mid < nums.size() - 1 && nums[mid] == nums[mid + 1]) {
        if ((rsize - 1) % 2 == 0) {
          right = mid - 1;
        } else {
          left = mid + 2;
        }
      } else {
        return nums[mid];
      }
    }
    return nums[mid];
  }
};
