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
  vector<int> findErrorNums(vector<int>& nums) {
    int twice = 0;
    for (int i = nums.size() - 1; i >= 0; i--) {
      int val = abs(nums[i]);
      if (nums[val - 1] < 0) {
        twice = val;
      }
      nums[val - 1] *= -1;
    }
    vector<int> ret(2);
    ret[0] = twice;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0 and i + 1 != twice) {
        ret[1] = i + 1;
        break;
      }
    }
    return ret;
  }
};
