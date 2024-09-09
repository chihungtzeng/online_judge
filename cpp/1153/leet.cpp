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
  bool canConvert(string s1, string s2) {
    if (s1 == s2) return true;
    vector<char> tr(26, 0);
    for (int i = 0, n = s1.size(); i < n; i++) {
      int idx = s1[i] - 'a';
      if (tr[idx] > 0 && s2[i] != tr[idx]) return false;

      tr[idx] = s2[i];
    }
    set<char> s;
    for (int i = 0; i < 26; i++) {
      if (tr[i]) s.insert(tr[i]);
    }
    return s.size() < 26;
  }
};
