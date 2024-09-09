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
  int waysToMakeFair(vector<int>& nums) {
    const int n = nums.size();
    int esum = 0, osum = 0;
    int esum_head = 0, osum_head = 0;
    for (int i = 0; i < n; i++) {
      if (i & 1)
        osum += nums[i];
      else
        esum += nums[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      const bool is_odd = bool(i & 1);
      if (is_odd) {
        osum -= nums[i];
      } else {
        esum -= nums[i];
      }

      if (esum + osum_head == osum + esum_head) {
        ans++;
      }

      if (is_odd) {
        osum_head += nums[i];
      } else {
        esum_head += nums[i];
      }
    }
    return ans;
  }
};
