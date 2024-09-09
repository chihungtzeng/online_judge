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
  vector<vector<int>> findSubsequences(const vector<int>& nums) {
    vector<vector<int>> ret, ans;
    if (nums.empty()) {
      return ans;
    }
    vector<int> cur;
    helper(nums, ret, cur, 0);
    if (!ret.empty()) {
      sort(ret.begin(), ret.end());
      ans.push_back(ret[0]);
      for (size_t i = 1; i < ret.size(); i++) {
        if (ret[i] != ret[i - 1]) ans.push_back(ret[i]);
      }
    }
    return ans;
  }
  void helper(const vector<int>& nums, vector<vector<int>>& ret,
              vector<int>& cur, const int pos) {
    if (pos == nums.size()) return;
    helper(nums, ret, cur, pos + 1);

    if (cur.empty()) {
      cur.push_back(nums[pos]);
      helper(nums, ret, cur, pos + 1);
      cur.pop_back();
    } else if (cur.back() <= nums[pos]) {
      cur.push_back(nums[pos]);
      ret.push_back(cur);
      helper(nums, ret, cur, pos + 1);
      cur.pop_back();
    }
  }
};
