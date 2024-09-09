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
  int getMaxLen(vector<int>& nums) {
    int last_zero = -1, last_neg = -1, nneg = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) {
        last_zero = i;
        last_neg = -1;
        nneg = 0;
      }
      if (nums[i] < 0 && last_neg < 0) {
        last_neg = i;
      }
//      LOG(INFO) << "i: " << i << " i - last_zero: " << i - last_zero << " i-last_neg: " << i-last_neg;
      if (nums[i] < 0) {
        nneg++;
        if (nneg % 2 == 0) {
          ans = max(ans, i - last_zero);
        } else if (last_neg >= 0) {
          ans = max(ans, i - last_neg);
        }
      }
      if (nums[i] > 0) {
        if (last_neg >= 0 && nneg % 2 == 1) {
          ans = max(ans, i - last_neg);
        } else {
          ans = max(ans, i - last_zero);
        }
      }
    }
    return ans;
  }
};
