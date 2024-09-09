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
  vector<int> findLonely(vector<int>& nums)
  {
    unordered_map<int, int> freq;
    for (auto v : nums)
    {
      freq[v]++;
    }
    nums.clear();
    for (const auto [v, f] : freq)
    {
      if (f == 1)
      {
        auto it = freq.find(v + 1);
        auto it2 = freq.find(v - 1);
        if (it == freq.end() && it2 == freq.end())
        {
          nums.push_back(v);
        }
      }
    }
    return nums;
  }
};
