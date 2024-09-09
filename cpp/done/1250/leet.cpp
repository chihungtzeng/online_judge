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
  bool isGoodArray(vector<int> &nums) {
    if (nums.size() == 1) {
      return bool(nums[0] == 1);
    }
    int div = gcd(nums[0], nums[1]);
    if (div == 1) return true;

    const int n = nums.size();
    for (int i = 2; i < n; i++) {
      div = gcd(div, nums[i]);
      if (div == 1) return true;
    }
    return false;
  }
};
