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
  vector<string> findMissingRanges(vector<int>& nums, int l, int r) {
    vector<int> ps;
    vector<string> ans;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] >= l && nums[i] <= r) ps.push_back(nums[i]);
    }
    if (ps.empty()) {
      add_seg_string(l, r, ans);
      return ans;
    }
    if (ps[0] != l) {
      add_seg_string(l, ps[0] - 1, ans);
    }
    for (int i = 1; i < ps.size(); i++) {
      add_seg_string(ps[i - 1] + 1, ps[i] - 1, ans);
    }
    if (ps.back() != r) {
      add_seg_string(ps.back() + 1, r, ans);
    }
    return ans;
  }
  void add_seg_string(int from, int to, vector<string>& ans) {
    if (from > to) return;
    int len = to - from + 1;
    if (len == 1) {
      ans.emplace_back(to_string(from));
    } else {
      ans.emplace_back(to_string(from) + "->" + to_string(to));
    }
  }
};
