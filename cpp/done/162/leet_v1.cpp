#include <vector>
using namespace std;

class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    if (nums.size() == 0) {
      return 0;
    }
    if (nums.size() == 1) {
      return 0;
    }
    auto left = 0;
    int right = static_cast<int>(nums.size() - 1);
    auto last_idx = static_cast<int>(nums.size()) - 1;
    auto mid = 0;
    while (left <= right) {
      mid = (left + right) >> 1;
      if (mid == 0 || mid == last_idx) {
        break;
      }

      if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid + 1]) {
        return mid;
      } else if (nums[mid] > nums[mid-1]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    if (mid == 0) {
      if (nums[0] > nums[1]) {
        return 0;
      } else {
        return 1;
      }
    }
    if (mid == last_idx) {
      if (nums[mid] > nums[mid - 1]) {
        return mid;
      }
    }
    return mid - 1;
  }
};
