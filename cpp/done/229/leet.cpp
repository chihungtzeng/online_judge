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
  vector<int> majorityElement(vector<int>& nums)
  {
    int v1 = 0, v2 = 1, c1 = 0, c2 = 0;
    for (auto val : nums)
    {
      if (v1 == val)
      {
        c1++;
      }
      else if (val == v2)
      {
        c2++;
      }
      else if (c1 == 0)
      {
        v1 = val;
        c1 = 1;
      }
      else if (c2 == 0)
      {
        v2 = val;
        c2 = 1;
      }
      else
      {
        c1--;
        c2--;
      }
    }

    vector<int> cans{ v1, v2 };
    vector<int> ans;
    for (auto val : cans)
    {
      int freq = 0;
      for (auto e : nums)
      {
        if (val == e)
          freq++;
      }
      if (freq > nums.size() / 3)
      {
        ans.push_back(val);
      }
    }

    return ans;
  }
};
