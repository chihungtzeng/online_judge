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
  int maxScore(vector<int>& nums)
  {
    vector<int> cache(1 << 14, 0);
    vector<vector<int>> gcds(nums.size(), vector<int>(nums.size()));

    for (int i = 0; i < nums.size(); i++)
    {
      for (int j = i + 1; j < nums.size(); j++)
      {
        gcds[i][j] = gcd(nums[i], nums[j]);
      }
    }

    return helper(nums, cache, gcds, 1, 0);
  }
  int helper(const vector<int>& nums, vector<int>& cache, const vector<vector<int>>& gcds, const int weight,
             const int mask)
  {
    if (weight > (nums.size() >> 1))
      return 0;

    if (cache[mask])
    {
      return cache[mask];
    }

    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if ((mask >> i) & 1)
        continue;

      for (int j = i + 1; j < nums.size(); j++)
      {
        if ((mask >> j) & 1)
          continue;

        const int can = gcds[i][j] * weight + helper(nums, cache, gcds, weight + 1, mask | (1 << i) | (1 << j));
        ans = max(can, ans);
      }
    }
    cache[mask] = ans;
    return ans;
  }
};
