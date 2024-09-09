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
  int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
    const int n = nums1.size();
    int64_t asd = 0;
    for (int i = 0; i < n; i++) {
      asd += abs(nums1[i] - nums2[i]);
    }
    vector<int> t1(nums1.begin(), nums1.end());
    sort(t1.begin(), t1.end());
    // LOG(INFO) << t1;
    int diff = 0;
    for (int i = 0; i < n; i++) {
      int org = abs(nums1[i] - nums2[i]);
      auto it = lower_bound(t1.begin(), t1.end(), nums2[i]);
      if (it != t1.end()) {
        diff = max(diff, org - abs(*it - nums2[i]));
        // LOG(INFO) << "i: " << i << " nums1[i]: " << nums1[i] << " lower_bound
        // for " << nums2[i] << "= " << *it;
      }
      if (it != t1.begin()) {
        it--;
        diff = max(diff, org - abs(*it - nums2[i]));
        // LOG(INFO) << "i: " << i << " nums1[i]: " << nums1[i] << " upper_bound
        // for " << nums2[i] << "= " << *it;
      }
      //      LOG(INFO) << "i: " << i << " diff: " << diff;
    }
    //    LOG(INFO) << "asd: " << asd << ", diff: " << diff;
    return (asd - diff) % base;
  }
#if 0  
  int minAbsoluteSumDiff2(vector<int>& nums1, vector<int>& nums2) {
    const int n = nums1.size();
    int64_t asd = 0;
    for (int i = 0; i < n; i++) {
      asd += abs(nums1[i] - nums2[i]);
    }
    int64_t ans = asd;
    for (int i = 0; i < n; i++) {
      int org = abs(nums1[i] - nums2[i]);
      for (int j = 0; j < n; j++) {
        int diff = abs(nums1[j] - nums2[i]);
        if (asd - org + diff < ans) {
          ans = asd - org + diff;
          LOG(INFO) << "i: " << i << ", nums1[i]: " << nums1[i]
                    << " nums2[i]: " << nums2[i] << ", replaced nums1[i] "
                    << nums1[j] << " ans: " << ans;
        }
        ans = min(ans, asd - org + diff);
      }
    }
    return ans % base;
  }
#endif
};
