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
  vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    vector<double> ret;
    if (k == 0) return ret;
    if (k == 1) return vector<double>(nums.begin(), nums.end());
    int even = (k % 2 == 0) ? 1 : 0;
    multiset<int> wnd{nums.begin(), nums.begin() + k};
    auto it = wnd.begin();
    auto half_k = k >> 1;
    if (even) {
      advance(it, half_k - 1);
      double v = *it / 2.0 + *next(it) / 2.0;
      ret.push_back(v);
    } else {
      advance(it, half_k);
      ret.push_back(*it);
    }

    for (int i = k; i < nums.size(); i++) {
      wnd.erase(wnd.lower_bound(nums[i - k]));
      wnd.insert(nums[i]);
      it = wnd.begin();
      if (even) {
        advance(it, half_k - 1);
        double v = *it / 2.0 + *next(it) / 2.0;
        ret.push_back(v);
      } else {
        advance(it, half_k);
        ret.push_back(*it);
      }
    }
    return ret;
  }
};
