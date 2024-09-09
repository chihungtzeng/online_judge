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
    int n = intervals.size();
    using ipair = pair<int, int>;
    vector<ipair> eps;
    eps.reserve(2 * n + 2);
    for (auto& v : intervals)
    {
      eps.push_back({ v[0], -1 });
      eps.push_back({ v[1], 1 });
    }

    eps.push_back({ ni[0], -1 });
    eps.push_back({ ni[1], 1 });
    sort(eps.begin(), eps.end());
    int b = 0, start = 0;
    vector<vector<int>> ans;
    for (auto& [p, w] : eps)
    {
      if (b == 0)
      {
        start = p;
      }
      b += w;
      if (b == 0)
      {
        ans.push_back({ start, p });
      }
    }
    return ans;
  }
};
