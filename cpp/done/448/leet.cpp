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
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      auto idx = abs(nums[i]) - 1;
      if (nums[idx] > 0) nums[idx] = -nums[idx];
    }
    vector<int> ret;
    ret.reserve(n);
    for (int i = 0; i < n; i++) {
      if (nums[i] > 0) ret.push_back(i + 1);
    }
    return ret;
  }
};
