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
#define DEBUG 0

constexpr int64_t base = 1e9 + 7;
using ipair = pair<int64_t, int64_t>;
class Solution {
 public:
  int maxProfit(vector<int>& inventory, int orders) {
    unordered_map<int, int> cnt;
    for (auto v : inventory) {
      cnt[v]++;
    }
    vector<ipair> amounts;
    for (auto& [val, freq] : cnt) {
      amounts.emplace_back(val, freq);
    }
    sort(amounts.begin(), amounts.end(), greater<ipair>());
    int64_t k = find_k(amounts, orders);
    int64_t ans = 0;
    for (auto& [val, freq] : amounts) {
      if (val > k) {
        ans += (val * (val + 1) / 2 - k * (k + 1) / 2) * freq;
        orders -= (val - k) * freq;
        ans %= base;
      } else {
        break;
      }
    }
    if (orders > 0) {
      ans = (ans + orders * k) % base;
    }
    return ans;
  }
  int64_t find_k(vector<ipair>& amounts, const int64_t target) {
    int64_t l = 0, r = amounts[0].first;
    while (l <= r) {
      int64_t mid = l + (r - l) / 2;
      if (is_valid(amounts, target, mid)) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return l;
  }
  bool is_valid(vector<ipair>& amounts, const int64_t target,
                const int64_t mid) {
    int64_t total = 0;
    for (auto& [val, freq] : amounts) {
      if (val > mid) {
        total += (val - mid) * freq;
      }
      else {
        break;
      }
    }
    return total <= target;
  }
};
