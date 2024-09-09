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
  int closestToTarget(vector<int>& arr, int target) {
    set<int> pool[2];
    int idx = 0;
    int ret = INT_MAX;
    for (int i = 0; i < arr.size(); i++) {
      for (auto v : pool[1 - idx]) {
        pool[idx].insert(v & arr[i]);
      }
      pool[idx].insert(arr[i]);
      for (auto v : pool[idx]) {
#if 0
        if (abs(v - target) < ret) {
          LOG(INFO) << "update ret: " << ret << " to " << abs(v-target);
        }
#endif
        ret = min(ret, abs(v - target));
        if (ret == 0) {
          return 0;
        }
      }
      // LOG(INFO) << "pool size: " << pool.size();
      idx = 1 - idx;
      pool[idx].clear();
    }
    return ret;
  }
};
