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
  vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<ipair> segs;
    for (auto& b : bookings) {
      segs.emplace_back(b[0], b[2]);
      segs.emplace_back(b[1] + 1, -b[2]);
    }
    sort(segs.begin(), segs.end());
    vector<int> ans(n);
    int seats = 0;
    int max_j = 2 * n;
    int j = 0;
    for (int i = 1; i <= n; i++) {
      while (j < max_j && segs[j].first <= i) {
        seats += segs[j].second;
        j++;
      }
      ans[i - 1] = seats;
    }
    return ans;
  }
};
