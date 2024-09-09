#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
  int maxDistance(vector<vector<int>>& grid)
  {
    int n = grid.size();
    deque<int> q;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 1)
        {
          q.push_back((i << 16) + j);
        }
      }
    }
    vector<int> dx{ 0, 0, 1, -1 }, dy{ -1, 1, 0, 0 };
    int ans = 0;
    while (!q.empty())
    {
      int pos = q.front();
      q.pop_front();
      int r = pos >> 16;
      int c = pos & 0xffff;
      for (int i = 0; i < 4; i++)
      {
        int nr = r + dx[i];
        int nc = c + dy[i];
        if (!valid(nr, nc, n))
        {
          continue;
        }
        if (grid[nr][nc] == 0)
        {
          grid[nr][nc] = grid[r][c] + 1;
          q.push_back((nr << 16) + nc);
          ans = grid[nr][nc];
        }
      }
    }
    ans--;
    return ans;
  }
  inline bool valid(int r, int c, int n)
  {
    return r >= 0 && r < n && c >= 0 && c < n;
  }
};
