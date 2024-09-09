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
  bool isPossibleDivide(vector<int>& nums, int k) {
    if (nums.size() % k != 0) return false;
    int nsets = nums.size() / k;
    multiset<int> s(nums.begin(), nums.end());
    while (nsets--) {
      int least = *s.begin();
      for (int i = 0; i < k; i++) {
        int target = least + i;
        auto it = s.find(target);
        if (it == s.end()) return false;
        s.erase(it);
      }
    }
    return true;
  }
};
