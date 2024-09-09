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
#define DEBUG 1

class Solution {
 public:
  int slen, tlen;
  int countSubstrings(string s, string t) {
    slen = s.size();
    tlen = t.size();
    int ans = 0;
    for (int i = 0; i < slen; i++) {
      ans += helper(s, t, i, 0);
    }
    for (int j = 1; j < tlen; j++) {
      ans += helper(s, t, 0, j);
    }
    return ans;
  }

  int helper(string& s, string& t, int i, int j) {
    int res = 0, prev = 0, cur = 0;
    for (; i < slen && j < tlen; i++, j++) {
      cur++;
      if (s[i] != t[j]) {
        prev = cur;
        cur = 0;
      }
      res += prev;
    }
    return res;
  }
};
