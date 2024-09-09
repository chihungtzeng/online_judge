#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
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

#define DEBUG 0

class Solution {
 public:
  bool wordPatternMatch(string pat, string s) {
    if (pat.size() > s.size()) return false;
    vector<string> mapping(128);
    unordered_map<string, char> mvals;
    return helper(pat, s, mapping, mvals, 0, 0);
  }
  bool helper(string& pat, string& s, vector<string>& mapping,
              unordered_map<string, char>& mvals, int pati, int si) {
    if (pati == pat.size()) {
#if DEBUG
      for (auto& [m, ch] : mvals) {
        LOG(INFO) << ch << " : " << m;
      }
#endif
      if (si == s.size())
        return true;
      else
        return false;
    }
    char ch = pat[pati];
    if (!mapping[ch].empty()) {
      string sv = s.substr(si, mapping[ch].size());
      if (sv != mapping[ch]) return false;
      return helper(pat, s, mapping, mvals, pati + 1, si + mapping[ch].size());
    }
    string m;
    for (int i = si; i < s.size(); i++) {
      m += s[i];
      auto mit = mvals.find(m);
      if (mit != mvals.end()) {
        if (mit->second == ch) {
          return helper(pat, s, mapping, mvals, pati + 1,
                        si + mapping[ch].size());
        } else {
          continue;
        }
      }

      if (mit == mvals.end()) {
        mvals[m] = ch;
        mapping[ch] = m;
        if (helper(pat, s, mapping, mvals, pati + 1, i + 1)) {
          return true;
        }
        mvals.erase(m);
        mapping[ch] = "";
      }
    }
    return false;
  }

  bool check(string& pat, string& s, vector<string>& mapping) {
    for (auto ch : pat) {
      if (mapping[ch].empty()) {
#if DEBUG
        LOG(INFO) << ch << " maps to empty string";
#endif
        return false;
      }
    }
#if DEBUG
    for (auto ch : pat) {
      LOG(INFO) << ch << " : " << mapping[ch];
    }
#endif
    string comp;
    for (auto ch : pat) {
      comp += mapping[ch];
    }
    return comp == s;
  }
};
