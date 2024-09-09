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

class Solution {
 public:
  int maxValue(int n, int index, int maxSum) {
    int ans = -1;
    int left = 0, right = maxSum;
    const int rseg_size = n - index - 1;
    while (left <= right){
      int mid = (right - left) / 2 + left;
      int64_t s = min_seg_sum(index, mid) + min_seg_sum(rseg_size, mid) + mid;
//      LOG(INFO) << "left: " << left << ", right: " << right << ", mid: " << mid << ", s: " << s;
      if (s > maxSum) {
        right = mid - 1;
      } else {
        left = mid + 1;
        ans = max(ans, mid);
      }
    }
    return ans;
  }

  int64_t min_seg_sum(int p, int bound) {
    int64_t res = 0;
    if (p <= 0) return 0;
    if (bound == 0) return 0;
    if (p < bound) {
      res = int64_t(p) *(2*bound - 1 -p) / 2;
    } else {
      res = (int64_t(bound) * (bound - 1)) / 2 + (p - bound + 1);
    }
    return res;
  }
};
