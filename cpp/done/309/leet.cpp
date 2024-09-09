#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    auto nprices = prices.size();
    if (nprices == 0) {
      return 0;
    }
    vector<int> profits(nprices);
    vector<int> pdiff(nprices);
    profits[0] = 0;
    pdiff[0] = -prices[0];
    if (nprices >= 2) {
      profits[1] = max(0, prices[1] - prices[0]);
      pdiff[1] = max(pdiff[0], -prices[1]);
    }
    if (nprices >= 3) {
      profits[2] = max(profits[1], prices[2] - prices[0]);
      profits[2] = max(profits[2], prices[2] - prices[1]);
      pdiff[2] = max(pdiff[1], -prices[2]);
    }
    for (auto i = 3; i < nprices; i++) {
      pdiff[i] = max(pdiff[i-1], profits[i-3] - prices[i-1]);
      profits[i] = max(profits[i-1], prices[i] + pdiff[i]);
    }
    return profits.back();
  }
};
