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
  int minOperationsMaxProfit(vector<int>& customers, int bcost, int rcost) {
    int ans = -1;
    int profit = 0;
    int best = 0;
    const int n = customers.size();
    int nwait = 0;
    int rot = 0;
    for (int i = 0; i < n; i++) {
      rot++;
      if (customers[i] + nwait >= 4) {
        nwait = customers[i] + nwait - 4;
        profit += 4 * bcost - rcost;
      } else {
        profit += (customers[i] + nwait) * bcost - rcost;
        nwait = 0;
      }

      if (profit > best) {
        best = profit;
        ans = rot;
      }
    }
    while (nwait > 0){
      rot++;
      int np = min(nwait, 4);
      profit += np * bcost - rcost;
      nwait -= np;

      if (profit > best) {
        best = profit;
        ans = rot;
      }

    }
    return ans;
  }
};
