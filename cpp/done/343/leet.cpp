#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int pow(int n, int k) {
  int ret = 1;
  for (int i = 0; i < k; i++) {
    ret *= n;
  }
  return ret;
}

class Solution {
 public:
  int integerBreak(int n) {
    if (n == 2) return 1;
    if (n == 3) return 2;
    if (n == 4) return 4;
    int p = n / 3;
    int res = n % 3;

    if (res == 0) {
      return pow(3, p);
    }
    if (res == 1) {
      return pow(3, p - 1) * 4;
    }
    return pow(3, p) * 2;
  }
};
