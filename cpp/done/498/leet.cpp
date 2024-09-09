#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    vector<int> ret;
    int m = matrix.size();
    if (m == 0) return ret;
    int n = matrix[0].size();
    if (n == 0) return ret;

    ret.reserve(n * m);
    constexpr int up = 0, down = 1;
    int dir = up;

    for (int line = 0, bound = n + m - 2; line <= bound; line++) {
      int r = 0, c = 0;
      if (dir == up) {
        c = 0;
        r = line - c;
        if (r >= m) {
          r = m - 1;
          c = line - r;
        }
      } else {
        r = 0;
        c = line - r;
        if (c >= n) {
          c = n - 1;
          r = line - c;
        }
      }

      while (r >= 0 && c >= 0 && r < m && c < n) {
        ret.push_back(matrix[r][c]);
        if (dir == up) {
          r--;
          c++;
        } else {
          r++;
          c--;
        }
      }
      dir = 1 - dir;
    }
    return ret;
  }
};
