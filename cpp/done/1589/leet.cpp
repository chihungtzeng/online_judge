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
  int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
    const int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> cnt(n);
    for (auto& r : requests) {
      cnt[r[0]]++;
      if (r[1] + 1 < n) {
        cnt[r[1] + 1]--;
      }
    }
    for (int i = 1; i < n; i++) {
      cnt[i] += cnt[i - 1];
    }
    sort(cnt.begin(), cnt.end());
    int ret = 0;
    const int base = 1e9 + 7;
    for (int i = 0; i < n; i++) {
      ret = (ret + nums[i] * cnt[i]) % base;
    }
    return ret;
  }
};
