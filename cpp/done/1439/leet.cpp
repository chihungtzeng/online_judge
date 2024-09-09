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
  int kthSmallest(vector<vector<int>>& mat, int k) {
    const int rows = mat.size();
    const int cols = mat[0].size();
    vector<int> temp;
    vector<int> ans{0};
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        for (auto v : ans) {
          temp.push_back(v + mat[i][j]);
        }
      }
      const int nelem = min((int)temp.size(), k);
      ans.clear();
      sort(temp.begin(), temp.end());
      for (int j = 0; j < nelem; j++) {
        ans.push_back(temp[j]);
      }
      temp.clear();
    }
    return ans[k - 1];
  }
};
