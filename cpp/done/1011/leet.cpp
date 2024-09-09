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
  int shipWithinDays(vector<int>& weights, int days)
  {
    int left = 0, right = 0;
    for (auto w : weights)
    {
      left = max(left, w);
      right += w;
    }
    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      int min_days = days_of_shipping(weights, mid);
      if (min_days > days)
      {
        left = mid + 1;
      }
      else
      {
        right = mid - 1;
      }
    }
    return right + 1;
  }
  int days_of_shipping(vector<int>& weights, int load)
  {
    int days = 0;
    int cur_load = 0;
    for (auto w : weights)
    {
      if (cur_load + w > load)
      {
        days++;
        cur_load = w;
      }
      else
      {
        cur_load += w;
      }
    }
    return days + 1;
  }
};
