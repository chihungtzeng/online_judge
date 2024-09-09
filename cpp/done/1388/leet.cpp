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
  int maxSizeSlices(vector<int>& slices) {
    vector<int> s1{slices.begin(), slices.end() - 1};
    vector<int> s2{slices.begin() + 1, slices.end()};
    return max(helper(s1, slices.size() / 3), helper(s2, slices.size() / 3));
  }

  int helper(vector<int>& slices, int npick) {
    const int nelems = slices.size();
    vector<vector<int>> dp(nelems + 1, vector<int>(npick+1, 0));
    for(int i=1; i<=npick; i++){
      dp[1][i] = slices[0];
    }
    for(int i=2; i<=nelems; i++){
      for(int j=1; j<=npick; j++){
        dp[i][j] = max(dp[i-1][j], dp[i-2][j-1] + slices[i-1]);
      }
    }
    LOG(INFO) << "slices: " << slices << " npick: " << npick;
    for(int i=0; i<=nelems; i++){
      LOG(INFO) << dp[i];
    }
    return dp[nelems][npick];
  }
};
