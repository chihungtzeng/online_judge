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
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& ni)
  {
    vector<vector<int>> res;
    res.reserve(intervals.size() + 1);

    for (auto& seg : intervals)
    {
      if (!intersect(seg, ni))
      {
        if (ni[1] < seg[0])
        {
          res.push_back(ni);
          ni[0] = INT_MAX;
          ni[1] = INT_MAX;
        }
        res.push_back(seg);
      }
      else
      {
        ni[0] = min(ni[0], seg[0]);
        ni[1] = max(ni[1], seg[1]);
      }
    }
    if (ni[0] != INT_MAX)
    {
      res.push_back(ni);
    }
    return res;
  }
  bool intersect(vector<int>& a, vector<int>& b)
  {
    int s = max(a[0], b[0]);
    int e = min(a[1], b[1]);
    return bool(s <= e);
  }
};
