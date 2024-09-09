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
  int clamp(int a, int left, int right) { return max(left, min(a, right)); }
  bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
    int xnear = clamp(xc, x1, x2);
    int ynear = clamp(yc, y1, y2);
    int xdiff = xnear - xc;
    int ydiff = ynear - yc;
    return xdiff * xdiff + ydiff * ydiff <= r * r;
  }
};
