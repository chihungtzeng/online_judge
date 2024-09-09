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
  bool canDistribute(vector<int>& nums, vector<int>& quantity) {
    unordered_map<int, int> cnt;

    for (auto v : nums) {
      cnt[v]++;
    }
    sort(quantity.begin(), quantity.end(), greater<int>());

    return dfs(cnt, quantity, 0);
  }

  bool dfs(unordered_map<int, int>& cnt, vector<int>& quantity, size_t idx) {
    if (idx == quantity.size()) {
      return true;
    }
    for (auto& [key, val] : cnt) {
      if (val >= quantity[idx]) {
        cnt[key] -= quantity[idx];
        if (dfs(cnt, quantity, idx + 1)) {
          return true;
        }
        cnt[key] += quantity[idx];
      }
    }
    return false;
  }
};
