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

using ituple = tuple<int, int, int>;
class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    const int n = nums.size();
    vector<ituple> temp;
    temp.reserve(100000);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < nums[i].size(); j++) {
        temp.push_back({i + j, -i, nums[i][j]});
      }
    }
    sort(temp.begin(), temp.end());
    vector<int> ans;
    ans.reserve(temp.size());
    for (auto& [s, neg_r, v] : temp) {
      ans.push_back(v);
    }

    return ans;
  }
};
