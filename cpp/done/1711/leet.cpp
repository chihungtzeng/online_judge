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
  int countPairs(vector<int>& ds) {
    vector<int> pow2(22);
    for (int i = 0; i < 22; i++) {
      pow2[i] = 1 << i;
    }
    unordered_map<int64_t, int64_t> cnt;
    for (auto d : ds) {
      cnt[d]++;
    }
    uint64_t ans = 0;
    for (auto [val, freq] : cnt) {
      for (int i = 0; i < 22; i++) {
        int target = pow2[i] - val;
        uint64_t addon = 0;
        if (target > val) {
          addon = 0;
        } else if (target == val) {
          addon = freq * (freq - 1) / 2;
        } else {
          auto it = cnt.find(target);
          if (it != cnt.end()) {
            addon = freq * it->second;
          }
        }
        // LOG(INFO) << "val: " << val << " target: " << target << " addon: " <<
        // addon;
        ans += addon;
      }
    }
    return ans % base;
  }
};
