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
  int numSub(string s) {
    int ret = 0;
    int cur = 0;
    for (auto ch : s) {
      if (ch - '0') {
        cur++;
      } else {
        cur = 0;
      }
      ret = (ret + cur) % 1000000007;
    }
    return ret;
  }
};
