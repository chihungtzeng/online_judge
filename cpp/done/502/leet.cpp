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

using ipair = pair<int, int>;
class Solution {
 public:
  int findMaximizedCapital(int k, int W, vector<int>& Profits,
                           vector<int>& Capital) {
    auto min_cap_cmp = [](const auto& a, const auto& b) {
      return a.first > b.first;
    };
    auto max_profit_cmp = [](const auto& a, const auto& b) {
      return a.second < b.second;
    };
    vector<ipair> ps;
    ps.reserve(Capital.size());
    for (int i = 0; i < Capital.size(); i++) {
      ps.emplace_back(ipair{Capital[i], Profits[i]});
    }
    priority_queue<ipair, vector<ipair>, decltype(min_cap_cmp)> min_pq(
        ps.begin(), ps.end(), min_cap_cmp);
    priority_queue<ipair, vector<ipair>, decltype(max_profit_cmp)> max_pq(

        max_profit_cmp);
    while (k--) {
      while (!min_pq.empty() && min_pq.top().first <= W) {
        max_pq.push(min_pq.top());
        min_pq.pop();
      }
      if (!max_pq.empty()) {
        auto proj = max_pq.top();
        max_pq.pop();
        W += proj.second;
      } else {
        break;
      }
    }
    return W;
  }
};
