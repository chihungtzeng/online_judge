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
  int maxArea(vector<int>& hs)
  {
    using ipair = pair<int, int>;
    vector<ipair> val_pos(hs.size());
    int n = hs.size();
    for (int i = 0; i < n; i++)
    {
      val_pos[i].first = hs[i];
      val_pos[i].second = i;
    }
    sort(val_pos.begin(), val_pos.end());
    int small = val_pos.back().second;
    int large = small;
    int ans = 0;
    for (int i = n - 2; i >= 0; i--)
    {
      auto [val, pos] = val_pos[i];
      int area = 0;
      if (large > pos)
      {
        area = (large - pos) * val;
      }
      if (small < pos)
      {
        area = max(area, (pos - small) * val);
      }
      small = min(small, pos);
      large = max(large, pos);
      ans = max(ans, area);
    }
    return ans;
  }
};
