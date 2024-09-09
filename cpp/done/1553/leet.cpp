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
  unordered_map<int, int> cache;
  int minDays(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    auto it = cache.find(n);
    if (it != cache.end()) return it->second;

    cache[n] = 1 + min(n % 2 + minDays(n >> 1), n % 3 + minDays(n / 3));
    return cache[n];
  }
};
