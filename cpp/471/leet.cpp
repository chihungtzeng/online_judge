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
  string encode(string s) {
    const int n = s.size();
    vector<vector<string>> dp(n, vector<string>(n));
    for (int ell = 1; ell <= n; ell++) {
      for (int start = 0; start + ell - 1 < n; start++) {
        int end = start + ell - 1;

        dp[start][end] = cmpr(s.substr(start, ell));
        for (int i = start; i < end; i++) {
          string left = dp[start][i];
          string right = dp[i + 1][end];
          string candidate = cmpr(left + right);
          if (candidate.size() < dp[start][end].size()) {
            dp[start][end] = candidate;
          }
        }
      }
    }
    return dp[0][n - 1];
  }
  string cmpr2(string s) {
    string s2 = s + s;
    auto pos = s2.find(s, 1);
    if (pos >= s.size()) return s;
    int nrepeat = s.size() / pos;
    string candidate = to_string(nrepeat) + '[' + s.substr(0, pos) + ']';
    if (candidate.size() < s.size())
      return candidate;
    else
      return s;
  }

  string cmpr(string s) {
    vector<int> lps(s.size());
    int n = s.size();
    int k = 0;
    for (int i = 1; i < n; i++) {
      while (k > 0 && s[i] != s[k]) {
        k = lps[k - 1];
      }
      if (s[i] == s[k]) {
        k++;
      }
      lps[i] = k;
    }
    int period = n - lps[n - 1];
    if (n % period == 0 && n / period > 1) {
      string candidate =
          to_string(n / period) + '[' + s.substr(0, period) + ']';
      if (candidate.size() < n)
        return candidate;
      else
        return s;
    } else {
      return s;
    }
  }
};
