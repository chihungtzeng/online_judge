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
  int findLength(vector<int>& A, vector<int>& B) {
    vector<vector<int>> dp(A.size(), vector<int>(B.size()));
    int ans = 0;
    dp[0][0] = (A[0] == B[0]) ? 1 : 0;
    for (int i = 1; i < B.size(); i++) {
      if (A[0] == B[i])
        dp[0][i] = 1;
      else
        dp[0][i] = 0;
    }
    for (int i = 1; i < A.size(); i++) {
      if (A[i] == B[0])
        dp[i][0] = 1;
      else
        dp[i][0] = 0;
    }
    ans = dp[0][B.size() - 1];
    ans = max(ans, dp[A.size()-1][0]);

    for (int i = 1; i < A.size(); i++) {
      for (int j = 1; j < B.size(); j++) {
        if (A[i] == B[j]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
          ans = max(ans, dp[i][j]);
        } else
          dp[i][j] = 0;
      }
    }
    return ans;
  }
};
