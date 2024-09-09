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
  int maxDistance(vector<int>& pos, int m) {
    sort(pos.begin(), pos.end());
    int left = 0, right = pos.back() - pos[0], mid = 0;
    while (left <= right) {
      mid = left + (right - left) / 2;
      if (can_fit(pos, m, mid)) {
        // LOG(INFO) << "can fit with " << mid;
        left = mid + 1;
      } else {
        // LOG(INFO) << "can NOT fit with " << mid;
        right = mid - 1;
      }
    }
    if (can_fit(pos, m, mid)) {
      return mid;
    } else {
      return mid - 1;
    }
  }
  bool can_fit(vector<int>& arr, int m, int f) {
    int cnt = 0, cur = 0;
    int start = 0;
    m--;
    for (int i = 1; i < arr.size(); i++) {
      cur = arr[i] - arr[start];
      if (cur >= f) {
        start = i;
        m--;
      }
    }
    return bool(m <= 0);
  }
};
