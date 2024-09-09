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
  bool canConstruct(string ransomNote, string magazine) {
    vector<int> cnt(26);
    for (auto ch : ransomNote) {
      cnt[ch - 'a']++;
    }
    for (auto ch : magazine) {
      cnt[ch - 'a']--;
    }
    for (auto v : cnt) {
      if (v > 0) {
        return false;
      }
    }
    return true;
  }
};
