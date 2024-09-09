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
  int totalMoney(int n) {
    int amount = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (i % 7 == 1) {
        amount = i / 7 + 1;
      }
      ans += amount;
      amount++;
    }

    return ans;
  }
};

