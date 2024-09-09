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
  void sortColors(vector<int>& nums)
  {
    vector<int> cnt(3);
    for (auto v : nums)
    {
      cnt[v]++;
    }
    int i = 0;
    for (int j = 0; j <= 2; j++)
    {
      while (cnt[j]--)
      {
        nums[i++] = j;
      }
    }
  }
};
