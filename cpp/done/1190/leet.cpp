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
  string reverseParentheses(string s) {
    vector<int> stack;
    for (int i = 0, n = s.size(); i < n; i++) {
      if (s[i] == '(') {
        stack.push_back(i);
      } else if (s[i] == ')') {
        reverse(s, stack.back() + 1, i - 1);
        stack.pop_back();
      }
    }
    string ans;
    for (auto ch : s) {
      if (ch != ')' && ch != '(') {
        ans.push_back(ch);
      }
    }
    return ans;
  }
  void reverse(string& s, int f, int t) {
    while (f < t) {
      swap(s[f++], s[t--]);
    }
  }
};
