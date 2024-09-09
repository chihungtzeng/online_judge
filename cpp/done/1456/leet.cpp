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
  const string vowels = "aeiou";
  int maxVowels(string s, int k) {
    int ret = 0, start = 0;
    while (start < k) {
      if (isvowel(s[start++])) ret++;
    }
    int cur = ret;
    for (int l = 1, r = k; r < s.size(); r++, l++) {
      if (isvowel(s[l - 1])) cur--;
      if (isvowel(s[r])) cur++;
      ret = max(ret, cur);
    }
    return ret;
  }
  bool isvowel(char c) {
    for (auto ch : vowels) {
      if (ch == c) return true;
    }
    return false;
  }
};
