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
  int divide(int a, int b)
  {
    if (a == b)
      return 1;
    if (a == INT_MIN && b == -1)
      return INT_MAX;
    if (b == 1)
      return a;
    if (b == -1)
    {
      return -a;
    }
    if (b == INT_MIN)
    {
      return 0;
    }
    if (a == INT_MIN)
      return handle_int_min(a, b);
    int pos = 1;
    if ((a < 0 && b > 0) || (a > 0 && b < 0))
    {
      pos = 0;
    }
    a = abs(a);
    b = abs(b);
    uint32_t c = b;
    int res = 0;
    while (a >= b)
    {
      int i = 0;
      while ((c << i) <= a)
        i++;
      i--;
      res += (1 << i);
      a -= (c << i);
    }
    if (pos)
      return res;
    else
      return -res;
  }
  int handle_int_min(int a, int b)
  {
    int pos = 1;
    if (b > 0)
    {
      pos = 0;
    }
    b = abs(b);
    uint32_t c = b;
    a = INT_MAX;
    int res = 0;
    while (a >= b)
    {
      int i = 0;
      while ((c << i) <= a)
        i++;
      i--;
      res += (1 << i);
      a -= (c << i);
    }
    a++;
    if (a == b)
      res++;
    return pos ? res : -res;
  }
};
