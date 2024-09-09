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
    map<vector<int>, ipair> cache;
    auto [eval, gsum] = helper(nums, cache);
    return eval;
  }
  ipair helper(vector<int> nums, map<vector<int>, ipair>& cache)
  {
    if (nums.size() == 0)
      return { 0, 0 };
    auto it = cache.find(nums);
    if (it != cache.end())
    {
      return it->second;
    }
    int cur_eval = 0, cur_gsum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      for (int j = i + 1; j < nums.size(); j++)
      {
        int g = gcd(nums[i], nums[j]);
        auto next_nums = trim(nums, i, j);
        auto [can_eval, can_gsum] = helper(next_nums, cache);
        if (can_eval + can_gsum + g > cur_eval)
        {
          cur_eval = can_eval + can_gsum + g;
          cur_gsum = can_gsum + g;
        }
      }
    }
    ipair ret{ cur_eval, cur_gsum };
    cache[nums] = ret;
    return ret;
  }

  vector<int> trim(vector<int>& nums, int i, int j){
    vector<int> res(nums.size() - 2);
    for(int k=0, p=0; k<nums.size(); k++){
      if (k != i && k != j) {
        res[p++] = nums[k];
      }
    }
    return res;
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
