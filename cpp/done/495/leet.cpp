#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
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
  int findPoisonedDuration(vector<int>& ts, int duration) {
    if (ts.empty()) return 0;
    int total = 0;
    int start = ts[0];
    int end = start + duration;
    for (size_t i = 1; i < ts.size(); i++) {
      if (ts[i] <= end) {
        end = ts[i] + duration;
      } else {
        total += end - start;
        start = ts[i];
        end = start + duration;
      }
    }
    total += end - start;
    return total;
  }
};
