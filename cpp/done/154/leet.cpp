#include <algorithm>
#include <cstdint>
#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
      auto mid = (low + high) >> 1;
      if (nums[low] > nums[mid]) {
        high = mid;
      } else if (nums[mid] > nums[high]) {
        low = mid + 1;
      } else if (nums[low] < nums[mid]) {
        return nums[low];
      } else if (nums[mid] < nums[high]) {
        return nums[mid];
      } else {
        low++;
      }
    }
    return nums[low];
  }
};
