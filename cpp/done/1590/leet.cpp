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
  int minSubarray(vector<int>& nums, int p) {
    const int n = nums.size();
    int target = 0;
    for (int i = 0; i < n; i++) {
      target = (target + nums[i]) % p;
    }
    unordered_map<int, int> pos{{0, -1}};
    int cur = 0, ans = n;
    for (int i = 0; i < n; i++) {
      cur = (cur + nums[i]) % p;
      int lookfor = (p + cur - target) % p;
      pos[cur] = i;
      auto it = pos.find(lookfor);
      if (it != pos.end()) {
        ans = min(ans, i - it->second);
      }
    }
    if (ans == n) return -1;
    return ans;
  }
};
