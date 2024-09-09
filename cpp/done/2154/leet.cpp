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
  int findFinalValue(vector<int>& nums, int original)
  {
    sort(nums.begin(), nums.end());
    while (binary_search(nums.begin(), nums.end(), original))
    {
      original <<= 1;
    }
    return original;
  }
};
