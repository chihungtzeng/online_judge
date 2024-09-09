#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    if (nums.size() == 0) {
      return {};
    }
    vector<int> parents(nums.size(), -1);
    vector<int> depth(nums.size(), 1);
    sort(nums.begin(), nums.end());
    size_t largest = 0;
    int largest_at = 0;
    for (size_t i = 0; i < nums.size(); i++) {
      for (size_t j = i + 1; j < nums.size(); j++) {
        if (nums[j] % nums[i] == 0 && depth[j] < depth[i] + 1) {
          depth[j] = depth[i] + 1;
          parents[j] = i;
          if (largest < depth[j]) {
            largest = depth[j];
            largest_at = j;
          }
        }
      }
    }
    vector<int> ret;
    ret.reserve(largest);
    int cur = largest_at;
    while (cur >= 0) {
      ret.push_back(nums[cur]);
      cur = parents[cur];
    }
    return ret;
  }
};
