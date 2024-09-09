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
  vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    uint32_t cur_xor = 0;
    for (auto v : nums) {
      cur_xor ^= v;
    }
    uint32_t suffix_mask = (1 << maximumBit) - 1;
    //    LOG(INFO) << "cur_xor: " << cur_xor;
    //    LOG(INFO) << "suffix_mask: " << suffix_mask;
    vector<int> ret;
    ret.reserve(nums.size());
    for (int i = nums.size() - 1; i >= 0; i--) {
      ret.push_back((cur_xor & suffix_mask) ^ suffix_mask);
      cur_xor ^= nums[i];
    }
    return ret;
  }
};
