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
  string shortestPalindrome(string s) {
    string rs = s;
    reverse(rs.begin(), rs.end());
    string t = s + '#' + rs;
    int slen = lcs(t);
    return rs.substr(0, rs.size() - slen) + s;
  }
  int lcs(string& t) {
    int lps[t.size()];
    lps[0] = 0;
    int k = 0;
    for (int i = 1; i < t.size(); i++) {
      while (k > 0 && t[k] != t[i]) {
        k = lps[k - 1];
      }
      if (t[k] == t[i]) {
        k++;
      }
      lps[i] = k;
    }
    return lps[t.size() - 1];
  }
};
