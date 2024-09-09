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
  bool isPossible(vector<int>& nums) {
    unordered_map<int, int> cnt, ends_at;
    for (auto v : nums) {
      cnt[v] += 1;
    }
    for (auto v : nums) {
      if (cnt[v] == 0) continue;
      if (ends_at[v - 1] > 0) {
        int m = min(ends_at[v - 1], cnt[v]);
        ends_at[v] += m;
        ends_at[v - 1] -= m;
        cnt[v] -= m;
      }
      if (cnt[v] > 0) {
        if (cnt[v + 1] >= cnt[v] and cnt[v + 2] >= cnt[v]) {
          ends_at[v + 2] += cnt[v];
          cnt[v + 1] -= cnt[v];
          cnt[v + 2] -= cnt[v];
          cnt[v] = 0;
        } else {
          return false;
        }
      }
    }
    return true;
  }
};
