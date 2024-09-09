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
  bool checkPowersOfThree(int n) {
    while (n > 0) {
      int r = n % 3;
      if (r == 2) {
        return false;
      }
      n = (n-r) / 3;
    }
    return true;
  }
};
