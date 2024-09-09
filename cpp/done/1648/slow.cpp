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
#define DEBUG 0

constexpr int base = 1e9 + 7;
class Solution {
 public:
  int maxProfit(vector<int>& inventory, int orders) {
    priority_queue<int> pq(inventory.begin(), inventory.end());
    int64_t ans = 0;
    while (orders > 0 && !pq.empty()) {
      int most = pq.top();
      pq.pop();
      int second_most = 0;
      if (!pq.empty()) {
        second_most = pq.top();
      }
      int64_t amount = 1;
      if (most != second_most) {
        amount = min(orders, most - second_most + 1);
      }
#if DEBUG
      LOG(INFO) << "orders: " << orders << " amount: " << amount;
      vector<int> bak;
      while(!pq.empty()){
        bak.push_back(pq.top());
        pq.pop();
      }
      LOG(INFO) << "inventory: " << bak;
      while(!bak.empty()){
        pq.push(bak.back());
        bak.pop_back();
      }
#endif
      ans += amount * (2 * static_cast<int64_t>(most) - amount + 1) / 2;
      ans %= base;
      pq.push(most - amount);
      orders -= amount;
    }
    return ans;
  }
};
