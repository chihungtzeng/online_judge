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
  int findPairs(vector<int>& nums, int k) {
    if (k < 0) return 0;
    unordered_map<int, int> mp;
    for (auto v : nums) {
      mp[v] = mp[v] + 1;
    }
    int ans = 0;
    for (auto& [key, val] : mp) {
      if (k == 0 && val >= 2) {
        ans++;
      } else if (k > 0 && mp.find(key + k) != mp.end()) {
        ans++;
      }
    }
    return ans;
  }
};
