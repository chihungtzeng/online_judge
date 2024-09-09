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
  int maximumGood(vector<vector<int>>& grid)
  {
    const int n = grid.size();
    int ans = 0;
    for (int i = (1 << n) - 1; i >= 0; i--)
    {
      int bcnt = bit_count(i);
      if (bcnt > ans && match(i, grid))
      {
        ans = bcnt;
      }
    }
    return ans;
  }

  int bit_count(int v)
  {
    int res = 0;
    while (v > 0)
    {
      res += (v & 1);
      v >>= 1;
    }
    return res;
  }

  bool is_good_person(int v, int idx)
  {
    return (v >> idx) & 1;
  }
  bool match(int v, vector<vector<int>>& grid)
  {
    int n = grid.size();
    for (int i = 0; i < n; i++)
    {
      if (is_good_person(v, i))
      {
        for (int j = 0; j < n; j++)
        {
          if (grid[i][j] == 1 && !is_good_person(v, j))
            return false;
          if (grid[i][j] == 0 && is_good_person(v, j))
            return false;
        }
      }
    }
    return true;
  }
};
