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
  int minMoves(int target, int m)
  {
    int ans = 0;
    while (target > 1)
    {
      if (target % 2 == 0 && m > 0)
      {
        target = target >> 1;
        m--;
        ans++;
      }
      else
      {
        if (m == 0)
        {
          ans += target - 1;
          target = 1;
        }
        else
        {
          target--;
          ans++;
        }
      }
    }
    return ans;
  }
};
