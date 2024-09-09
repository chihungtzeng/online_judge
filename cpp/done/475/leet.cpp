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
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    int ans = 0;
    sort(heaters.begin(), heaters.end());
    for (int i = 0; i < houses.size(); i++) {
      auto it = lower_bound(heaters.begin(), heaters.end(), houses[i]);
      int idx = it - heaters.begin();
      int dist = 0;
      if (idx > 0 && idx < heaters.size()) {
        dist = min(abs(*it - houses[i]), abs(heaters[idx - 1] - houses[i]));
      } else if (idx == 0) {
        dist = abs(*it - houses[i]);
      } else {
        dist = abs(heaters.back() - houses[i]);
      }
      ans = max(ans, dist);
    }
    return ans;
  }
};
