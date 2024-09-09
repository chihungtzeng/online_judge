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
  bool canBeIncreasing(vector<int>& nums)
  {
    int pos = nums.size() - 1;
    while (pos > 0 && nums[pos] > nums[pos - 1])
      pos--;
    if (pos <= 1)
      return true;
    // remove nums[pos-1]
    for (auto skip : vector<int>{ pos - 1, pos })
    {
      int ub = nums.size() - 1;
      ub = min(ub, pos + 1);
      bool inc = true;
      for (int j = 1; j <= ub && inc; j++)
      {
        if (j == skip)
        {
          continue;
        }
        int prev = j - 1;
        if (prev == skip)
          prev--;

        if (nums[j] <= nums[prev])
        {
          inc = false;
        }
      }
      if (inc)
      {
        return true;
      }
    }
    return false;
  }
};
