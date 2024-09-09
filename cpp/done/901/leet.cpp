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

class StockSpanner {
 public:
  vector<int> stack;
  vector<int> prices;
  StockSpanner() {
    stack.reserve(10000);
    prices.reserve(10000);
  }

  int next(int price) {
    int kth = prices.size();
    prices.push_back(price);
    while (!stack.empty() && prices[stack.back()] <= price) {
      stack.pop_back();
    }
    int ret = kth + 1;
    if (!stack.empty()) {
      ret = kth - stack.back();
    }
    stack.push_back(kth);
    // LOG(INFO) << "after add " << price << ": " << stack;
    return ret;
  }
};
