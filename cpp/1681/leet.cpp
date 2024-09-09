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
  int nelem_per_group;
  int minimumIncompatibility(vector<int>& nums, int k) {
    const int n = nums.size();
    if (k == n) {
      return 0;
    }
    if (!can_partition(nums, k)) return -1;

    nelem_per_group = n / k;
    sort(nums.begin(), nums.end());
    vector<vector<int>> groups(k);
    return helper(nums, groups, n, k, 0);
  }

  int helper(vector<int>& nums, vector<vector<int>>& groups, const int n,
             const int k, int pos) {
    if (pos == n) {
      return calc_incomp(groups, k);
    }
    int ans = INT_MAX;
    int val = nums[pos];
    for (int i = 0; i < k; i++) {
      if (groups[i].size() == nelem_per_group) {
        continue;
      }
      if (!groups[i].empty() && groups[i].back() == val) {
        continue;
      }
      groups[i].push_back(val);
      ans = min(ans, helper(nums, groups, n, k, pos + 1));
      groups[i].pop_back();
    }
    return ans;
  }

  int calc_incomp(vector<vector<int>>& groups, int k) {
    int ret = 0;
    for (int i = 0; i < k; i++) {
      ret += groups[i].back() - groups[i][0];
    }
    return ret;
  }

  bool can_partition(vector<int>& nums, int k) {
    unordered_map<int, int> cnt;
    for (auto v : nums) {
      cnt[v]++;
    }
    for (auto& [v, c] : cnt) {
      if (c > k) return false;
    }
    return true;
  }
};
