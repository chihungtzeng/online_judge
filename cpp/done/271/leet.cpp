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

class Codec {
 public:
  // Encodes a list of strings to a single string.
  string encode(vector<string>& strs) {
    string ret;
    for (auto& s : strs) {
      int len = s.size();
      ret += to_string(len) + ',' + s;
    }
    return ret;
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(string s) {
    vector<string> ret;
    int pos = 0;
    string slen;
    while (pos < s.size()) {
      while (s[pos] != ',') {
        slen.push_back(s[pos]);
        pos++;
      }
      int len = stoi(slen);
      ret.emplace_back(s.substr(pos + 1, len));
      pos = pos + 1 + len;
      slen = "";
    }
    return ret;
  }
};

