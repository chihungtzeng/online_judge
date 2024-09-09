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
    vector<int> pmod10(11, 1);
    a = a % 1337;
    for (int i = 1; i <= 10; i++) {
      pmod10[i] = (pmod10[i - 1] * a) % 1337;
    }
    return helper(a, b, pmod10);
  }
  int helper(int a, vector<int>& b, vector<int>& pmod10) {
    if (b.empty()) return 1;
    int last = b.back();
    b.pop_back();
    int ret = helper(a, b, pmod10);
    return (x10mod1337(ret) * pmod10[last]) % 1337;
  }
  int x10mod1337(int x) {
    int y2 = (x * x) % 1337;
    int y4 = (y2 * y2) % 1337;
    int y8 = (y4 * y4) % 1337;
    return (y2 * y8) % 1337;
  }
};
