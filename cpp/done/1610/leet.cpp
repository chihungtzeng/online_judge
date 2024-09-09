#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
#include <cmath>
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

constexpr double PI2 = M_PI * 2;
class Solution {
 public:
  int visiblePoints(vector<vector<int>>& points, int angle,
                    vector<int>& location) {
    vector<double> radians;
    int same = 0;
    for (auto& p : points) {
      int ydiff = p[1] - location[1];
      int xdiff = p[0] - location[0];
      if (xdiff == ydiff && ydiff == 0) {
        same++;
      } else {
        auto r = atan2(ydiff, xdiff);
        if (r < 0) {
          radians.push_back(r + PI2);
        } else {
          radians.push_back(r);
        }
      }
    }
    double fov = angle * M_PI / 180.0;
    fov += 1e-9;
    sort(radians.begin(), radians.end());
    int n = radians.size();
    for (int i = 0; i < n; i++) {
      radians.push_back(radians[i] + PI2);
    }
    int ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
      while (j < radians.size() && radians[j] - radians[i] <= fov) j++;
      ans = max(ans, j - i);
    }
    return ans + same;
  }
};
