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
  int surfaceArea(vector<vector<int>>& mat)
  {
    const int n = mat.size();
    int ncubes = 0;
    int nadj = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        ncubes += mat[i][j];
        if (j < n - 1)
        {
          nadj += min(mat[i][j], mat[i][j + 1]);
        }
        nadj += max(0, mat[i][j] - 1);
      }
    }
    for (int r = 1; r < n; r++)
    {
      for (int c = 0; c < n; c++)
      {
        nadj += min(mat[r][c], mat[r - 1][c]);
      }
    }
    return 6 * ncubes - 2 * nadj;
  }
};
