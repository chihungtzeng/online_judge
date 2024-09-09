#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int integerReplacement(int n) {
    return integerReplacement(static_cast<int64_t>(n));
  }
  int integerReplacement(int64_t n) {
    if (n == 1) {
      return 0;
    } else if ((n & (n - 1)) == 0) {
      int c = 0;
      while (n > 1) {
        c++;
        n >>= 1;
      }
      return c;
    } else if (n % 2 == 0) {
      return 1 + integerReplacement(n >> 1);
    } else {
      return min(integerReplacement(n - 1), integerReplacement(n + 1)) + 1;
    }
  }
};
