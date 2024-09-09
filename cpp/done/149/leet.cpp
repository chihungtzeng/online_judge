#include <algorithm>
#include <cstdint>
#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

using tuple_t = std::tuple<int, int>;

class Solution {
public:
  int gcd(int m, int n) {
    while (n != 0) {
      auto temp = m % n;
      m = n;
      n = temp;
    }
    return m;
  }
  int maxPoints(vector<vector<int>> &points) {
    if (points.size() <= 2) {
      return points.size();
    }
    sort(points.begin(), points.end());
    int ans = 0;

    for (size_t i = 0; i < points.size(); i++) {
      int vertical = 0;
      int horizontal = 0;
      int overlap = 1;
      std::map<tuple_t, int> slopes;
      for (size_t j = i + 1; j < points.size(); j++) {
        auto dx = points[j][0] - points[i][0];
        auto dy = points[j][1] - points[i][1];
        if (dx == 0 && dy == 0) {
          overlap++;
          continue;
        }
        if (dx == 0) {
          vertical++;
          continue;
        }
        if (dy == 0) {
          horizontal++;
          continue;
        }
        auto _gcd = gcd(dx, abs(dy));
        auto slope_x = dx / _gcd;
        auto slope_y = dy / _gcd;
        auto slope = tuple_t{slope_x, slope_y};
        if (slopes.find(slope) == slopes.end())
        {
          slopes[slope] = 1;
        }
        else {
          slopes[slope] += 1;
        }
      }
      auto local_ans = vertical;
      if (slopes.size() > 0) {
        auto max_elem =
            std::max_element(slopes.begin(), slopes.end(),
                             [](const std::pair<tuple_t, int> &a,
                                const std::pair<tuple_t, int> &b) -> bool {
                               return a.second < b.second;
                             });
        local_ans = max(local_ans, max_elem->second);
      }
      local_ans = max(local_ans, horizontal);
      local_ans += overlap;
      ans = max(ans, local_ans);
    }

    return ans;
  }
};
