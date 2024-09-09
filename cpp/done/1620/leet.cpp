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

class Solution {
 public:
  vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
    vector<int> ans(2);
    int strongest = 0;
    for (int x = 0; x <= 50; x++) {
      for (int y = 0; y <= 50; y++) {
        int signal = 0;
        for (auto& tower : towers) {
          int xi = tower[0];
          int yi = tower[1];
          int qi = tower[2];

          double dist = sqrt_(x - xi, y - yi);
          if (dist > radius) continue;

          int q = qi / (1 + dist);
          signal += q;
        }
        if (signal > strongest) {
          strongest = signal;
          ans[0] = x;
          ans[1] = y;
        }
      }
    }
    return ans;
  }

  double sqrt_(const int x, const int y) { return sqrt(x * x + y * y); }
};
