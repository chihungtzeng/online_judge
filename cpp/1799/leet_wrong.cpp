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
    int weight = nums.size() / 2;
    int n = nums.size();
    bool done = false;
    int ans = 0;
    while (!done)
    {
      int g = 0;
      int i1 = 0, j1 = 0;
      for (int i = 0; i < n; i++)
      {
        if (nums[i] < 0)
        {
          continue;
        }
        int a = nums[i];
        for (int j = i + 1; j < n; j++)
        {
          if (nums[j] < 0)
            continue;

          int b = nums[j];
          int g_can = gcd(a, b);
          if (g_can > g)
          {
            g = g_can;
            i1 = i;
            j1 = j;
          }
        }
      }
      nums[i1] = -1;
      nums[j1] = -1;
      ans += g * weight;
      weight--;
      if (weight == 0)
      {
        done = true;
      }
    }

    return ans;
  }
};
