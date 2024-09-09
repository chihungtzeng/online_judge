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

class SubrectangleQueries {
 public:
  vector<vector<int>> rect_;
  SubrectangleQueries(vector<vector<int>>& rect) : rect_(rect) {}

  void updateSubrectangle(int row1, int col1, int row2, int col2,
                          int newValue) {
    for (int i = row1; i <= row2; i++) {
      for (int j = col1; j <= col2; j++) {
        rect_[i][j] = newValue;
      }
    }
  }

  int getValue(int row, int col) { return rect_[row][col]; }
};
