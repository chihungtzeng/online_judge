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
  int numTriplets(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> cnt1, cnt2;
    for (auto v : nums1) {
      cnt1[v]++;
    }
    for (auto v : nums2) {
      cnt2[v]++;
    }
    return helper(cnt1, cnt2) + helper(cnt2, cnt1);
  }
  int helper(unordered_map<int, int>& cnt1, unordered_map<int, int>& cnt2) {
    int ans = 0;
    for (auto& [v1, c1] : cnt1) {
      int64_t sq = (int64_t)v1 * v1;
      for (auto& [v2, c2] : cnt2) {
        if (sq % v2 != 0) continue;
        int64_t target = sq / v2;
        if (v2 == v1)
          ans += c2 * (c2 - 1) * c1;
        else {
          auto it = cnt2.find(target);
          if (it != cnt2.end()) {
            ans += c2 * c1 * it->second;
          }
        }
      }
    }
    return ans / 2;
  }
};
