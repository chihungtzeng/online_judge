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
  vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    const int n = nums.size();
    vector<int> psum(n), ssum(n);
    psum[0] = nums[0];
    for (int i = 1; i < n; i++) {
      psum[i] = psum[i - 1] + nums[i];
    }
    ssum[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      ssum[i] = ssum[i + 1] + nums[i];
    }
    vector<int> ans(n);
    ans[0] = ssum[1] - nums[0] * (n - 1);
    ans[n - 1] = nums[n - 1] * (n - 1) - psum[n - 2];
    for (int i = 1, j = n - 1; i < j; i++) {
      ans[i] = nums[i] * i - psum[i - 1] + ssum[i + 1] - nums[i] * (j - i);
    }
    return ans;
  }
};
