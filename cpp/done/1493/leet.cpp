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

using ipair = pair<int, int>;
class Solution {
 public:
  int longestSubarray(vector<int>& nums) {
    vector<ipair> segs;
    int start = -1;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 1 && start < 0)
        start = i;
      else if (nums[i] == 0 && start >= 0) {
        segs.push_back({start, i - 1});
        start = -1;
      }
    }
    if (start >= 0) segs.push_back({start, nums.size() - 1});
    if (segs.size() == 0) return 0;
    if (segs.size() == 1) {
      int can = segs[0].second - segs[0].first + 1;
      if (can == nums.size())
        return can - 1;
      else
        return can;
    }
    int ret = segs[0].second - segs[0].first + 1;
    for (int i = segs.size() - 1; i >= 1; i--) {
      if (segs[i - 1].second + 2 == segs[i].first) {
        ret = max(ret, segs[i].second - segs[i - 1].first);
      } else {
        ret = max(ret, segs[i].second - segs[i].first + 1);
      }
    }
    return ret;
  }
};
