#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    auto cmp = [](const auto& a, const auto& b) { return a > b; };
    std::priority_queue<uint64_t, vector<uint64_t>, decltype(cmp)> pq(cmp);
    int count = 0;
    pq.push(1);
    uint64_t top = 1;
    while (count < n) {
      top = pq.top();
      pq.pop();
      if (pq.empty() || top != pq.top()) {
        count++;
        for (auto p : primes) {
          pq.push(top * p);
        }
      }
    }
    return top;
  }
};
