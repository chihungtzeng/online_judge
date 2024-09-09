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
  string largestOddNumber(string num) {
    int pos = num.size() - 1;
    while (pos >= 0) {
      int digit = num[pos] - '0';
      if (digit > 0 && 1 == (digit & 1)) {
        break;
      } else {
        pos--;
      }
    }
    return num.substr(0, pos + 1);
  }
};
