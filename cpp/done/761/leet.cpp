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

bool cmp(const string& s1, const string& s2) { return s1 + s2 > s2 + s1; }

class Solution {
 public:
  string makeLargestSpecial(string s) {
    if (s.size() <= 2) return s;
    int balance = 0, start = 0;
    vector<string> subs;
    for (int i = 0; i < s.size(); i++) {
      balance += (s[i] - '0' == 0) ? -1 : 1;
      if (balance == 0) {
        subs.emplace_back(s.substr(start, i - start + 1));
        start = i + 1;
      }
    }
    for (int i = 0; i < subs.size(); i++) {
      subs[i] =
          '1' + makeLargestSpecial(subs[i].substr(1, subs[i].size() - 2)) + '0';
    }
    sort(subs.begin(), subs.end(), cmp);
    string ret = subs[0];
    for (int i = 1; i < subs.size(); i++) {
      ret += subs[i];
    }
    return ret;
  }
};
