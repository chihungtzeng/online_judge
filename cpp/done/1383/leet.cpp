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
  int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {
    const int base = 1e9 + 7;
    vector<ipair> pairs(n);
    for (int i = 0; i < n; i++) {
      pairs[i] = {eff[i], speed[i]};
    }
    sort(pairs.begin(), pairs.end());
    reverse(pairs.begin(), pairs.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    int64_t total = 0;
    int64_t res = 0;
    for (auto& [e, s] : pairs) {
      pq.push(s);
      total += s;
      if (pq.size() > k) {
        total -= pq.top();
        pq.pop();
      }
      res = max(res, total * e);
    }
    return res % base;
  }
};
