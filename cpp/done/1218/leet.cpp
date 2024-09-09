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
  int longestSubsequence(vector<int>& arr, int difference) {
    vector<int> dp(arr.size());
    int ans = 0;
    unordered_map<int, int> index_of;

    for (int i = 0, n = arr.size(); i < n; i++) {
      auto it = index_of.find(arr[i] - difference);
      if (it == index_of.end()) {
        dp[i] = 1;
      } else {
        dp[i] = dp[it->second] + 1;
      }
      index_of[arr[i]] = i;
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};
