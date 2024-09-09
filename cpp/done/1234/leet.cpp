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
  const vector<char> chs_{'Q', 'W', 'E', 'R'};
  int balancedString(string s) {
    vector<int> cnt(128);
    int n = s.size();
    int n_4 = n >> 2;
    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {
      cnt[s[i]]++;
    }
    int start = 0, end = 0;
    for (; end < n; end++) {
      cnt[s[end]]--;
      while (start < n && satisfy(cnt, n_4)) {
        ans = min(ans, end - start + 1);
        cnt[s[start]]++;
        start++;
      }
    }
    return ans;
  }
  bool satisfy(vector<int>& cnt, const int n_4) {
    for (auto ch : chs_) {
      if (cnt[ch] > n_4) return false;
    }
    return true;
  }
};
