#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> s;
    sort(nums1.begin(), nums1.end());
    for (auto ch : nums2) {
      if (s.count(ch) > 0) {
        continue;
      }
      if (binary_search(nums1.begin(), nums1.end(), ch)) {
        s.insert(ch);
      }
    }
    return {s.begin(), s.end()};
  }
};
