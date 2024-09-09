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
  int reverse(int x)
  {
    if (x == INT_MIN)
      return 0;
    bool pos = true;
    if (x < 0)
    {
      pos = false;
      x = -x;
    }
    int y = 0;
    while (x > 0)
    {
      int r = x % 10;
      if (y > (INT_MAX - r) / 10)
      {
        return 0;
      }
      y = y * 10 + r;
      x = x / 10;
    }
    if (pos)
      return y;
    else
      return -y;
  }
};
