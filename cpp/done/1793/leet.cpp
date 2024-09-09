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
  int maximumScore(vector<int>& nums, int k)
  {
    int ans = nums[k];
    const int n = nums.size();
    int l = k, r = k;
    for (int v = nums[k]; v >= 1;)
    {
      while (l >= 0 && nums[l] >= v)
        l--;
      while (r < n && nums[r] >= v)
        r++;

      ans = max(ans, (r - l - 1) * v);
      v = 0;
      if (l >= 0 && v < nums[l])
      {
        v = nums[l];
      }
      if (r < n && v < nums[r])
      {
        v = nums[r];
      }
    }
    return ans;
  }
};
