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
  int minimumEffort(vector<vector<int>>& tasks) {
    auto cmp = [](const auto& a, const auto& b) {
      auto diff = a[1] - a[0] - (b[1] - b[0]);
      if (diff != 0)
        return bool(diff > 0);
      else
        return a[1] > b[1];
    };
    sort(tasks.begin(), tasks.end(), cmp);
    int ans = INT_MAX;

    int right = 1e9 + 7;
    int left = 0;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (can_finish(tasks, mid)) {
        ans = min(ans, mid);
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return ans;
  }

  bool can_finish(vector<vector<int>>& tasks, int energy) {
    const int n = tasks.size();
    for (int i = 0; i < n; i++) {
      if (tasks[i][1] > energy) return false;
      energy -= tasks[i][0];
      if (energy < 0) return false;
    }
    return true;
  }
};
