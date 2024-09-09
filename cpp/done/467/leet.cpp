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
  int findSubstringInWraproundString(string p) {
    if (p.empty()) return 0;
    vector<int> dp(26);
    int ell = 1;
    dp[p[0] - 'a'] = 1;
    for (int i = 1; i < p.size(); i++) {
      int idx = p[i] - 'a';
      if ((p[i - 1] + 1 - 'a') % 26 == idx) {
        ell++;
      } else {
        ell = 1;
      }
      dp[idx] = max(dp[idx], ell);
    }
    return accumulate(dp.begin(), dp.end(), 0);
  }
};
