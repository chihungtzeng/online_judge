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

const vector<vector<int>> nbrs = {
  { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 }
};
class Solution
{
public:
  vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)
  {
    int r = click[0], c = click[1];
    const int rows = board.size(), cols = board[0].size();

    if (board[r][c] == 'B' || (board[r][c] >= 1 && board[r][c] <= 8) || board[r][c] == 'X')
      return board;

    if (board[r][c] == 'M')
    {
      board[r][c] = 'X';
      return board;
    }

    vector<int> stack{ (r << 16) + c };

    while (!stack.empty())
    {
      const int pos = stack.back();
      stack.pop_back();
      const int cr = pos >> 16;
      const int cc = pos & 0xffff;

      flip(board, cr, cc);
      if (board[cr][cc] == 'B')
      {
        for (auto& nbr : nbrs)
        {
          const int nr = cr + nbr[0];
          const int nc = cc + nbr[1];
          if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && board[nr][nc] == 'E')
          {
            flip(board, nr, nc);
            stack.push_back((nr << 16) + nc);
          }
        }
      }
    }

    return board;
  }
  void flip(vector<vector<char>>& board, const int cr, const int cc)
  {
    int nearby_mine = 0;
    for (auto& nbr : nbrs)
    {
      const int nr = cr + nbr[0];
      const int nc = cc + nbr[1];
      if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() &&
          (board[nr][nc] == 'M' || board[nr][nc] == 'X'))
      {
        nearby_mine++;
      }
    }
    if (nearby_mine == 0)
    {
      board[cr][cc] = 'B';
    }
    else
    {
      board[cr][cc] = '0' + nearby_mine;
    }
    // LOG(INFO) << "board " << cr << ", " << cc << " : " << board[cr][cc];
  }
};
