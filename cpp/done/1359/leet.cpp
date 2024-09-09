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
  const int base = 1e9 + 7;
  int countOrders(int n) {
    if (n == 1) return 1;
    int64_t ans = 1;
    for (int i = 2; i <= n; i++) {
      ans = (ans * i * (2 * i - 1)) % base;
    }
    return ans;
  }
};
