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
  bool isPowerOfFour(int n) {
    return bool((n > 0) && (n & (n - 1)) == 0 && (n % 3 == 1));
  }
};
