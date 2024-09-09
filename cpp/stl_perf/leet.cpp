#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int bsearch(vector<int>& nums, int target) {
    auto it = std::lower_bound(nums.begin(), nums.end(), target);
    return *it;
  }
  int bsearch(list<int>& nums, int target) {
    auto it = std::lower_bound(nums.begin(), nums.end(), target);
    return *it;
  }
  int bsearch2(list<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      auto mid = left + (right - left) / 2;
      auto it = nums.begin();
      advance(it, mid);

      if (*it == target)
        return *it;
      else if (*it < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return 0;
  }

  int lower_bound(set<int>& nums, int target) {
    return *nums.lower_bound(target);
  }

  int _next(set<int>& nums, int target) {
    auto it = std::next(nums.begin(), target);
    return *it;
  }

  int _advance(set<int>& nums, int target) {
    auto it = nums.begin();
    std::advance(it, target);
    return *it;
  }
};
