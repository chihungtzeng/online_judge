#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
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
  int maxEnvelopes(vector<vector<int>>& env) {
    auto cmp = [](const auto& a, const auto& b) {
      if (a[0] == b[0]) return a[1] > b[1];
      return a[0] < b[0];
    };
    sort(env.begin(), env.end(), cmp);
    vector<int> ys(env.size());
    for (int i = 0; i < env.size(); i++) {
      ys[i] = env[i][1];
    }
    return lis(ys);
  }
  int lis(vector<int>& nums) {
    vector<int> seq;
    for (auto num : nums) {
      auto it = lower_bound(seq.begin(), seq.end(), num);
      if (it == seq.end()) {
        seq.push_back(num);
      } else {
        *it = num;
      }
    }
    return seq.size();
  }
};
