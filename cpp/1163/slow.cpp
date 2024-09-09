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
  string lastSubstring(string s) {
    string stack;
    string ans = "";
    const int n = s.size();
    for (int i = 0; i < n; i++) {
      auto ch = s[i];
      if (stack.empty()) {
        stack.push_back(ch);
        continue;
      }
      if (ch > stack[0]) {
        if (stack > ans) {
          ans = stack;
        }
        stack = ch;
      } else if (ch == stack[0]) {
        string can = s.substr(i, stack.size());
        if (can > stack) {
          stack = ch;
        } else {
          stack.push_back(ch);
        }
      } else {
        stack.push_back(ch);
      }
    }
    if (stack > ans) {
      ans = stack;
    }
    return ans;
  }
};
