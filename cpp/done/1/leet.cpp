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
  vector<int> twoSum(vector<int>& nums, int target)
  {
    unordered_map<int, int> v2i;
    for (int i = 0; i < nums.size(); i++)
    {
      auto it = v2i.find(target - nums[i]);
      if (it != v2i.end())
      {
        return { it->second, i };
      }
      v2i[nums[i]] = i;
    }
    return { 0, 1 };
  }
};
