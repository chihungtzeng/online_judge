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

class Solution {
 public:
  bool canMeasureWater(int x, int y, int z) {
    if (x + y < z) {
      return false;
    }
    auto gcd = std::gcd(x, y);
    if (gcd == 0 && z != 0) {
      return false;
    }
    if (gcd != 0 && z % gcd != 0) {
      return false;
    }
    return true;
  }
};
