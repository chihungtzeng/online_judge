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
  vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    const int n = nums.size();
    vector<int> ans;
    ans.reserve(100000);
    int ub = 0;
    for (int i = 0; i < n; i++) {
      ub = max(ub, i + (int)nums[i].size());
    }
    for (int i = 0; i < ub; i++) {
      int c = 0;
      while (c <= i) {
        int r = i - c;
        if (!(r >= n || r < 0 || c >= nums[r].size() || c < 0)) {
          ans.push_back(nums[r][c]);
        }
        c++;
      }
    }
    return ans;
  }
};
