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
  int minimumIncompatibility(vector<int>& nums, int k) {
    const int n = nums.size();
    if (k == n) {
      return 0;
    }
    int nelem_per_group = n / k;
    if (!can_partition(nums, k)) return -1;

    vector<int> gids;
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < nelem_per_group; j++) {
        gids.push_back(i);
      }
    }
    int ans = INT_MAX;
    sort(nums.begin(), nums.end());
    do {
      int can = calc_incompatibility(nums, gids, n, k);
      if (can < INT_MAX) {
        ans = min(ans, can);
      }
    } while (next_permutation(gids.begin(), gids.end()));

    return ans;
  }
  int calc_incompatibility(vector<int>& nums, vector<int>& gids, int n, int k) {
    vector<vector<int>> groups(k);
    for (int i = 0; i < n; i++) {
      groups[gids[i]].push_back(nums[i]);
    }
    int incomp = 0;
    for (auto& group : groups) {
      for (int i = 0; i < group.size() - 1; i++) {
        if (group[i] == group[i + 1]) return INT_MAX;
      }
      incomp += group.back() - group[0];
    }
    return incomp;
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
