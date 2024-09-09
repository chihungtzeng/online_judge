#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
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
  bool makesquare(vector<int>& nums) {
    if (nums.empty()) return false;
    int perimeter = accumulate(nums.begin(), nums.end(), 0);
    if (perimeter < 0 || perimeter % 4 != 0) return false;
    vector<int> edge_lens(4);
    edge_lens[0] = nums[0];
    return dfs(nums, 1, perimeter / 4, edge_lens);
  }
  bool dfs(vector<int>& nums, const int pos, const int target,
           vector<int>& edge_lens) {
    if (pos == nums.size()) return true;
    for (int i = 0; i < 4; i++) {
      if (edge_lens[i] + nums[pos] <= target) {
        edge_lens[i] += nums[pos];
        if (dfs(nums, pos + 1, target, edge_lens)) return true;
        edge_lens[i] -= nums[pos];
      }
    }
    return false;
  }
};
