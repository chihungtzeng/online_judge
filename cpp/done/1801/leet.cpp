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

constexpr int base = 1e9 + 7;
constexpr int buy = 0;
constexpr int sell = 1;
using ipair = pair<int, int>;
class Solution {
 public:
  int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
    priority_queue<ipair> buy_q;
    priority_queue<ipair, vector<ipair>, greater<>> sell_q;

    for (const auto& order : orders) {
      auto price = order[0];
      auto amount = order[1];
      auto otype = order[2];
      if (otype == 0) {
        while (amount > 0 && (!sell_q.empty()) && sell_q.top().first <= price) {
          auto [sell_price, sell_amount] = sell_q.top();
          sell_q.pop();
          const int ntrans = min(amount, sell_amount);
          amount -= ntrans;
          if (sell_amount > ntrans) {
            sell_q.push({sell_price, sell_amount - ntrans});
          }
        }
        if (amount > 0) {
          buy_q.push({price, amount});
        }
      } else {
        while (amount > 0 && (!buy_q.empty()) && buy_q.top().first >= price) {
          auto [buy_price, buy_amount] = buy_q.top();
          buy_q.pop();
          const int ntrans = min(amount, buy_amount);
          amount -= ntrans;
          if (buy_amount > ntrans) {
            buy_q.push({buy_price, buy_amount - ntrans});
          }
        }
        if (amount > 0) {
          sell_q.push({price, amount});
        }
      }
    }
    int ans = 0;
    while (!buy_q.empty()) {
      auto [price, amount] = buy_q.top();
      buy_q.pop();
      ans = (ans + amount) % base;
    }
    while (!sell_q.empty()) {
      auto [price, amount] = sell_q.top();
      sell_q.pop();
      ans = (ans + amount) % base;
    }
    return ans;
  }
};
