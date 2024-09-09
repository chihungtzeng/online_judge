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

const int base = 1e9 + 7;
class Solution {
 public:
  int countHomogenous(string s) {
    uint64_t rep = 0, ans = 0;
    char prev_ch = 0;
    for (auto ch : s) {
      if (ch != prev_ch) {
        ans += ((rep * (rep + 1)) >> 1);
        rep = 1;
        prev_ch = ch;
      } else {
        rep++;
      }
    }
    ans += ((rep * (rep + 1)) >> 1);
    return ans % base;
  }
};
