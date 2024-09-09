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
  string maximumBinaryString(string s) {
    const int n = s.size();
    int l1 = 0, n0 = 0, t1 = 0;
    bool see0 = false;
    for (auto ch : s) {
      if (ch == '0') {
        see0 = true;
        n0++;
      } else if (see0) {
        t1++;
      } else {
        l1++;
      }
    }
    for (int i = l1 + n0 - 2; i >= 0; i--) {
      s[i] = '1';
    }
    s[l1 + n0 - 1] = (n0 == 0)? '1' : '0';
    
    for (int i = l1 + n0; i < n; i++) {
      s[i] = '1';
    }
    return s;
  }
};
