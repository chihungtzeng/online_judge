#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int lastRemaining(int n) { return helper(n, 0); }
  int helper(int n, int dir) {
    if (n == 1) {
      return 1;
    }
    if (dir == 0) {
      return 2 * helper(n / 2, 1 - dir);
    } else {
      if (n % 2 == 0) {
        return 2 * helper(n / 2, 1 - dir) - 1;
      } else {
        return 2 * helper(n / 2, 1 - dir);
      }
    }
  }
};
