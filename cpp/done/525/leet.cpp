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
  int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> seen;
    int ans = 0;
    int cnt = 0;
    seen[0] = -1;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0)
        cnt += 1;
      else
        cnt -= 1;

      auto it = seen.find(cnt);
      if (it == seen.end()) {
        seen[cnt] = i;
      } else {
        ans = max(ans, i - it->second);
      }
    }
    return ans;
  }
};
