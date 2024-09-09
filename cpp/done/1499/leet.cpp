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
  int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
    int ans = INT_MIN;
    deque<pair<int, int>> q;
    for (int i = 0; i < points.size(); i++) {
      while (!q.empty() && points[i][0] - q.front().second > k) q.pop_front();
      if (!q.empty()) {
        ans = max(ans, q.front().first + points[i][0] + points[i][1]);
      }
      int y_x = points[i][1] - points[i][0];
      while (!q.empty() && q.back().first < y_x) q.pop_back();
      q.push_back({y_x, points[i][0]});
    }
    return ans;
  }
};
