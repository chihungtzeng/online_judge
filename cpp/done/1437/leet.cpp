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
  bool kLengthApart(vector<int>& nums, int k) {
    vector<int> stack;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != 1) continue;
      if (!stack.empty()) {
        if (i - stack.back() - 1 < k)
          return false;
        else
          stack.pop_back();
      }
      stack.push_back(i);
    }
    return true;
  }
};
