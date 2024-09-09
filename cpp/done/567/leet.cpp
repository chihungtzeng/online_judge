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
  bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;
    vector<short> cnt(26, 0);
    for (auto ch : s1) {
      cnt[ch - 'a'] += 1;
    }
    for (int i = 0; i < s1.size(); i++) {
      cnt[s2[i] - 'a'] -= 1;
    }
    if (satisfy(cnt)) return true;
    for (int i = 0, j = s1.size(); j < s2.size(); j++, i++) {
      cnt[s2[i] - 'a'] += 1;
      cnt[s2[j] - 'a'] -= 1;
      if (satisfy(cnt)) return true;
    }
    return false;
  }
  bool satisfy(vector<short>& cnt) {
    for (int i = 0; i < 26; i++) {
      if (cnt[i] != 0) return false;
    }
    return true;
  }
};
