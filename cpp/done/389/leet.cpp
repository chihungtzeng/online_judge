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
  char findTheDifference(string s, string t) {
    vector<int> cnt(26);
    for (size_t i = 0; i < s.size(); i++) {
      cnt[s[i] - 'a'] -= 1;
      cnt[t[i] - 'a'] += 1;
    }
    cnt[t.back() - 'a'] += 1;
    for (size_t i = 0; i < 26; i++) {
      if (cnt[i] > 0) {
        return i + 'a';
      }
    }
    return 'a';
  }
};
