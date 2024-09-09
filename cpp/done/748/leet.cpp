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
  string shortestCompletingWord(string licensePlate, vector<string>& words) {
    auto lcnt = count(licensePlate);
    int idx = -1;
    for (int i = 0; i < words.size(); i++) {
      auto wcnt = count(words[i]);
      bool complete = true;
      for (int j = 0; j < 26 && complete; j++) {
        if (lcnt[j] > wcnt[j]) complete = false;
      }
      if (complete) {
        if (idx < 0)
          idx = i;
        else if (words[i].size() < words[idx].size())
          idx = i;
      }
    }
    return words[idx];
  }
  vector<int> count(string& s) {
    vector<int> cnt(26);
    for (auto ch : s) {
      if ('A' <= ch && ch <= 'Z')
        cnt[ch - 'A']++;
      else if ('a' <= ch && ch <= 'z')
        cnt[ch - 'a']++;
    }
    return cnt;
  }
};
