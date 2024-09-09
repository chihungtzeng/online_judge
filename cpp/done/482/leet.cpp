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
  string licenseKeyFormatting(string S, int K) {
    string chs;
    int diff = 'A' - 'a';
    for (auto ch : S) {
      if (ch == '-') continue;
      if ('a' <= ch && ch <= 'z') {
        ch += diff;
      }
      chs.push_back(ch);
    }
    const int n = chs.size();
    string ret;
    int pos = 0;
    if (n % K != 0) {
      ret += chs.substr(pos, n % K);
      ret.push_back('-');
      pos = n % K;
    }
    while (pos < n) {
      ret += chs.substr(pos, K);
      ret.push_back('-');
      pos += K;
    }
    if (!ret.empty()) {
      ret.pop_back();
    }

    return ret;
  }
};
