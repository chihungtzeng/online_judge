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
  string minRemoveToMakeValid(string s) {
    string t1;
    int balance = 0;
    for (auto ch : s) {
      if (ch == '(') {
        balance++;
        t1.push_back(ch);
      } else if (ch == ')') {
        balance--;
        if (balance >= 0) {
          t1.push_back(ch);
        } else {
          balance = 0;
        }
      } else {
        t1.push_back(ch);
      }
    }
    vector<char> stack;
    stack.reserve(t1.size());
    balance = 0;
    for (int i = t1.size() - 1; i >= 0; i--) {
      char ch = t1[i];
      if (ch == ')') {
        balance++;
        stack.push_back(ch);
      } else if (ch == '(') {
        balance--;
        if (balance >= 0) {
          stack.push_back(ch);
        } else {
          balance = 0;
        }
      } else {
        stack.push_back(ch);
      }
    }
    string ans;
    while (!stack.empty()) {
      ans.push_back(stack.back());
      stack.pop_back();
    }
    return ans;
  }
};
