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
  int minOperations(vector<int>& nums, int x) {
    const int n = nums.size();
    vector<int> psum(n);
    psum[0] = nums[0];
    for (int i = 1; i < n; i++) {
      psum[i] = psum[i - 1] + nums[i];
    }
    const int total = psum.back();
    if (total < x) return -1;
    int ans = INT_MAX;
    const int diff = total - x;
    auto it = lower_bound(psum.begin(), psum.end(), diff);
    if (it != psum.end() && *it == diff) {
      int idx = it - psum.begin();
      ans = n - (idx + 1);
    }
    for (int i = 1; i < n; i++) {
      int target = diff + psum[i - 1];
      auto it = lower_bound(psum.begin(), psum.end(), target);
      if (it != psum.end() && *it - psum[i - 1] == diff) {
        int j = it - psum.begin();
        ans = min(ans, n - (j - i + 1));
      }
    }
    if (ans == INT_MAX)
      return -1;
    else
      return ans;
  }
};
