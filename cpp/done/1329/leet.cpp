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
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    const int rows = mat.size();
    const int cols = mat[0].size();

    for (int r = 0; r < rows; r++) {
      vector<int> temp;
      for (int i = r, c = 0; i < rows && c < cols; i++, c++) {
        temp.push_back(mat[i][c]);
      }
      sort(temp.begin(), temp.end());
      for (int i = r, c = 0, j = 0; i < rows && c < cols; i++, c++, j++) {
        mat[i][c] = temp[j];
      }
    }
    for (int c = 1; c < cols; c++) {
      vector<int> temp;
      for (int i = c, r = 0; i < cols && r < rows; r++, i++) {
        temp.push_back(mat[r][i]);
      }
      sort(temp.begin(), temp.end());
      for (int i = c, r = 0, j = 0; i < cols && r < rows; r++, i++, j++) {
        mat[r][i] = temp[j];
      }
    }
    return mat;
  }
};
