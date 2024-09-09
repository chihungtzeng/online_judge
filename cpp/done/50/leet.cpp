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
  double myPow(double x, int n)
  {
    if (n == 0)
      return 1;
    if (x == 0)
      return 0;
    int pos = 1;
    uint32_t p = n;
    if (n < 0)
    {
      pos = 0;
      if (n == INT_MIN) {
        p = -(n + 1);
        p++;
      }
      else {
        p = -n;
      }
    }
    double res = 1, y = x;
    while (p > 0)
    {
      if (p & 1)
      {
        res *= y;
      }
      p >>= 1;
      y = y * y;
    }
    if (!pos)
    {
      res = 1 / res;
    }
    return res;
  }
};
