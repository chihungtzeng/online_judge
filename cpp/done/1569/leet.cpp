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

constexpr int base = 1e9 + 7;
class Solution {
 public:
  vector<vector<int>> comb;
  int numOfWays(vector<int>& nums) {
    comb.resize(nums.size() + 1);
    for (int r = 1; r <= nums.size(); r++) {
      comb[r] = vector<int>(r + 1, 1);
      for (int c = 1; c < r; c++) {
        comb[r][c] = (comb[r - 1][c - 1] + comb[r - 1][c]) % base;
      }
    }
    return (helper(nums) - 1) % base;
  }
  int64_t helper(vector<int>& nums) {
    if (nums.size() <= 1) return 1;
    vector<int> left, right;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] < nums[0])
        left.push_back(nums[i]);
      else
        right.push_back(nums[i]);
    }
    int64_t temp = (helper(left) * helper(right)) % base;
    return (temp * comb[nums.size() - 1][left.size()]) % base;
  }
};
