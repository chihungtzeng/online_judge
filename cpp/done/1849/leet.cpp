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

constexpr int64_t bound = 1e11;
class Solution {
 public:
  bool splitString(string s) {
    int64_t cur = 0;
    for (int i = 0; i < s.size(); i++) {
      cur = cur * 10 + s[i] - '0';
      if (cur > bound) {
        break;
      }
      if (helper(s, i + 1, cur - 1, 1)) {
        return true;
      }
    }
    return false;
  }
  bool helper(string &s, const int idx, const int64_t next_val,
              const int nsplit) {
    if (idx == s.size()) {
      return bool(nsplit > 1);
    }
    if (next_val == 0) {
      for (int i = idx; i < s.size(); i++) {
        if (s[i] != '0') return false;
      }
      return true;
    }
    int64_t val = 0;
    for (int i = idx; i < s.size() && val <= next_val; i++) {
      val = val * 10 + s[i] - '0';
      if (val == next_val) {
        return helper(s, i + 1, val - 1, nsplit + 1);
      }
    }
    return false;
  }
};
