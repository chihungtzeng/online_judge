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
  long long maxAlternatingSum(vector<int>& nums)
  {
    long long even = 0, odd = 0;
    for (auto val : nums)
    {
      auto next_even = max(odd - val, even);
      auto next_odd = max(even + val, odd);
      even = next_even;
      odd = next_odd;
    }
    return max(even, odd);
  }
};
