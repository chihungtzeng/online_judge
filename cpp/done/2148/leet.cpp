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
  int countElements(vector<int>& nums)
  {
    if (nums.size() <= 2)
      return 0;
    unordered_map<int, int> freq;
    int ub = INT_MIN, lb = INT_MAX;
    for (auto v : nums)
    {
      freq[v]++;
      ub = max(ub, v);
      lb = min(lb, v);
    }
    if (lb == ub)
      return 0;

    return nums.size() - freq[lb] - freq[ub];
  }
};
