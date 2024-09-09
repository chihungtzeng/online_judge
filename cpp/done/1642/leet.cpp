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
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    vector<int> diff(heights.size());
    for (int i = 1; i < heights.size(); i++) {
      diff[i] = heights[i] - heights[i - 1];
    }
    int left = 0, right = heights.size() - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (can_go(diff, bricks, ladders, mid)) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return left - 1;
  }
  int can_go(vector<int>& diff, int bricks, int ladders, int kth) {
    vector<int> diffs;
    for (int i = 0; i <= kth; i++) {
      if (diff[i] > 0) {
        diffs.push_back(diff[i]);
      }
    }
    // LOG(INFO) << "kth: " << kth << " diffs: " << diffs;
    sort(diffs.begin(), diffs.end());
    if (diffs.size() <= ladders) return true;
    while (diffs.size() > 0 && ladders > 0) {
      diffs.pop_back();
      ladders--;
    }
    return bool(accumulate(diffs.begin(), diffs.end(), 0) <= bricks);
  }
};
