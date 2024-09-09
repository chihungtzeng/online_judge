#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <bitset>
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

using ipair = pair<int, int>;
class Solution {
 public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<ipair> segs;
    for (auto& trip : trips) {
      segs.emplace_back(trip[1], trip[0]);
      segs.emplace_back(trip[2], -trip[0]);
    }
    sort(segs.begin(), segs.end());
    int peak = 0;
    for (auto& seg : segs) {
      peak += seg.second;
      if (peak > capacity) return false;
    }
    return true;
  }
};
