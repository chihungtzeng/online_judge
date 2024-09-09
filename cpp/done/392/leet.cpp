#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isSubsequence(string s, string t) {
    size_t i = 0, j = 0;
    while (j < t.size() && i < s.size()) {
      if (s[i] == t[j]) {
        i++;
      }
      j++;
    }
    return bool(i == s.size());
  }
};
