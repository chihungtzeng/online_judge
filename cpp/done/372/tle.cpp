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
  int superPow(int a, vector<int>& b) {
    int y = a % 1337;
    int ret = 1;
    while (!b.empty()) {
      int parity = b.back() & 1;
      if (parity) {
        ret = (ret * y) % 1337;
      }
      y = (y * y) % 1337;
      halve(b);
    }
    return ret;
  }
  void halve(vector<int>& b) {
    vector<int> tmp;
    tmp.reserve(b.size());
    int d0 = b[0] >> 1;
    if (d0) tmp.push_back(d0);
    int carry = b[0] & 1;
    for (int i = 1; i < b.size(); i++) {
      int n = (carry << 3) + (carry << 1) + b[i];
      carry = n & 1;
      tmp.push_back(n >> 1);
    }
    b = tmp;
  }
};
