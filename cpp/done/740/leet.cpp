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
  int deleteAndEarn(vector<int>& nums) {
    if (nums.empty()) return 0;
    map<int, int> cnt;
    for (auto v : nums) cnt[v] += 1;
    vector<int> vals;
    for (auto& [key, val] : cnt) {
      vals.push_back(key);
    }
    vector<int> dp(vals.size());
    dp[0] = vals[0] * cnt[vals[0]];
    for (int i = 1; i < dp.size(); i++) {
      if (vals[i] != vals[i - 1] + 1) {
        dp[i] = dp[i - 1] + vals[i] * cnt[vals[i]];
      } else {
        int prev2 = (i >= 2) ? dp[i - 2] : 0;
        int prev3 = (i >= 3) ? dp[i - 3] : 0;
        dp[i] = max(prev2 + vals[i] * cnt[vals[i]],
                    prev3 + vals[i - 1] * cnt[vals[i - 1]]);
        dp[i] = max(dp[i], dp[i - 1]);
      }
    }
    return dp.back();
  }
};
