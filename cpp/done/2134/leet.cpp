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
  int minSwaps(vector<int>& nums)
  {
    int w = accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size();
    if (w <= 1)
      return 0;
    if (w >= n - 1)
      return 0;
    int nz = 0;
    for (int i = 0, j = w - 1; i <= j; i++)
    {
      nz += (1 - nums[i]);
    }
    int ans = nz;
    for (int i = w, j = w - 1; i != j; i = (i + 1) % n)
    {
      nz -= (1 - nums[(i - w + n) % n]);
      nz += (1 - nums[i]);
      ans = min(ans, nz);
    }
    return ans;
  }
};
