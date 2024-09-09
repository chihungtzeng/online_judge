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

class Solution {
 public:
  int numDifferentIntegers(string word) {
    set<string> vals;
    string val = "";
    for (auto ch : word) {
      if (isdigit(ch)) {
        val += ch;
      } else {
        if (!val.empty()) {
          trim(val);
          vals.insert(val);
          val = "";
        }
      }
    }
    if (!val.empty()) {
      trim(val);
      vals.insert(val);
    }
    return vals.size();
  }
  void trim(string& s) {
    reverse(s.begin(), s.end());
    while (!s.empty() && s.back() == '0') {
      s.pop_back();
    }
  }
};
