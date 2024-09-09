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
  int kthLargestValue(vector<vector<int>>& matrix, int k) {
    const int rows = matrix.size();
    const int cols = matrix[0].size();
    const int n = rows*cols;
    vector<int> vals{matrix[0][0]};
    vals.reserve(n);

    for (int r = 1; r < rows; r++) {
      matrix[r][0] ^= matrix[r - 1][0];
      vals.push_back(matrix[r][0]);
    }
    for (int c = 1; c < cols; c++) {
      matrix[0][c] ^= matrix[0][c - 1];
      vals.push_back(matrix[0][c]);
    }
    for (int r = 1; r < rows; r++) {
      for (int c = 1; c < cols; c++) {
        matrix[r][c] ^=
            matrix[r][c - 1] ^ matrix[r - 1][c] ^ matrix[r - 1][c - 1];
        vals.push_back(matrix[r][c]);
      }
    }
    nth_element(vals.begin(), vals.begin() + n - k, vals.end());
    return *(vals.begin() + n - k);
  }
};
