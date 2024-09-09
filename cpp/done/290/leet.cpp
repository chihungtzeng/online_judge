#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  bool wordPattern(string pattern, string str) {
    unordered_map<char, string> map;
    unordered_map<string, char> rmap;

    auto vals = split(str);
    if (vals.size() != pattern.size()) {
      return false;
    }
    for (size_t i = 0, bound = pattern.size(); i < bound; i++) {
      auto key = pattern[i];
      auto val = vals[i];

      auto mkey = map.find(key);
      auto mval = rmap.find(val);

      if (mkey == map.end() && mval == rmap.end()) {
        map[key] = val;
        rmap[val] = key;
      } else if (mkey == map.end() || mval == rmap.end()) {
        return false;
      } else if (mkey->second != val || mval->second != key) {
        return false;
      }
    }
    return true;
  }
  vector<string> split(string& s) {
    string tok;
    vector<string> ret;
    for (auto ch : s) {
      if ((ch == ' ') && (!tok.empty())) {
        ret.emplace_back(tok);
        tok = "";
      } else if (ch != ' ') {
        tok += ch;
      }
    }
    if (!tok.empty()) {
      ret.emplace_back(tok);
    }
    return ret;
  }
};
