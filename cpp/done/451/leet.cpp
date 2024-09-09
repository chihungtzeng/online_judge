#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  string frequencySort(string s) {
    if (s.empty()) {
      return s;
    }
    map<char, int> cnt;
    for (auto ch : s) {
      if (cnt.find(ch) == cnt.end()) {
        cnt[ch] = 1;
      } else {
        cnt[ch] += 1;
      }
    }
    vector<pair<char, int>> vcnt(cnt.size());
    for (auto &[ch, val] : cnt) {
      vcnt.emplace_back(pair<char, int>{ch, val});
    }
    auto cmp = [](const auto &a, const auto &b) { return a.second > b.second; };
    sort(vcnt.begin(), vcnt.end(), cmp);
    string ret;
    ret.reserve(s.size());
    for (const auto &v : vcnt) {
      ret.append(string(v.second, v.first));
    }
    return ret;
  }
};
