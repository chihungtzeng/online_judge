#include <algorithm>
#include <cstdint>
#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int no_trans_limit(vector<int>& prices) {
    int profit = 0;
    for(size_t i=1; i<prices.size(); i++)
    {
      if (prices[i] > prices[i-1]) {
        profit += prices[i] - prices[i-1];
      }
    }
    return profit;
  }
  int maxProfit(int k, vector<int> &prices) {
    auto nprices = static_cast<int>(prices.size());
    if (nprices <= 1) {
      return 0;
    }
    if (k >= nprices / 2)
    {
      return no_trans_limit(prices);
    }
    vector<vector<int>> mp(k + 1);
    for (int i = 0; i <= k; i++) {
      mp[i].resize(nprices);
    }
    auto lm = 0;
    for (int kth = 1; kth <= k; kth++) {
      lm = -prices[0];
      for (int i = 1; i < nprices; i++) {
        mp[kth][i] = max(mp[kth][i - 1], lm + prices[i]);
        if (kth >= 1)
        {
          lm = max(lm, mp[kth - 1][i - 1] - prices[i]);
        }
      }
    }
    return mp[k][nprices - 1];
  }
};
