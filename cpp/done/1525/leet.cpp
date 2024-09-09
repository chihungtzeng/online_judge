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
  int numSplits(string s) {
    int lhs = 0, prev_lhs = 0, rhs = 0, prev_rhs = 0;
    vector<int> lbits(s.size()), rbits(s.size());
    lhs = 1 << (s[0] - 'a');
    lbits[0] = 1;
    for (int i = 1; i < s.size(); i++) {
      prev_lhs = lhs;
      lhs = lhs | (1 << (s[i] - 'a'));
      if (lhs != prev_lhs) {
        lbits[i] = lbits[i - 1] + 1;
      } else {
        lbits[i] = lbits[i - 1];
      }
    }
    for (int i = s.size() - 2; i >= 0; i--) {
      prev_rhs = rhs;
      rhs = rhs | (1 << (s[i + 1] - 'a'));
      if (rhs != prev_rhs) {
        rbits[i] = rbits[i + 1] + 1;
      } else {
        rbits[i] = rbits[i + 1];
      }
    }
    int ret = 0;
    for (int i = s.size() - 2; i >= 0; i--) {
      if (lbits[i] == rbits[i]) ret++;
    }
    return ret;
  }
};
