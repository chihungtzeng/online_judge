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
  string maxValue(string n, int x) {
    bool neg = bool(n[0] == '-');
    const int len = n.size();
    int pos = 0;
    char ch = x + '0';
    if (neg) {
      pos = 1;
      while (pos < len && (n[pos] <= ch)) {
        pos++;
      }
    } else {
      while (pos < len && (n[pos] >= ch)) {
        pos++;
      }
    }
    return n.substr(0, pos) + ch + n.substr(pos);
  }
};
