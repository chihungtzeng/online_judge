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
  int minPatches(vector<int>& nums, int n) {
    int i = 0, npatch = 0;
    int64_t miss = 1;
    while (miss <= n) {
      if ((i < nums.size() && miss < nums[i]) || (i >= nums.size())) {
        npatch += 1;
        miss = miss << 1;
      } else {
        miss += nums[i++];
      }
    }
    return npatch;
  }
};
