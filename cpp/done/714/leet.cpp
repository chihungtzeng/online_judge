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
  int maxProfit(vector<int>& prices, int fee) {
    vector<int> dp(prices.size());
    dp[0] = 0;
    int best_j = -prices[0];
    for (int i = 1; i < prices.size(); i++) {
      dp[i] = max(dp[i - 1], prices[i] - fee + best_j);
      best_j = max(best_j, dp[i - 1] - prices[i]);
    }
    return dp.back();
  }
};
