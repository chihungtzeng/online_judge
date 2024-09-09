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
  int majorityElement(vector<int>& nums)
  {
    int can = INT_MAX, rep = -1;
    for (auto val : nums)
    {
      if (val != can)
      {
        rep--;
        if (rep < 0)
        {
          can = val;
          rep = 1;
        }
      }
      else
      {
        rep++;
      }
    }
    return can;
  }
};
