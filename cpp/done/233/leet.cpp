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
  int countDigitOne(int n) {
    if (n <= 0) return 0;
    if (n <= 9) return 1;
    int64_t base = 10;
    while (n / base > 0) {
      base = base * 10;
    }
    base = base / 10;
    int msb = n / base;
    int64_t ret = 0;
    if (msb == 1) {
      ret += 1 + n % base;
    } else {
      ret += base;
    }
    ret += msb * countDigitOne(base - 1);
    ret += countDigitOne(n % base);
    return ret;
  }
};
