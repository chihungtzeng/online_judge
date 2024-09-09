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
    long long lo = 0, hi = 0;
    for (auto task : tasks) lo += task[0], hi += task[1];
    sort(tasks.begin(), tasks.end(), [](auto a, auto b) {
      if (a[1] - a[0] != b[1] - b[0]) return a[1] - a[0] > b[1] - b[0];
      return a[1] > b[1];
    });

    // for (auto task : tasks) cout << task[0]<<":"<<task[1]<<" "; cout <<"\n";
    auto isValid = [](long long energy, vector<vector<int>>& tks) {
      // cout << energy<<":: \t";
      int mini = tks[0][1], maxi = tks[0][0];
      int idx = 0;
      for (auto task : tks) {
        if (task[1] <= energy)
          energy -= task[0];
        else
          return false;
        if (tks[0][0] == task[0]) mini = min(mini, task[1]);
        idx++;
      }
      return true;
    };
    while (lo < hi) {
      long long mid = (lo + hi) / 2;
      // cout << lo << " "<<mid <<" "<<hi<<"\t";
      if (isValid(mid, tasks))
        hi = mid;
      else
        lo = mid + 1;
      // cout << lo << " "<<mid <<" "<<hi<<"\n";
    }
    return lo;
  }
};

