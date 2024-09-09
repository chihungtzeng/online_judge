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
  int maxSideLength(vector<vector<int>>& mat, int threshold) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> psum(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        psum[i][j] = mat[i - 1][j - 1] + psum[i][j - 1] + psum[i - 1][j] -
                     psum[i - 1][j - 1];
      }
    }
    int len = 0;
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        int i0 = i - len - 1;
        int j0 = j - len - 1;
        if (i0 >= 0 && j0 >= 0 &&
            psum[i][j] - psum[i0][j] - psum[i][j0] + psum[i0][j0] <=
                threshold) {
          len++;
        }
      }
    }
    return len;
  }
};
