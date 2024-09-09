#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxCoins(vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }
    vector<vector<int>> coins(nums.size(), vector<int>(nums.size(), -1));
    return solve(nums, coins, 0, nums.size() - 1);
  }
  int solve(const vector<int>& nums, vector<vector<int>>& coins, int left,
            int right) {
    if (left > right) {
      return 0;
    }
    if (coins[left][right] != -1) {
      return coins[left][right];
    }
    int lcoin = 1, rcoin = 1;
    if (left > 0) lcoin = nums[left - 1];
    if (right < nums.size() - 1) rcoin = nums[right + 1];
    int ans = -1;
    int temp = lcoin * rcoin;
    for (int i = left; i <= right; i++) {
      ans = max(ans, temp * nums[i] + solve(nums, coins, left, i - 1) +
                         solve(nums, coins, i + 1, right));
    }
    coins[left][right] = ans;
    return ans;
  }
};
