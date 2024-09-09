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
  bool checkRecord(string s) {
    int na = 0;
    int l3 = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'A') na++;
      if (s[i] == 'L' && i < s.size() - 2 && s[i + 1] == 'L' &&
          s[i + 2] == 'L') {
        l3++;
      }
    }
    return bool(na <= 1 && l3 == 0);
  }
};
