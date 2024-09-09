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

using ipair = pair<int, int>;
class Solution {
 public:
  int eatenApples(vector<int>& apples, vector<int>& days) {
    const int n = apples.size();
    priority_queue<ipair, vector<ipair>, greater<>> pq;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (apples[i] > 0) {
        pq.push({i + days[i] - 1, apples[i]});
      }
      while (!pq.empty() && pq.top().first < i) {
        pq.pop();
      }
      if (!pq.empty()) {
        auto [expire, amount] = pq.top();
        pq.pop();
        //        LOG(INFO) << "eat apple at day " << i;
        ans++;
        if (amount > 1) {
          pq.push({expire, amount - 1});
        }
      }
    }
    int cur_day = n;
    while (!pq.empty()) {
      auto [expire, amount] = pq.top();
      if (expire >= cur_day) {
        int consume = min(expire - cur_day + 1, amount);
        //        LOG(INFO) << "eat apples from day " << cur_day << " to day "
        //        << cur_day + consume;
        ans += consume;
        cur_day += consume;
      }
      pq.pop();
    }
    return ans;
  }
};
