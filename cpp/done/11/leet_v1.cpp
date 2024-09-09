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
  int maxArea(vector<int>& height)
  {
    int ans = 0;
    int left = 0, right = height.size() - 1;
    int cur_h = min(height[left], height[right]);
    ans = cur_h * (right - left);
    while (left < right && left < height.size() && right >= 0)
    {
      while (left < height.size() && height[left] <= cur_h)
        left++;
      while (right >= 0 && height[right] <= cur_h)
        right--;
      if (left < height.size() && right >= 0)
      {
        cur_h = min(height[left], height[right]);
        ans = max(ans, cur_h * (right - left));
      }
    }
    return ans;
  }
};
