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
  bool checkStraightLine(vector<vector<int>>& ps) {
    sort(ps.begin(), ps.end());
    int dx = ps[1][0] - ps[0][0];
    int dy = ps[1][1] - ps[0][1];
    for (int i = 1, stop = ps.size() - 1; i < stop; i++) {
      if (dx != 0 && dy != 0) {
        if (dy*(ps[i + 1][0] - ps[i][0]) != dx*(ps[i + 1][1] - ps[i][1])) return false;
      } else if (dx != 0 && dy == 0){
        if (ps[i + 1][1] != ps[i][1]) return false;
      } else if (dx == 0 && dy != 0){
        if (ps[i + 1][0] != ps[i][0]) return false;
      }
    }
    return true;
  }
};
