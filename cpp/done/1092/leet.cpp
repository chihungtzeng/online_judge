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
  string shortestCommonSupersequence(string str1, string str2) {
    const int n1 = str1.size(), n2 = str2.size();
    vector<vector<int>> dp(n2 + 1, vector<int>(n1 + 1, 0));
    for (int i = 1; i <= n2; i++) {
      for (int j = 1; j <= n1; j++) {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        if (str2[i - 1] == str1[j - 1]) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
      }
    }
#if 0
    for(auto& arr: dp){
      LOG(INFO) << arr;
    }
#endif
    string ans;
    int j = n1;
    int i = n2;
    while (i > 0 && j > 0) {
      if (str1[j-1] == str2[i-1] && dp[i][j] == dp[i - 1][j - 1] + 1) {
        ans.push_back(str1[j-1]);
        j--;
        i--;
      } else if (dp[i][j] == dp[i - 1][j]) {
        ans.push_back(str2[i-1]);
        i--;
      } else {
        ans.push_back(str1[j-1]);
        j--;
      }
    }
    while (i > 0) {
      ans.push_back(str2[i-1]);
      i--;
    }
    while (j > 0) {
      ans.push_back(str1[j-1]);
      j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
