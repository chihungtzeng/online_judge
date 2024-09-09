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
  int minSteps(int n)
  {
    if (n <= 1)
      return 0;
    if (n == 2)
      return 2;
    int ans = 0;
    int sq = sqrt(n);
    while ((n & 1) == 0)
    {
      ans += 2;
      n = n >> 1;
    }
    for (int i = 3; i <= sq; i += 2)
    {
      while (n % i == 0)
      {
        n = n / i;
        ans += i;
      }
    }
    if (n > 1)
      ans += n;
    return ans;
  }
};
