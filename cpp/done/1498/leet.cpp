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
  int numSubseq(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    const int n = nums.size();
    const int base = 1e9 + 7;
    vector<int> pows(n);
    pows[0] = 1;
    for (int i = 1; i < n; i++) {
      pows[i] = (pows[i - 1] << 1) % base;
    }
    int l = 0;
    int r = n - 1;
    int ret = 0;
    while (l <= r) {
      if (nums[l] + nums[r] > target) {
        r--;
      } else {
        ret = (ret + pows[r - l]) % base;
        l++;
      }
    }
    return ret;
  }
};
