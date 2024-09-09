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
  int minSpeedOnTime(vector<int>& dist, double hour) {
    if (dist.size() - 1 >= hour) {
      return -1;
    }
    int best = 1e7;
    int left = 1, right = 1e7 + 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (can_arrive(dist, hour, mid)) {
        //    LOG(INFO) << "can use speed " << mid;
        best = min(best, mid);
        right = mid - 1;
      } else {
        //      LOG(INFO) << "cannot use speed " << mid;
        left = mid + 1;
      }
    }
    return best;
  }
  bool can_arrive(vector<int>& dist, const double hour, const int speed) {
    int travel = 0;
    for (int i = dist.size() - 2; i >= 0; i--) {
      travel += (dist[i] / speed) + ((dist[i] % speed == 0) ? 0 : 1);
    }
    double res = travel + dist.back() / double(speed);
    //    LOG(INFO) << "Using speed " << speed << ", travel time is " << res;

    return res <= hour;
  }
};
