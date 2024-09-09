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
  bool check(vector<int>& nums) {
    int n = nums.size();
    if (n <= 2) {
      return true;
    }
    int gap = nums.back() - nums[0];
    int sidx = 0;
    for (int i = 1; i < n; i++) {
      int temp = nums[i - 1] - nums[i];
      if (temp > gap) {
        gap = temp;
        sidx = i;
      }
    }
    for (int i = 1; i < sidx; i++) {
      if (nums[i - 1] > nums[i]) {
        return false;
      }
    }
    for (int i = sidx; i < n - 1; i++) {
      if (nums[i] > nums[i + 1]) {
        return false;
      }
    }
    if (sidx > 0){
      return bool(nums[0] >= nums[n-1]);
    } else {
      return true;
    }
  }
};
