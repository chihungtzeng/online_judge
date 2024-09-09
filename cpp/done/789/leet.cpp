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
  bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
    int dist = abs(target[0]) + abs(target[1]);
    for (int i = ghosts.size() - 1; i >= 0; i--) {
      int gdist = abs(ghosts[i][0] - target[0]) + abs(ghosts[i][1] - target[1]);
      if (gdist <= dist) return false;
    }
    return true;
  }
};
