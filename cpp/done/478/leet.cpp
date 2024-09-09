#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
#include <cmath>
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
  const double radius_, xc_, yc_, pi2_;
  Solution(double radius, double x_center, double y_center)
      : radius_(radius), xc_(x_center), yc_(y_center), pi2_(2 * M_PI) {
    srand(time(NULL));
  }

  vector<double> randPoint() {
    double x, y, r;
    r = radius_ * sqrt((double(rand()) / INT_MAX));
    double theta = pi2_ * (double(rand()) / INT_MAX);
    x = r * cos(theta) + xc_;
    y = r * sin(theta) + yc_;
    return vector<double>{x, y};
  }
};

