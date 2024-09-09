#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <map>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int calculate(string s) {
    vector<int64_t> stack, signs;
    int64_t num = 0, cur = 0, sign = 1;
    for (auto ch : s) {
      if (isdigit(ch)) {
        num = num * 10 + ch - '0';
      } else {
        cur += num * sign;
        num = 0;
        if (ch == '+') sign = 1;
        if (ch == '-') sign = -1;
        if (ch == '(') {
          stack.push_back(cur);
          signs.push_back(sign);
          cur = 0;
          sign = 1;
        }
        if (ch == ')' && !signs.empty()) {
          cur = cur * signs.back() + stack.back();
          signs.pop_back();
          stack.pop_back();
        }
      }
    }
    cur += sign * num;
    return cur;
  }
};

