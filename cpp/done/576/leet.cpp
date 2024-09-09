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
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
  {
    const int base = 1e9 + 7;
    vector<vector<uint64_t>> moves(m, vector<uint64_t>(n, 0));
    const vector<vector<int>> nbrs{ { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };
    auto temp = moves;
    moves[startRow][startColumn] = 1;
    uint64_t ans = 0;

    while (maxMove--)
    {
#if 0
      LOG(INFO) << "maxMove: " << maxMove;
      for(int i=0; i<m; i++)
      {
        LOG(INFO) << moves[i];
      }
#endif
      for (int i = 0; i < m; i++)
      {
        ans += moves[i][0] + moves[i][n - 1];
      }
      for (int i = 0; i < n; i++)
      {
        ans += moves[0][i] + moves[m - 1][i];
      }
      ans %= base;

      for (int i = 0; i < m; i++)
      {
        for (int j = 0; j < n; j++)
        {
          temp[i][j] = 0;
          for (auto& nbr : nbrs)
          {
            int nr = i + nbr[0];
            int nc = j + nbr[1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n)
            {
              temp[i][j] += moves[nr][nc];
            }
          }
          temp[i][j] %= base;
        }
      }
      swap(moves, temp);
    }

    return ans;
  }
};
