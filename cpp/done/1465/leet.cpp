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
  int maxArea(int h, int w, vector<int>& hcuts, vector<int>& vcuts) {
    const int base = 1e9 + 7;
    sort(hcuts.begin(), hcuts.end());
    sort(vcuts.begin(), vcuts.end());
    hcuts.push_back(h);
    vcuts.push_back(w);
    int vmax = vcuts[0];
    for (int i = 1; i < vcuts.size(); i++) {
      vmax = max(vmax, vcuts[i] - vcuts[i - 1]);
    }
    int hmax = hcuts[0];
    for (int i = 1; i < hcuts.size(); i++) {
      hmax = max(hmax, hcuts[i] - hcuts[i - 1]);
    }
    int64_t area = ((int64_t)hmax * vmax) % base;
    return area;
  }
};
