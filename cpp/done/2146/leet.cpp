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
#define DEBUG 0

class Solution
{
public:
  vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k)
  {
    using ipair = pair<int, int>;
    const int nrows = grid.size();
    const int ncols = grid[0].size();
    vector<vector<int>> dist(nrows, vector<int>(ncols, INT_MAX));
    deque<ipair> q;

    dist[start[0]][start[1]] = 0;
    const vector<int> offset_x{ 0, 1, 0, -1 }, offset_y{ -1, 0, 1, 0 };
    q.push_back({ start[0], start[1] });

    vector<vector<int>> res;
    res.reserve(k);
    while (!q.empty() && res.size() < k)
    {
      int qsize = q.size();
      for (int i = 0; i < qsize; i++)
      {
        auto [r, c] = q[i];
        if (grid[r][c] >= pricing[0] && grid[r][c] <= pricing[1] && grid[r][c] > 1)
        {
          res.push_back(vector<int>{ dist[r][c], grid[r][c], r, c });
        }

        for (int j = 0; j < 4; j++)
        {
          int nr = r + offset_x[j];
          int nc = c + offset_y[j];
          if (nr < 0 || nr >= nrows || nc < 0 || nc >= ncols)
            continue;
          if (grid[nr][nc] == 0)
            continue;
          if (dist[nr][nc] > dist[r][c] + 1)
          {
            dist[nr][nc] = dist[r][c] + 1;
            q.push_back({ nr, nc });
          }
        }
      }
      for (int i = 0; i < qsize; i++)
      {
        q.pop_front();
      }
    }
    sort(res.begin(), res.end());
    vector<vector<int>> ans;
    ans.reserve(k);
    for (int i = 0, j = min((int)res.size(), k); i < j; i++)
    {
      ans.push_back({ res[i][2], res[i][3] });
    }
    return ans;
  }
};
