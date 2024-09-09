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

constexpr double dh = 360.0 / 12;
constexpr double dm = 360.0 / 60;
class Solution {
 public:
  double angleClock(int hour, int minutes) {
    hour = hour % 12;
    double h = dh * (hour + minutes / 60.0);
    double m = dm * minutes;
    double diff = abs(h - m);
    // LOG(INFO) << hour << ":" << minutes << " -> " << h << " , " << m << " diff: " << diff;
    return min(diff, 360 - diff);
  }
};
