#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
#include <cmath>
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
  vector<int> constructRectangle(int area) {
    vector<int> pfs = prime_factors_of(area);
    if (pfs.empty()) {
      return {area, 1};
    }
    auto cmp = [](const auto& a, const auto& b) { return a > b; };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    for (auto f : pfs) pq.push(f);
    int W = 0;
    int ub = sqrt(area);
//    LOG(INFO) << "area: " << area << " pfactors: " << pfs << " ub: " << ub;
    while (!pq.empty()) {
      if (pq.top() > ub) break;

      int can = pq.top();
      while (!pq.empty() && pq.top() == can) pq.pop();
      if (area % can == 0) {
        W = can;
        for (auto f : pfs) {
          pq.push(f * W);
        }
      }
    }
    return {area / W, W};
  }
  vector<int> prime_factors_of(const int area) {
    vector<int> pfs;
    if (area % 2 == 0 && area >= 4) pfs.push_back(2);
    if (area % 3 == 0 && area >= 9) pfs.push_back(3);
    int ub = sqrt(area);
    int k = 5, offset = 2;
    while (k <= ub) {
      if (area % k == 0) pfs.push_back(k);
      k += offset;
      offset = 6 - offset;
    }
    return pfs;
  }
};
