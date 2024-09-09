#include <algorithm>
#include <cstdint>
#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class NumMatrix {
  private:
  int nrows, ncols;
  vector<vector<int>> rsum;
public:
  NumMatrix(vector<vector<int>> &matrix) {
    nrows = matrix.size();
    if (nrows > 0) {
      ncols = matrix[0].size();
    } else {
      ncols = 0;
    }
    rsum = matrix;
    for(auto r=1; r<nrows; r++)
    {
      rsum[r][0] += rsum[r-1][0];
      }

    for(auto c=1; c<ncols; c++)
    {
      rsum[0][c] += rsum[0][c-1];
    }
    for(auto r=1; r<nrows; r++){
      for(auto c=1; c<ncols; c++)
      {
        rsum[r][c] += rsum[r-1][c] + rsum[r][c-1] - rsum[r-1][c-1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    if (nrows == 0 || ncols == 0) {
      return 0;
    }
    row1 = max(row1, 0);
    col1 = max(col1 , 0);
    row2 = min(row2, nrows-1);
    col2 = min(col2, ncols-1);
    if (row1 >=1 && col1 >=1){
      return rsum[row2][col2] - rsum[row2][col1-1] - rsum[row1-1][col2] + rsum[row1-1][col1-1];
    } else if (row1 == 0 && col1 >= 1)
    {
      return rsum[row2][col2] - rsum[row2][col1-1];
    } else if (row1 >= 1 && col1 == 0) {
      return rsum[row2][col2] - rsum[row1-1][col2];
    } else {
      return rsum[row2][col2];
    }
  }
};

