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
  int minTaps(int n, vector<int>& ranges) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i <= n; i++) {
      int left = max(0, i - ranges[i]);
      int right = min(n, i + ranges[i]);
      for (int j = left; j <= right; j++) {
        if (dp[left] != INT_MAX) {
          dp[j] = min(dp[j], dp[left] + 1);
        }
      }
    }
    if (dp[n] == INT_MAX) return -1;
    return dp[n];
  }
};
