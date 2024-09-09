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
  int numIslands(vector<vector<char>>& grid)
  {
    int res = 0;
    for (int r = 0; r < grid.size(); r++)
    {
      for (int c = 0; c < grid[0].size(); c++)
      {
        if (grid[r][c] == '1')
        {
          res++;
          dfs(grid, r, c);
        }
      }
    }
    return res;
  }
  void dfs(vector<vector<char>>& grid, const int r, const int c)
  {
    const vector<int8_t> dr{ 1, -1, 0, 0 }, dc{ 0, 0, 1, -1 };
    grid[r][c] = '2';
    for (int i = 0; i < 4; i++)
    {
      const int nr = r + dr[i];
      const int nc = c + dc[i];
      if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == '1')
      {
        dfs(grid, nr, nc);
      }
    }
  }
};
