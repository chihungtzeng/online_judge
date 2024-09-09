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
  void nextPermutation(vector<int>& nums)
  {
    int k = nums.size() - 1;
    while (k > 0 && nums[k - 1] >= nums[k])
    {
      k--;
    }
    int ell = k - 1;
    if (ell >= 0)
    {
      int j = ell + 1;
      while (j < nums.size() && nums[j] > nums[ell])
      {
        j++;
      }
      swap(nums[ell], nums[j - 1]);
    }
    reverse(nums.begin() + ell + 1, nums.end());
  }
};
