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
  int waysToSplit(vector<int>& nums) {
    const int n = nums.size();
    vector<int> psum(n);
    psum[0] = nums[0];
    for (int i = 1; i < n; i++) {
      psum[i] = psum[i - 1] + nums[i];
    }
    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
      int left_seg = range_sum(psum, 0, i);
      int l = i + 1, r = n - 1;
      while (l <= r) {
        int m = (l + r) / 2;
        int mid_seg = range_sum(psum, i + 1, m);
        int right_seg = range_sum(psum, m+1, n-1);
        if (left_seg > mid_seg) {
          l = m + 1;
        } else {
          if (mid_seg > right_seg) {
            r = m - 1;
          } else {
            l = m + 1;
          }
        }
      }
      if (l < n) {
        ans += l - i;
        int addon = l -i;
        LOG(INFO) << "i: " << i << " addon: " << addon;
      }
    }
    return ans;
  }
  int range_sum(vector<int>& psum, int from, int to) {
    if (from == 0)
      return psum[to];
    else
      return psum[to] - psum[from - 1];
  }
};
