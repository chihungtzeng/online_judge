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
  bool isPossible(vector<int>& target) {
    if (target.size() == 1) {
      return target[0] == 1;
    }
    int64_t sum = accumulate(target.begin(), target.end(), 0ll);
    priority_queue<int64_t> pq(target.begin(), target.end());
    bool ans = true;
    while (!pq.empty() && ans) {
      auto val = pq.top();
      pq.pop();
      //      LOG(INFO) << "pop " << val << " cur sum: " << sum;
      if (val == 1) continue;
      int diff = sum - val;
      int ratio = val / diff;
      int org_val = val;
      if (ratio <= 0) {
        ans = false;
      }
      sum -= val;
      val = val - diff * ratio;
      if (val < 1) val += diff;

      if (val == org_val) {
        ans = false;
      }
      sum += val;

      if (val < 1) {
        ans = false;
      } else {
        pq.push(val);
        //        LOG(INFO) << "push " << val;
      }
    }
    return ans;
  }
};
