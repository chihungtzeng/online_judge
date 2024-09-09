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
  bool canConvertString(string s, string t, int k) {
    if (s.size() != t.size()) return false;
    int n = s.size();
    vector<int> nshift(26);
    for (int i = 0; i < n; i++) {
      int diff = (t[i] - s[i] + 26) % 26;
      nshift[diff]++;
    }
    int res = 0;
    for (int i = 1; i < 26; i++) {
      int min_steps = 0;
      if (nshift[i] > 0) {
        min_steps = i + (nshift[i] - 1) * 26;
      }
      res = max(res, min_steps);
    }
    return bool(res <= k);
  }
};
