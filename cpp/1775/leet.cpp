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
  int minOperations(vector<int>& nums1, vector<int>& nums2) {
    if (6 * min(nums1.size(), nums2.size()) < max(nums1.size(), nums2.size())) {
      return -1;
    }
    int s1 = accumulate(nums1.begin(), nums1.end(), 0);
    int s2 = accumulate(nums2.begin(), nums2.end(), 0);
    if (s1 > s2) {
      swap(s1, s2);
      swap(nums1, nums2);
    }
    vector<int> vs1(7), vs2(7);
    for (auto v : nums1) {
      vs1[v]++;
    }
    for (auto v : nums2) {
      vs2[v]++;
    }
    int ans = 0;
    for (int i = 6; i >= 2; i--) {
      int diff = s2 - s1;
      if (vs2[i] == 0) continue;
      int amount = min(diff / (i - 1), vs2[i]);
      s2 -= amount * (i - 1);
      ans += amount;
    }
    if (s1 != s2) {
      ans += 1;s2 - s1;
    }
    return ans;
  }
};
