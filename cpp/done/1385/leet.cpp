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
  int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    vector<ipair> segs;
    for (auto v : arr2) {
      segs.push_back({v - d, v + d});
    }
    sort(segs.begin(), segs.end());
    int ans = 0;
    for (auto v : arr1) {
      ipair key{v, INT_MAX};
      auto it = upper_bound(segs.begin(), segs.end(), key) - 1;
      bool within = false;
      while (it >= segs.begin() && !within) {
        auto& [end, start] = *it;
        if (start >= v && end <= v) within = true;
        it--;
      }
      if (!within) ans++;
    }
    return ans;
  }
};
