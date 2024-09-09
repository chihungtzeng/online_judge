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
  int numberOfArrays(vector<int>& differences, int lower, int upper)
  {
    int64_t min_acc = INT_MAX;
    int64_t max_acc = INT_MIN;
    int64_t cur_acc = 0;
    for (auto d : differences)
    {
      cur_acc += d;
      min_acc = min(min_acc, cur_acc);
      max_acc = max(max_acc, cur_acc);
    }
    int64_t min_a0 = lower - min_acc;
    int64_t max_a0 = upper - max_acc;
    if (min_a0 > max_a0)
      return 0;
    int64_t left = max(min_a0, (int64_t)lower);
    int64_t right = min(max_a0, (int64_t)upper);
    if (left > right)
      return 0;
    return right - left + 1;
  }
};
