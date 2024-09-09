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
  int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    const int n = nums1.size();
    const int m = nums2.size();
    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = nums1[0] * nums2[0];
    for (int i = 1; i < n; i++) {
      dp[i][0] = max(dp[i - 1][0], nums1[i] * nums2[0]);
    }
    for (int i = 1; i < m; i++) {
      dp[0][i] = max(dp[0][i - 1], nums1[0] * nums2[i]);
    }
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        const int temp = nums1[i] * nums2[j];
        dp[i][j] = max(dp[i - 1][j - 1] + temp, dp[i - 1][j]);
        dp[i][j] = max(dp[i][j], dp[i][j - 1]);
        dp[i][j] = max(dp[i][j], temp);
      }
    }
    return dp[n - 1][m - 1];
  }
};
