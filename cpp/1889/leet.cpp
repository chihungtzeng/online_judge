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

constexpr int base = 1e9 + 7;
class Solution {
 public:
  int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
    unordered_map<int, int> cnt;
    int max_package = 0;
    for (auto p : packages) {
      cnt[p]++;
      max_package = max(max_package, p);
    }
    for (auto& b : boxes) {
      sort(b.begin(), b.end());
    }
    const int nsupplier = boxes.size();
    uint64_t waste = 0x7fffffffffffff;
    for (int i = 0; i < nsupplier; i++) {
      if (boxes[i].back() < max_package) {
        continue;
      }
      uint64_t cur_waste = 0;
      for (auto& [p, freq] : cnt) {
        auto it = lower_bound(boxes[i].begin(), boxes[i].end(), p);
        cur_waste += abs(p - *it) * freq;
      }
      waste = min(cur_waste, waste);
    }
    if (waste == 0x7fffffffffffff) {
      return -1;
    } else {
      return waste % base;
    }
  }
};
