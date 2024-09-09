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

struct Cell
{
  int row, col, price, dist;
  Cell(int r, int c, int p, int d) : row(r), col(c), price(p), dist(d)
  {
  }
  bool operator>(const Cell& other) const
  {
    if (dist != other.dist)
      return dist > other.dist;
    if (price != other.price)
      return price > other.price;
    if (row != other.row)
      return row > other.row;
    else
      return col > other.col;
  }

  bool operator<(const Cell& other) const
  {
    if (dist != other.dist)
      return dist < other.dist;
    if (price != other.price)
      return price < other.price;
    if (row != other.row)
      return row < other.row;
    else
      return col < other.col;
  }
  bool operator==(const Cell& other) const
  {
    return dist == other.dist && price == other.price && row == other.row && col == other.col;
  }
};

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
    priority_queue<Cell, vector<Cell>, greater<>> pq;

    dist[start[0]][start[1]] = 0;
    vector<int> offset_x{ 0, 1, 0, -1 }, offset_y{ -1, 0, 1, 0 };
    q.push_back({ start[0], start[1] });
    while (!q.empty() && pq.size() < k)
    {
      int qsize = q.size();
      for (int i = 0; i < qsize; i++)
      {
        auto [r, c] = q[i];
#ifdef DEBUG
        LOG(INFO) << "doing " << ipair{ r, c };
#endif
        if (grid[r][c] >= pricing[0] && grid[r][c] <= pricing[1] && grid[r][c] > 1)
        {
          pq.push(Cell(r, c, grid[r][c], dist[r][c]));
#ifdef DEBUG
          LOG(INFO) << ipair{ r, c } << " dist: " << dist[r][c] << " pushed to pq with " << grid[r][c];
#endif
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
#ifdef DEBUG
            LOG(INFO) << ipair{ nr, nc } << " dist: " << dist[nr][nc];
#endif
            q.push_back({ nr, nc });
          }
        }
      }
      for (int i = 0; i < qsize; i++)
      {
        q.pop_front();
      }
    }
    vector<vector<int>> res;
    res.reserve(k);
    while (k && !pq.empty())
    {
      k--;
      auto& cell = pq.top();
      res.push_back({ cell.row, cell.col });
      pq.pop();
    }
    return res;
  }
};
