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

class Solution {
 public:
  int largestMagicSquare(vector<vector<int>>& grid) {
    const int rows = grid.size();
    const int cols = grid[0].size();
    auto rsum = grid;
    auto csum = grid;
    auto dr = grid;
    auto dl = grid;

    for (int r = 1; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        rsum[r][c] += rsum[r - 1][c];
      }
    }
    for (int c = 1; c < cols; c++) {
      for (int r = 0; r < rows; r++) {
        csum[r][c] += csum[r][c - 1];
      }
    }
    for (int r = 1; r < rows; r++) {
      for (int c = 0; c < cols - 1; c++) {
        dl[r][c] += dl[r - 1][c + 1];
      }
    }
    for (int r = 1; r < rows; r++) {
      for (int c = 1; c < cols; c++) {
        dr[r][c] += dr[r - 1][c - 1];
      }
    }
#if 0    
    for(auto& row: dr)
    {
      LOG(INFO) << row;
    }
#endif
    const int max_magic_grid_len = min(rows, cols);
    int ans = 1;
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        for (int len = 2; len <= max_magic_grid_len; len++) {
          if (len <= ans) continue;
          if (r + len - 1 >= rows) continue;
          if (c + len - 1 >= cols) continue;
          if (!is_magic_square(r, c, len, rsum, csum, dl, dr)) continue;
          ans = max(ans, len);
        }
      }
    }
    return ans;
  }

  bool is_magic_square(const int r, const int c, const int len,
                       const vector<vector<int>>& rsum,
                       const vector<vector<int>>& csum,
                       const vector<vector<int>>& dl,
                       const vector<vector<int>>& dr) {
    const int rows = rsum.size();
    const int cols = rsum[0].size();
    if (r + len - 1 >= rows || c + len - 1 >= cols) return false;
    if (len == 1) return true;
    const auto dls = get_dl_sum(r, c, len, dl);
    const auto drs = get_dr_sum(r, c, len, dr);
    if (dls != drs) return false;
    for (int i = 0; i < len; i++) {
      if (dls != get_rsum(r, c + i, len, rsum)) return false;
    }
    for (int i = 0; i < len; i++) {
      if (dls != get_csum(r + i, c, len, csum)) return false;
    }
    return true;
  }
  int get_dl_sum(const int r, const int c, const int len,
                 const vector<vector<int>>& dl) {
    int prev = 0;
    if (r > 0 && c + len - 1 < dl[0].size() - 1) {
      prev = dl[r - 1][c + len];
    }
    return dl[r + len - 1][c] - prev;
  }

  int get_dr_sum(const int r, const int c, const int len,
                 const vector<vector<int>>& dr) {
    if (r == 0 || c == 0)
      return dr[r + len - 1][c + len - 1];
    else
      return dr[r + len - 1][c + len - 1] - dr[r - 1][c - 1];
  }

  int get_rsum(const int r, const int c, const int len,
               const vector<vector<int>>& rsum) {
    int prev = 0;
    if (r > 0) prev = rsum[r - 1][c];

    int ans = rsum[r + len - 1][c] - prev;
    return ans;
  }

  int get_csum(const int r, const int c, const int len,
               const vector<vector<int>>& csum) {
    if (c == 0)
      return csum[r][c + len - 1];
    else
      return csum[r][c + len - 1] - csum[r][c - 1];
  }
};
