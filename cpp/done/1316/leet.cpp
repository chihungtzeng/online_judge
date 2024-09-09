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
  int distinctEchoSubstrings(string text) {
    unordered_set<string_view> ans;
    const int n = text.size();
    const char* c_str = text.c_str();
    for (int i = 0; i < n; i++) {
      for (int len = 2; i + len - 1 < n; len += 2) {
        string_view wide(c_str + i, len);
        string_view left = wide.substr(0, len / 2);
        string_view right = wide.substr(len / 2, len / 2);
        if (left == right) ans.insert(wide);
      }
    }
    return ans.size();
  }
};
