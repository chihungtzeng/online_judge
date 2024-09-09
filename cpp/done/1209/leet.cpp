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
  string removeDuplicates(string s, int k) {
    const int n = s.size();
    vector<int> stack;
    for (int i = 0; i < n; i++) {
      if (stack.empty()) {
        stack.emplace_back((s[i] << 16) | 1);
      } else if ((stack.back() >> 16) == s[i]) {
        stack.emplace_back((s[i] << 16) | ((stack.back() & 0xffff) + 1));
      } else {
        stack.emplace_back((s[i] << 16) | 1);
      }

      if (!stack.empty() && (stack.back() & 0xffff) == k) {
        while (!stack.empty() && ((stack.back() >> 16) == s[i]))
          stack.pop_back();
      }
    }

    string t;
    for (auto val : stack) {
      t.push_back(val >> 16);
    }
    return t;
  }
};

