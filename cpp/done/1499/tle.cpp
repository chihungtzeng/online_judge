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
    for (int i = 0, j = 1; i < points.size(); i++) {
      while (j < points.size() && points[j][0] - points[i][0] <= k) {
        j++;
      }
      for (int k = i + 1; k < j; k++) {
        // LOG(INFO) << "add points at " << i << ", " << k;
        ans =
            max(ans, points[k][1] + points[i][1] + points[k][0] - points[i][0]);
      }
    }
    return ans;
  }
};
