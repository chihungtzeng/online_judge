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
  int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    const int n = nums.size();
    vector<int64_t> psum(n, nums[0]);
    for (int i = 1; i < n; i++) {
      psum[i] = psum[i - 1] + nums[i];
    }
    int best = 1;
    for (int i = 0; i < n; i++) {
      int left = 0, right = i - 1;
      int best_j = -1;
      while (left <= right) {
        int j = (left + right) >> 1;
        int64_t nop =
            static_cast<int64_t>(nums[i]) * (i - j) - range_sum(psum, j, i - 1);
        if (nop <= k) {
          best_j = j;
          right = j - 1;
        } else {
          left = j + 1;
        }
      }
      //      LOG(INFO) << "i: " << i << " best_j: " << best_j;
      if (best_j >= 0) {
        best = max(best, i - best_j + 1);
      }
    }
    return best;
  }
  int64_t range_sum(vector<int64_t>& psum, int from, int to) {
    if (from == 0)
      return psum[to];
    else
      return psum[to] - psum[from - 1];
  }
};
