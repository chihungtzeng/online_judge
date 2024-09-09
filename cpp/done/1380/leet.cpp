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
  vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();

    vector<int> ans;
    for (int i = 0; i < m; i++) {
      auto it = min_element(matrix[i].begin(), matrix[i].end());
      int can = *it;
      int offset = it - matrix[i].begin();
      bool is_max = true;
      for (int j = 0; j < m && is_max; j++) {
        if (matrix[j][offset] > can) {
          is_max = false;
        }
      }
      if (is_max) ans.push_back(can);
    }

    return ans;
  }
};
