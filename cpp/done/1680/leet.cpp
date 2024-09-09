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
  vector<int64_t> cache;
  int concatenatedBinary(int n) {
    if (cache.empty()) {
      cache.push_back(0);
      cache.push_back(1);
    }

    for (int i = cache.size(); i <= n; i++) {
      int nbits = 0;
      int temp = i;
      while (temp > 0) {
        nbits++;
        temp >>= 1;
      }
      cache.push_back(((cache[i - 1] << nbits) + i) % base);
    }
    return cache[n];
  }
};
