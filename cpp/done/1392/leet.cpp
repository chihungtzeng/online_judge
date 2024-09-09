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
  string longestPrefix(string s) {
    auto lps = lps_of(s);
    return s.substr(0, lps.back());
  }

  vector<int> lps_of(string& s) {
    vector<int> lps(s.size());
    int k = 0;
    const int n = s.size();
    for (int i = 1; i < n; i++) {
      while (k > 0 && s[k] != s[i]) {
        k = lps[k - 1];
      }
      if (s[k] == s[i]) {
        k++;
      }
      lps[i] = k;
    }
    return lps;
  }
};
