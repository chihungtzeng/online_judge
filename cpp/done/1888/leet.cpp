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
  int minFlips(string s) {
    const int n = s.size();
    for (int i = 0; i < n; i++) {
      s[i] = s[i] - '0';
    }
    s += s;
    const int dn = n * 2;
    string s1(dn, 0), s2(dn, 0);
    for (int i = 0; i < dn; i++) {
      s1[i] = i & 1;
      s2[i] = 1 - s1[i];
    }
    int ans1 = 0, ans2 = 0, ans = INT_MAX;
    const int n_1 = n - 1;
    for (int i = 0; i < dn; i++) {
      if (s[i] != s1[i]) ans1++;
      if (s[i] != s2[i]) ans2++;

      if (i >= n) {
        const int idx = i - n;
        if (s[idx] != s1[idx]) ans1--;
        if (s[idx] != s2[idx]) ans2--;
      }

      if (i >= n_1) {
        ans = min(ans, ans1);
        ans = min(ans, ans2);
      }
    }

    return ans;
  }
};
