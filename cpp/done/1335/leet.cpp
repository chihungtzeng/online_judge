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

class Solution {
 public:
  int minDifficulty(vector<int>& jobDifficulty, int d) {
    if (jobDifficulty.size() < d) return -1;
    vector<vector<int>> cache(jobDifficulty.size(), vector<int>(d + 1, -1));
    return helper(jobDifficulty, d, 0, cache);
  }
  int helper(vector<int>& jd, int remaining_days, int kth_job,
             vector<vector<int>>& cache) {
    if (remaining_days == 1) {
      return *max_element(jd.begin() + kth_job, jd.end());
    }
    if (cache[kth_job][remaining_days] >= 0)
      return cache[kth_job][remaining_days];
    int ret = INT_MAX;
    int maxd = 0;
    for (int i = kth_job; jd.size() - i >= remaining_days; i++) {
      maxd = max(maxd, jd[i]);
      ret = min(ret, maxd + helper(jd, remaining_days - 1, i + 1, cache));
    }

    cache[kth_job][remaining_days] = ret;
    return ret;
  }
};
