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

constexpr int base = 1e9 + 7;
class Solution {
 public:
  int countNicePairs(vector<int>& nums) {
    vector<int> diff(nums.size());
    unordered_map<int, int> cnt;
    int ans = 0;
    for (int i = nums.size() - 1; i >= 0; i--) {
      int diff = nums[i] - rev(nums[i]);
      auto it = cnt.find(diff);
      if (it != cnt.end()) {
        ans = (ans + it->second) % base;
        it->second += 1;
      } else {
        cnt[diff] = 1;
      }
    }
    return ans;
  }
  int rev(int n) {
    int ret = 0;
    while (n > 0) {
      ret = ret * 10 + (n % 10);
      n = n / 10;
    }
    return ret;
  }
};
