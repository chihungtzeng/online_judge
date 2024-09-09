#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
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
  string findLongestWord(string s, vector<string>& d) {
    if (d.empty()) return "";
    string ret;
    for (auto& w : d) {
      int i = 0, j = 0;
      while (i < s.size() && j < w.size()) {
        if (s[i] == w[j]) {
          i++;
          j++;
        } else {
          i++;
        }
      }
      if (j == w.size()) {
        if (w.size() > ret.size() || (w.size() == ret.size() && w < ret)) {
          ret = w;
        }
      }
    }
    return ret;
  }
};
