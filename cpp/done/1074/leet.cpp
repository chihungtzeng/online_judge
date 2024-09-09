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
  int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target)
  {
    const int nrows = matrix.size();
    const int ncols = matrix[0].size();
    matrix.emplace_back(vector<int>(ncols, 0));
    int ans = 0;

    for (int i = nrows - 1; i >= 0; i--)
    {
      for (int k = 0; k < ncols; k++)
      {
        matrix[i][k] += matrix[i + 1][k];
      }
      for (int j = nrows - 1; j >= i; j--)
      {
        vector<int> rowij(ncols, 0);
        for (int k = 0; k < ncols; k++)
        {
          rowij[k] = matrix[i][k] - matrix[j + 1][k];
        }
        ans += helper(rowij, target);
      }
    }
    return ans;
  }

  int helper(vector<int>& rowij, int target)
  {
    const int ncols = rowij.size();
    int res = 0;
    unordered_map<int, int> psum;
    int cur = 0;
    psum[0] = 1;

    for (int k = 0; k < ncols; k++)
    {
      cur += rowij[k];
      int lookfor = cur - target;
      auto it = psum.find(lookfor);
      if (it != psum.end())
      {
        res += it->second;
      }
      psum[cur] += 1;
    }
    // LOG(INFO) << rowij << " returns " << res;
    return res;
  }
};
