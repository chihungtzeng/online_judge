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
  vector<int> sortEvenOdd(vector<int>& nums)
  {
    vector<int> odd, even;
    for (int i = 0, j = 1; i < nums.size(); i += 2, j += 2)
    {
      even.push_back(nums[i]);
      if (j < nums.size())
        odd.push_back(nums[j]);
    }
    sort(odd.begin(), odd.end(), greater<>());
    sort(even.begin(), even.end());
    for (int i = 0; i < odd.size(); i++)
    {
      nums[(i << 1) + 1] = odd[i];
    }
    for (int i = 0; i < even.size(); i++)
    {
      nums[(i << 1)] = even[i];
    }
    return nums;
  }
};
