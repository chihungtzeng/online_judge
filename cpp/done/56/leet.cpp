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
  vector<vector<int>> merge(vector<vector<int>>& intervals)
  {
    using ipair = pair<int, int>;
    vector<ipair> eps;
    const int n = intervals.size();
    eps.reserve(2 * n);
    for (auto& v : intervals)
    {
      eps.push_back({ v[0], -1 });
      eps.push_back({ v[1], 1 });
    }
    sort(eps.begin(), eps.end());
    vector<vector<int>> ans;
    int balance = 0, start = 0;
    for (auto& [p, w] : eps)
    {
      if (balance == 0 && w == -1)
      {
        start = p;
      }
      balance += w;
      if (balance == 0)
      {
        ans.push_back({ start, p });
      }
    }
    return ans;
  }
};
