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
  int minEatingSpeed(vector<int>& piles, int h)
  {
    int left = 1, right = *max_element(piles.begin(), piles.end());
    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      if (can_finish(piles, h, mid))
      {
        right = mid - 1;
      }
      else
      {
        left = mid + 1;
      }
    }
    return right + 1;
  }
  bool can_finish(vector<int>& piles, int h, int k)
  {
    int elapse = 0;
    for (auto val : piles)
    {
      elapse += (val / k) + !!(val % k);
    }
    return elapse <= h;
  }
};
