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

using ipair = pair<int64_t, int64_t>;
class Solution {
 public:
  int nthUglyNumber(int n, int a, int b, int c) {
    auto cmp = [](const auto& a, const auto& b) {
      if (a.first != b.first) {
        return a.first > b.first;
      } else {
        return a.second > b.second;
      }
    };
    priority_queue<ipair, vector<ipair>, decltype(cmp)> pq(cmp);

    // a, b, c might be duplicate or a multiple of another number.
    vector<int> bases{a, b, c};
    sort(bases.begin(), bases.end());
    pq.push({bases[0], bases[0]});
    for (int i = 1; i < 3; i++) {
      if (bases[i] % bases[0] == 0) {
        continue;
      }
      if (i == 2 && bases[2] % bases[1] == 0) {
        continue;
      }
      pq.push({bases[i], bases[i]});
    }
    if (pq.size() == 1) {
      return pq.top().first * n;
    }
    int remains = n;
    int64_t ans = 0;
    while (remains > 0) {
#if DEBUG
      vector<ipair> temp;
      while (!pq.empty()) {
        temp.push_back(pq.top());
        pq.pop();
      }
      LOG(INFO) << "pq: " << temp;
      for (auto& v : temp) {
        pq.push(v);
      }
#endif
      auto [least, diff] = pq.top();
      pq.pop();
      while (!pq.empty() && pq.top().first == least) {
        auto [val, d2] = pq.top();
        pq.pop();
        pq.push({val + d2, d2});
      }
      auto [bigger, bdiff] = pq.top();
      int multiple = (bigger - least) / diff;
#if DEBUG
      LOG(INFO) << "least: " << least << " diff: " << diff
                << " bigger: " << bigger << " mutliple: " << multiple
                << " remains: " << remains;
#endif
      if (multiple + 1 >= remains) {
        ans = least + diff * (remains - 1);
        remains = 0;
      } else {
        remains -= multiple + 1;
        auto next = least + diff * (multiple + 1);
        if (next - diff == bigger) {
          // watch: if we cover |bigger| in this iteration, we should update the
          // |bigger| pair in pq.
          pq.pop();
          pq.push({bigger + bdiff, bdiff});
        }
        pq.push({next, diff});
      }
    }
    return ans;
  }
};
