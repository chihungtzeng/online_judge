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
  int maxSum(vector<int>& nums1, vector<int>& nums2) {
    vector<int> common;
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] == nums2[j]) {
        common.push_back(nums1[i]);
        i++;
        j++;
      } else if (nums1[i] < nums2[j]) {
        i++;
      } else {
        j++;
      }
    }
    common.push_back(INT_MAX);
    vector<int64_t> s1(common.size()), s2(common.size());
    i = 0;
    j = 0;

    while (j < s1.size()) {
      while (i < nums1.size() && nums1[i] <= common[j]) {
        s1[j] += nums1[i++];
      }
      j++;
    }
    i = 0;
    j = 0;
    while (j < s2.size()) {
      while (i < nums2.size() && nums2[i] <= common[j]) {
        s2[j] += nums2[i++];
      }
      j++;
    }
    int64_t ans = 0;
    for (i = 0; i < common.size(); i++) {
      ans += max(s1[i], s2[i]);
      ans = ans % 1000000007;
    }
    return ans;
  }
};
