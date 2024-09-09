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
  string findLexSmallestString(string s, int a, int b) {
    unordered_set<string> seen;
    for (int i = 0; i < s.size(); i++) {
      s[i] = s[i] - '0';
    }
    seen.insert(s);
    deque<string> q;
    q.push_back(s);
    while (!q.empty()) {
      string cur = q.front();
      q.pop_front();

      string next = add(cur, a);
      if (seen.find(next) == seen.end()) {
        seen.insert(next);
        q.emplace_back(next);
      }

      next = shift(cur, b);
      while (seen.find(next) == seen.end()) {
        seen.insert(next);
        q.push_back(next);
        next = shift(next, b);
      }
    }
    string ans;
    for (int i = 0; i < s.size(); i++) {
      ans.push_back(9);
    }
    for (auto& s : seen) {
      if (s < ans) ans = s;
    }
    for (int i = 0; i < ans.size(); i++) {
      ans[i] += '0';
    }
    return ans;
  }
  string add(string& s, int a) {
    string t = s;
    for (int i = 1; i < s.size(); i += 2) {
      t[i] = (s[i] + a) % 10;
    }
    return t;
  }
  string shift(string& s, int b) {
    string suffix = s.substr(b);
    string prefix = s.substr(0, b);
    return suffix + prefix;
  }
};
