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
  int largestSubmatrix(vector<vector<int>>& matrix) {
    const int rows = matrix.size();
    const int cols = matrix[0].size();
    for (int r = 1; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (matrix[r][c]) {
          matrix[r][c] += matrix[r - 1][c];
        }
      }
    }
    int ans = 0;
    for (int r = 0; r < rows; r++) {
      sort(matrix[r].rbegin(), matrix[r].rend());
      for (int c = 0; c < cols; c++) {
        ans = max(ans, matrix[r][c] * (c + 1));
      }
    }
    return ans;
  }
};
