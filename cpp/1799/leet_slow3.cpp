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

using ipair = pair<int, int>;
class Solution
{
public:
  int maxScore(vector<int>& nums)
  {
    unordered_map<string, ipair> cache;
    auto [eval, gsum] = helper(nums, cache, nums.size());
    return eval;
  }
  ipair helper(vector<int> nums, unordered_map<string, ipair>& cache, int n)
  {
    if (n == 0)
      return { 0, 0 };
    string key = nums2str(nums);

    auto it = cache.find(key);
    if (it != cache.end())
    {
      return it->second;
    }

    int cur_eval = 0, cur_gsum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] < 0) continue;
      int a = nums[i];
      nums[i] = -1;
      for (int j = i + 1; j < nums.size(); j++)
      {
        if (nums[j] < 0) continue;

        int b = nums[j];
        nums[j] = -1;
        int g = gcd(a, b);
        auto [can_eval, can_gsum] = helper(nums, cache, n-2);
        if (can_eval + can_gsum + g > cur_eval)
        {
          cur_eval = can_eval + can_gsum + g;
          cur_gsum = can_gsum + g;
        }
        nums[j] = b;
      }
      nums[i] = a;
    }
    ipair ret{ cur_eval, cur_gsum };
    cache[key] = ret;
    return ret;
  }

  string nums2str(vector<int>& nums)
  {
    string s;
    for (auto v : nums)
    {
      if (v > 0)
      {
        s += to_string(v) + ",";
      }
    }
    return s;
  }
};
