#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <queue>
using namespace std;

class Solution
{
public:
  vector<int> searchRange(vector<int>& nums, int target)
  {
    if (nums.empty())
      return { -1, -1 };
    int left = lowerbound(nums, target);
    if (left >= 0 && left < nums.size() && nums[left] == target)
    {
      return { left, upperbound(nums, target) };
    }
    else
    {
      return { -1, -1 };
    }
  }
  int upperbound(vector<int>& nums, int target)
  {
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
      int mid = (left + right) / 2;
      if (nums[mid] <= target)
      {
        left = mid + 1;
      }
      else
      {
        right = mid - 1;
      }
    }
    return left - 1;
  }

  int lowerbound(vector<int>& nums, int target)
  {
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
      int mid = (left + right) / 2;
      if (nums[mid] >= target)
      {
        right = mid - 1;
      }
      else
      {
        left = mid + 1;
      }
    }
    return right + 1;
  }
};
