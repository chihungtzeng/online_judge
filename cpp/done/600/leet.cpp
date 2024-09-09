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
  int findIntegers(int n)
  {
    if (n == 0)
      return 1;
    if (n == 1)
      return 2;
    if (n == 2)
      return 3;
    if (n == 3)
      return 3;
    int k = 0;
    while ((n >> k) >= 4)
      k++;
    int msb = n >> k;
    int lsb = n & ((1 << k) - 1);
    int temp = (1 << k) - 1;
    if (msb == 3)
    {
      return (findIntegers(temp) << 1) + findIntegers(temp >> 1);
    }
    return findIntegers(temp) + findIntegers(temp >> 1) + findIntegers(lsb);
  }
};
