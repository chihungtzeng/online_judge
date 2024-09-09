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
  vector<int> pivotArray(vector<int>& nums, int pivot)
  {
    const int n = nums.size();
    vector<int> lt, gt;
    lt.reserve(n);
    gt.reserve(n);
    int neq = 0;
    for (auto v : nums)
    {
      if (v < pivot)
        lt.push_back(v);
      else if (v == pivot)
        neq++;
      else
        gt.push_back(v);
    }
    while (neq--)
      lt.push_back(pivot);
    for (auto v : gt)
      lt.push_back(v);
    return lt;
  }
};
