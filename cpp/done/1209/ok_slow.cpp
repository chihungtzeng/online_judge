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

using cipair = pair<char, int>;
class Solution {
 public:
  string removeDuplicates(string s, int k) {
    const int n = s.size();
    vector<cipair> stack;
    for (int i = 0; i < n; i++) {
      if (stack.empty()) {
        stack.emplace_back(s[i], 1);
      } else if (stack.back().first == s[i]) {
        stack.emplace_back(s[i], stack.back().second + 1);
      } else {
        stack.emplace_back(s[i], 1);
      }

      if (!stack.empty() && stack.back().second == k) {
        while (!stack.empty() && stack.back().first == s[i]) stack.pop_back();
      }
    }

    string t;
    for (auto& [ch, freq] : stack) {
      t.push_back(ch);
    }
    return t;
  }
};
