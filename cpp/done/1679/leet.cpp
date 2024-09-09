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
  int maxOperations(vector<int>& nums, int k) {
    unordered_map<int, int> cnt;
    for (auto v : nums) {
      cnt[v]++;
    }
    int ans = 0;
    bool k_is_even = bool(k % 2 == 0);
    for (auto& [val, c] : cnt) {
      int target = k - val;
      if (target < val) {
        continue;
      }
      if (target == val && k_is_even) {
        ans += c / 2;
        continue;
      }
      auto it = cnt.find(target);
      if (it == cnt.end()) {
        continue;
      }
      ans += min(c, it->second);
    }
    return ans;
  }
};
