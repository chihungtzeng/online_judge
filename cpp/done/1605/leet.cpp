#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
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

class Solution {
 public:
  int rows;
  int cols;
  vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    rows = rowSum.size();
    cols = colSum.size();
    vector<vector<int>> ans(rows, vector<int>(cols));
    dfs(ans, rowSum, colSum, 0, 0);
    return ans;
  }

  int dfs(vector<vector<int>>& ans, vector<int>& rowSum, vector<int>& colSum,
          int r, int c) {
    if (r == rows && c == 0) {
      int rsum = accumulate(rowSum.begin(), rowSum.end(), 0);
      int csum = accumulate(colSum.begin(), colSum.end(), 0);
      if (rsum == 0 and csum == 0)
        return 0;
      else
        return 1;
    }

    if (c == cols - 1) {
      if (rowSum[r] < 0) return 1;
      ans[r][c] = rowSum[r];
      rowSum[r] = 0;
      colSum[c] -= ans[r][c];
      int ret = dfs(ans, rowSum, colSum, r + 1, 0);
      if (ret == 0) return 0;

      rowSum[r] += ans[r][c];
      colSum[c] += ans[r][c];
      return 1;
    } else if (r == rows - 1) {
      ans[r][c] = colSum[c];
      rowSum[r] -= ans[r][c];
      colSum[c] = 0;
      int ret = dfs(ans, rowSum, colSum, r, c+1);
      if (ret == 0) return 0;

      rowSum[r] += ans[r][c];
      colSum[c] += ans[r][c];
      return 1;

    } else {
      int ub = min(rowSum[r], colSum[c]);
      if (ub < 0) return 1;
      for (int i = ub; i >=0; i--) {
        ans[r][c] = i;
        rowSum[r] -= i;
        colSum[c] -= i;
        int nr = r, nc = c + 1;
        if (nc == cols) {
          nr = r + 1;
          nc = 0;
        }
        int ret = dfs(ans, rowSum, colSum, nr, nc);
        if (ret == 0) {
          return 0;
        }
        rowSum[r] += i;
        colSum[c] += i;
      }
    }
    return 1;
  }
};
