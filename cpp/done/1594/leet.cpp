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
  int maxProductPath(vector<vector<int>>& grid) {
    const int rows = grid.size();
    const int cols = grid[0].size();
    vector<vector<int64_t>> min_(rows, vector<int64_t>(cols));
    vector<vector<int64_t>> max_(rows, vector<int64_t>(cols));
    min_[0][0] = grid[0][0];
    max_[0][0] = grid[0][0];

    for (int i = 1; i < rows; i++) {
      min_[i][0] = min_[i - 1][0] * grid[i][0];
      max_[i][0] = min_[i][0];
    }
    for (int i = 1; i < cols; i++) {
      min_[0][i] = min_[0][i - 1] * grid[0][i];
      max_[0][i] = min_[0][i];
    }

    for (int i = 1; i < rows; i++) {
      for (int j = 1; j < cols; j++) {
        vector<int64_t> vals{
            max_[i - 1][j] * grid[i][j], min_[i - 1][j] * grid[i][j],
            max_[i][j - 1] * grid[i][j], min_[i][j - 1] * grid[i][j]};
        sort(vals.begin(), vals.end());
        max_[i][j] = vals.back();
        min_[i][j] = vals[0];
      }
    }

    if (max_[rows - 1][cols - 1] < 0) return -1;

    const int base = 1e9 + 7;
    return max_[rows - 1][cols - 1] % base;
  }
};
