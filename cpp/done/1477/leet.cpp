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
  int minSumOfLengths(vector<int>& arr, int target) {
    const int n = arr.size();
    vector<int> psum(n + 1), pmin(n + 2, INT_MAX), smin(n + 2, INT_MAX);
    for (int i = 1; i <= n; i++) {
      psum[i] = arr[i - 1] + psum[i - 1];
      int lookfor = psum[i] - target;
      auto it = upper_bound(psum.begin(), psum.begin() + i, lookfor);
      int dist = it - psum.begin();
      dist--;
      if (dist >= 0 && psum[dist] == lookfor) pmin[i] = min(pmin[i], i - dist);

      pmin[i] = min(pmin[i], pmin[i - 1]);
    }
    for (int i = n - 1; i >= 1; i--) {
      int lookfor = target + psum[i];
      auto it = lower_bound(psum.begin() + i + 1, psum.end(), lookfor);
      int dist = it - psum.begin();
      // LOG(INFO) << "i:" << i <<" lookfor: " << lookfor << " dist: " << dist;
      if (dist <= n && psum[dist] == lookfor) smin[i] = min(smin[i], dist - i);

      smin[i] = min(smin[i], smin[i + 1]);
    }
    int ret = INT_MAX;
    for (int i = 1; i <= n; i++) {
      if (smin[i] < INT_MAX && pmin[i] < INT_MAX) {
        ret = min(ret, smin[i] + pmin[i]);
      }
    }
#if 0
    LOG(INFO) << psum;
    LOG(INFO) << pmin;
    LOG(INFO) << smin;
#endif
    if (ret == INT_MAX) return -1;
    return ret;
  }
};
