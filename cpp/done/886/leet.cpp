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
  bool possibleBipartition(int n, vector<vector<int>>& dislikes)
  {
    vector<int8_t> colors(n + 1, -1);
    vector<vector<int16_t>> nbrs(n + 1);
    for (auto& p : dislikes)
    {
      nbrs[p[0]].push_back(p[1]);
      nbrs[p[1]].push_back(p[0]);
    }
    for (int i = n; i >= 1; i--)
    {
      if (colors[i] < 0 && !dfs(nbrs, colors, i, 0))
        return false;
    }
    return true;
  }
  bool dfs(vector<vector<int16_t>>& nbrs, vector<int8_t>& colors, const int cur, int8_t cur_color)
  {
    colors[cur] = cur_color;
    auto nbr_color = 1 - cur_color;
    for (const auto nbr : nbrs[cur])
    {
      if (colors[nbr] < 0)
      {
        if (!dfs(nbrs, colors, nbr, nbr_color))
          return false;
      }
      else if (colors[nbr] != nbr_color)
      {
        return false;
      }
    }
    return true;
  }
};
