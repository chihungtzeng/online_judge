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
  vector<int> rearrangeArray(vector<int>& nums)
  {
    const int n = nums.size();
    vector<int> ptmp, ntmp;
    ptmp.reserve(n / 2);
    ntmp.reserve(n / 2);
    for (auto v : nums)
    {
      if (v >= 0)
        ptmp.push_back(v);
      else
        ntmp.push_back(v);
    }
    for (int i = 0, j = 0; i < ntmp.size(); i++)
    {
      nums[j++] = ptmp[i];
      nums[j++] = ntmp[i];
    }
    return nums;
  }
};
