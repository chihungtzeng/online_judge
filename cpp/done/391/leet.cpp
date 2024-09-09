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
  bool isRectangleCover(vector<vector<int>>& rectangles) {
    int area = 0;
    set<ipair> corners;
    for (auto& rect : rectangles) {
      area += (rect[2] - rect[0]) * (rect[3] - rect[1]);
      vector<ipair> rcorners{{rect[0], rect[1]},
                             {rect[0], rect[3]},
                             {rect[2], rect[1]},
                             {rect[2], rect[3]}};
      for (auto& corner : rcorners) {
        auto it = corners.find(corner);
        if (it == corners.end())
          corners.insert(corner);
        else
          corners.erase(it);
      }
    }
    if (corners.size() != 4) return false;
    /*
    vector<ipair> expect{{x1, y1}, {x1, y2}, {x2, y1}, {x2, y2}};
    for (auto& corner : expect) {
      if (corners.find(corner) == corners.end()) return false;
    }
    */
    int x1 = INT_MAX, y1 = INT_MAX, x2 = INT_MIN, y2 = INT_MIN;
    for(auto& corner: corners){
      x1 = min(x1, corner.first);
      y1 = min(y1, corner.second);
      x2 = max(x2, corner.first);
      y2 = max(y2, corner.second);
    }
    if (area != (x2 - x1) * (y2 - y1)) return false;
    return true;
  }
};
