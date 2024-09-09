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
  int minimumMountainRemovals(vector<int>& nums) {
    vector<int> temp;
    int prev = -1;
    for (auto v : nums) {
      if (v != prev) {
        temp.push_back(v);
      }
      prev = v;
    }
    int base = nums.size() - temp.size();
    swap(temp, nums);

    LOG(INFO) << nums;
    const int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n));
    int best = 0;
    for(int i=0; i+2<n; i++){
      if (nums[i+1] > nums[i] && nums[i+1] > nums[i+2]) {
        dp[i][i+2] = 3;
        best = 3;
      }
    }
    for(int i=0; i<n; i++){
      for(int len=4; len<n; len++){
        int j = i + len - 1;
        if (j >= n) continue;

        int local_best = 0;
        for(int k=j-1, stop=i+2; k>=stop;k--){
          if (dp[i][k] >= 3 && nums[k] > nums[j]) {
            local_best = max(local_best, dp[i][k] + 1);
          }
        }
        dp[i][j] = local_best;
        best = max(best, local_best);
      }
    }

    for(int i=0; i<n; i++){
      LOG(INFO) << dp[i];
    }
    return n - best + base;
  }
};
