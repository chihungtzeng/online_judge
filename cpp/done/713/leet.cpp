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
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int prod = 1;
    int ans = 0;
    if (k == 0) return 0;
    for (int i = 0, j = 0; i < nums.size(); i++) {
      if (j <= i) {
        j = i;
        prod = 1;
      }
      while (j < nums.size()) {
        int next = prod * nums[j];
        if (next < k) {
          prod = next;
          j++;
        } else {
          break;
        }
      }
      ans += j - i;
      // LOG(INFO) << "i: " << i << " j: " << j << " ans increase by " << j - i
      // << " prod: " << prod;
      prod = prod / nums[i];
    }
    return ans;
  }
};
