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
  bool checkSubarraySum(vector<int>& nums, int k) {
    if (nums.size() < 2) return false;
    k = abs(k);
    int psum = nums[0];
    unordered_map<int, int> remains;
    if (k == 0)
      remains[psum] = 0;
    else
      remains[psum % k] = 0;

    for (int i = 1; i < nums.size(); i++) {
      psum += nums[i];
      int r = (k == 0) ? psum : psum % k;
      auto it = remains.find(r);
      if (it == remains.end()) {
        remains[r] = i;
      } else {
        int prev = it->second;
        int nelem = 0;
        if ((k == 0 && nums[prev] == 0) || (k > 0 && nums[prev] % k == 0)) {
          nelem = i - prev + 1;
        } else {
          nelem = i - prev;
        }
        if (nelem >= 2) {
          return true;
        }
      }
      if (r == 0) {
        return true;
      }
    }
    return false;
  }
};
