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
  int rows, cols;
  int countSquares(vector<vector<int>>& matrix) {
    rows = matrix.size();
    cols = matrix[0].size();
    vector<int> vsum = matrix[0];
    int ans = count_square(vsum);
    for (int r = 1; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (matrix[r][c] == 0) {
          vsum[c] = 0;
        } else {
          vsum[c] += 1;
        }
      }
      ans += count_square(vsum);
    }
    return ans;
  }

  int count_square(vector<int>& vsum) {
    vector<int> width(vsum.size());
    vector<int> stack;
    width[0] = -1;
    stack.push_back(0);
    for (int i = 1; i < cols; i++) {
      while (!stack.empty() && vsum[stack.back()] >= vsum[i]) {
        stack.pop_back();
      }
      if (stack.empty()) {
        width[i] = -1;
      } else {
        width[i] = stack.back();
      }
      stack.push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < cols; i++) {
      int cur = i;
      int candidate = 0;
      while (cur >= 0) {
        candidate = max(candidate, min(vsum[cur], i - width[cur]));
        cur = width[cur];
      }
      ans += candidate;
    }
    // LOG(INFO) << "width: " << width;
    // LOG(INFO) << vsum << " ans: " << ans;
    return ans;
  }
};
