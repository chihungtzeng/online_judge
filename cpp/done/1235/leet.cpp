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

using ituple = tuple<int, int, int>;
class Solution {
 public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                    vector<int>& profit) {
    vector<ituple> jobs;
    const int n = profit.size();
    jobs.reserve(n);
    for (int i = 0; i < n; i++) {
      jobs.emplace_back(startTime[i], endTime[i], profit[i]);
    }
    auto cmp = [](const auto& a, const auto& b) {
      auto [s1, e1, pt1] = a;
      auto [s2, e2, pt2] = b;
      if (e1 != e2) {
        return e1 < e2;
      } else {
        return s1 < s2;
      }
    };
    sort(jobs.begin(), jobs.end(), cmp);
#if 0
    for (auto& [start, end, profit] : jobs) {
      LOG(INFO) << start << ", " << end << ", " << profit;
    }
#endif
    int ans = 0;
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
      auto [start, end, pt] = jobs[i];
      ituple target{start, start, 0};
      auto it = upper_bound(jobs.begin(), jobs.begin() + i, target, cmp);
#if 0
      int dist = distance(it, jobs.begin());
      LOG(INFO) << "dist: " << dist;
#endif
      if (it == jobs.begin()) {
        dp[i] = pt;
      } else {
        int idx = it - jobs.begin() - 1;
        dp[i] = dp[idx] + pt;
      }
      if (i > 0) {
        dp[i] = max(dp[i], dp[i - 1]);
      }
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};
