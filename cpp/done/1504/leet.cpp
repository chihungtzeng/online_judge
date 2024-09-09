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
  int numSubmat(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<int> cur(m, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (mat[i][j] == 0)
          cur[j] = 0;
        else
          cur[j]++;
      }
      ans += accu(cur);
    }
    return ans;
  }
  int accu(vector<int>& cur) {
    vector<int> stack;
    vector<int> sum(cur.size());
    for (int i = 0; i < cur.size(); i++) {
      while (!stack.empty() && cur[stack.back()] >= cur[i]) {
        stack.pop_back();
      }

      if (!stack.empty()){
        int last_idx = stack.back();
        sum[i] = (i - last_idx) * cur[i];
        sum[i] += sum[last_idx];
      } else {
        sum[i] = cur[i] * (i+1);
      }
      stack.push_back(i);
    }
    return accumulate(sum.begin(), sum.end(), 0);
  }
};
