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
    vector<ipair> cache(1 << 14);
    vector<vector<int>> gcds(nums.size(), vector<int>(nums.size()));

    for(int i=0; i<nums.size(); i++){
      for(int j=i+1; j<nums.size(); j++){
        gcds[i][j] = gcd(nums[i], nums[j]);
      }
    }

    int mask = 0;
    auto [eval, gsum] = helper(nums, cache, gcds, nums.size(), mask);
    return eval;
  }
  ipair helper(const vector<int>& nums, vector<ipair>& cache, const vector<vector<int>>& gcds, const int n, const int mask)
  {
    if (n == 0)
      return { 0, 0 };

    if (cache[mask].first > 0) {
      return cache[mask];
    }

    int cur_eval = 0, cur_gsum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if ((mask >> i) & 1)
        continue;

      for (int j = i + 1; j < nums.size(); j++)
      {
        if ((mask >> j) & 1)
          continue;

        int g = gcds[i][j];
        auto [can_eval, can_gsum] = helper(nums, cache, gcds, n - 2, mask | (1 << i) | (1 << j));
        int temp_eval = can_eval + can_gsum + g;
        if (temp_eval > cur_eval)
        {
          cur_eval = temp_eval;
          cur_gsum = can_gsum + g;
        } else if (temp_eval == cur_eval && can_gsum + g > cur_gsum) {
          cur_eval = temp_eval;
          cur_gsum = can_gsum + g;
        }
      }
    }
    ipair ret{ cur_eval, cur_gsum };
    cache[mask] = ret;
    return ret;
  }
};
