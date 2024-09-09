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
  int smallestDivisor(vector<int>& nums, int threshold) {
    int left = 1, right = 1e6;
    //    int best = INT_MAX;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (leq_thresh(nums, threshold, mid)) {
        right = mid - 1;
        //        best = min(best, mid);
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
  bool leq_thresh(vector<int>& nums, int thresh, int div) {
    int s = 0;
    for (int i = nums.size() - 1; i >= 0; i--) {
      s += (nums[i] + div - 1) / div;
    }
    //    LOG(INFO) << "div: " << div << ": s=" << s;
    return bool(s <= thresh);
  }
};
