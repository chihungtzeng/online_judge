#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
      return 0;
    }
    sort(intervals.begin(), intervals.end());
    int end = intervals[0][1];
    int ans = 0;
    for (size_t i = 1; i < intervals.size(); i++) {
      if (intervals[i][0] < end) {
        ans++;
        end = min(end, intervals[i][1]);
      } else {
        end = intervals[i][1];
      }
    }
    return ans;
  }
};
