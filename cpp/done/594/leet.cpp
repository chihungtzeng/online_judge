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
  int findLHS(vector<int>& nums)
  {
    sort(nums.begin(), nums.end());
    int ans = 0;
    int prev = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] == prev)
        continue;
      int target = nums[i] + 1;
      auto it = upper_bound(nums.begin() + i, nums.end(), target);
      it--;
      if (*it == target)
      {
        int dist = it - nums.begin();
        // LOG(INFO) << "target: " << target << ", *it: " << *it << ", dist: " << dist;
        ans = max(ans, dist - i + 1);
      }
      prev = nums[i];
    }
    return ans;
  }
};
