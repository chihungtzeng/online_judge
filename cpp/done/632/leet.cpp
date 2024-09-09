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
  vector<int> smallestRange(vector<vector<int>>& nums)
  {
    auto vals = merge(nums);
    int left = 0, right = vals.back() - vals[0] + 1;
    int sp = 0;
    vector<int> ans{ 0, INT_MAX };
    while (left <= right)
    {
      int len = (left + right) / 2;
      if (can_cover(vals, nums, len, &sp))
      {
        right = len - 1;
        if (len < ans[1] || (len == ans[1] && sp < ans[0]))
        {
          ans[0] = sp;
          ans[1] = len;
        }
      }
      else
      {
        left = len + 1;
      }
    }
    ans[1] = ans[0] + ans[1] - 1;
    return ans;
  }

  bool can_cover(vector<int>& vals, vector<vector<int>>& nums, int len, int* start)
  {
    for (auto val : vals)
    {
      int end = val + len - 1;
      bool can = true;
      for (int i = nums.size() - 1; i >= 0 && can; i--)
      {
        auto it = lower_bound(nums[i].begin(), nums[i].end(), val);
        if (it == nums[i].end() || *it > end)
        {
          can = false;
        }
      }
      if (can)
      {
        *start = val;
        return true;
      }
    }
    return false;
  }

  vector<int> merge(vector<vector<int>>& nums)
  {
    vector<int> res;
    for (auto& a : nums)
    {
      for (auto v : a)
      {
        res.push_back(v);
      }
    }
    sort(res.begin(), res.end());
    int last = 0;
    for (int i = 1; i < res.size(); i++)
    {
      if (res[i] != res[last])
      {
        last++;
        res[last] = res[i];
      }
    }
    for (int i = res.size() - 1; i > last; i--)
    {
      res.pop_back();
    }
    return res;
  }
};
