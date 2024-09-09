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
  vector<string> letterCasePermutation(string s) {
    vector<int> pos;
    for (int i = 0; i < s.size(); i++) {
      if (isalpha(s[i])) pos.push_back(i);
    }
    if (pos.empty()) return vector<string>{s};
    int bound = 1 << pos.size();
    vector<string> ans(bound);
    for (int i = 0; i < bound; i++) {
      for (int j = 0; j < pos.size(); j++) {
        if ((i & (1 << j)) == 0)
          s[pos[j]] = lower(s[pos[j]]);
        else
          s[pos[j]] = upper(s[pos[j]]);
      }
      ans[i] = s;
    }
    return ans;
  }
  bool isalpha(char c) {
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
  }
  char upper(char c) {
    if ('a' <= c && c <= 'z') return c - 'a' + 'A';
    return c;
  }
  char lower(char c) {
    if ('A' <= c && c <= 'Z') return c - 'A' + 'a';
    return c;
  }
};
