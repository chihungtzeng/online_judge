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
  int minOperations(string s) { return min(helper(s, 0), helper(s, 1)); }
  int helper(string& s, int cur) {
    int alt = 0;
    for (auto ch : s) {
      if (ch != '0' + cur) {
        alt++;
      }
      cur = 1 - cur;
    }
    return alt;
  }
};
