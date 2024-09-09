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
  int triangleNumber(vector<int>& nums) {
    if (nums.size() < 2) return 0;
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) {
        continue;
      }
      int j = i + 1, k = i + 2;
      while (j < nums.size()) {
        while (k < nums.size() && nums[i] + nums[j] > nums[k]) {
          k++;
        }
        ans += k - j - 1;
        j++;
      }
    }
    return ans;
  }
};
