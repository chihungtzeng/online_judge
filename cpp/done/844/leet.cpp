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
  bool backspaceCompare(string S, string T) {
    modify(S);
    modify(T);
    return S == T;
  }
  void modify(string& s) {
    int len = 0;
    for (int i = 0, n = s.size(); i < n; i++) {
      if (s[i] == '#') {
        if (len > 0) len--;
      } else {
        s[len++] = s[i];
      }
    }
    s.resize(len);
  }
};
