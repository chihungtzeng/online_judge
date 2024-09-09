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
  double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    int64_t wnd = 0, sum = 0;
    for (int i = n - 1; i >= n - k; i--) {
      wnd += nums[i];
    }
    sum = wnd;
    for (int i = n - 1, j = n - k - 1; j >= 0; i--, j--) {
      wnd = wnd - nums[i] + nums[j];
      sum = max(sum, wnd);
    }
    return double(sum) / k;
  }
};
