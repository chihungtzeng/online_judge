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
  string evaluate(string s, vector<vector<string>>& knowledge) {
    unordered_map<string, string> kmap;
    for (auto& item : knowledge) {
      kmap[item[0]] = item[1];
    }
    vector<char> stack;
    stack.reserve(s.size());
    string ans;
    for (auto ch : s) {
      if (ch == '(') {
        stack.push_back(ch);
      } else if (ch == ')') {
        string key{stack.begin() + 1, stack.end()};
        auto it = kmap.find(key);
        if (it == kmap.end()) {
          ans.push_back('?');
        } else {
          ans += it->second;
        }
        stack.clear();
      } else if (stack.empty()) {
        ans.push_back(ch);
      } else {
        stack.push_back(ch);
      }
    }
    return ans;
  }
};
