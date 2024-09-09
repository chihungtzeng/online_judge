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
  vector<int> findRightInterval(vector<vector<int>>& intervals) {
    vector<ipair> starts;
    for (int i = 0; i < intervals.size(); i++) {
      starts.push_back({intervals[i][0], i});
    }
    sort(starts.begin(), starts.end());
    vector<int> ans;
    for (int i = 0; i < intervals.size(); i++) {
      ans.push_back(find_right(starts, intervals[i][1]));
    }
    return ans;
  }
  int find_right(vector<ipair>& starts, int x) {
    int l = 0, r = starts.size() - 1, mid;
    while (l <= r) {
      mid = l + (r - l) / 2;
      if (starts[mid].first < x)
        l = mid + 1;
      else if (starts[mid].first == x)
        return starts[mid].second;
      else
        r = mid - 1;
    }
    if (mid == starts.size() - 1 && starts[mid].first < x) return -1;
    if (starts[mid].first >= x)
      return starts[mid].second;
    else
      return starts[mid + 1].second;
  }
};
