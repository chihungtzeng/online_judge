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
  bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3,
                   vector<int>& p4) {
    vector<vector<int>> points{p1, p2, p3, p4};
    auto cmp = [](const auto& a, const auto& b) {
      if (a[0] != b[0])
        return a[0] < b[0];
      else
        return a[1] < b[1];
    };
    sort(points.begin(), points.end(), cmp);

    if (!form_right_angle(points[0], points[1], points[2]) ||
        !form_right_angle(points[1], points[0], points[3]) ||
        !form_right_angle(points[2], points[0], points[3]) ||
        !form_right_angle(points[3], points[1], points[2])) {
      return false;
    }
    int ds = dist_square(points[0], points[1]);
    return bool(ds > 0 && ds == dist_square(points[0], points[2]));
  }
  bool form_right_angle(vector<int>& p0, vector<int>& p1, vector<int>& p2) {
    return bool((p1[0] - p0[0]) * (p2[0] - p0[0]) +
                    (p1[1] - p0[1]) * (p2[1] - p0[1]) ==
                0);
  }
  int dist_square(vector<int>& p0, vector<int>& p1) {
    return (p1[0] - p0[0]) * (p1[0] - p0[0]) +
           (p1[1] - p0[1]) * (p1[1] - p0[1]);
  }
};
