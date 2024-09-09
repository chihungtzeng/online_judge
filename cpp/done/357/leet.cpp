#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int countNumbersWithUniqueDigits(int n) {
    vector<int> cnt(11);
    cnt[0] = 1;
    cnt[1] = 10;
    cnt[2] = 91;
    int cur = 9 * 9;
    for (size_t i = 3; i < 11; i++) {
      cur = cur * (11 - i);
      cnt[i] = cnt[i - 1] + cur;
    }
    if (n >= 10) {
      return cnt[10];
    } else {
      return cnt[n];
    }
  }
};
