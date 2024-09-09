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
  int maximizeSweetness(vector<int>& s, int k) {
    const int n = s.size();
    int left = 0, right = accumulate(s.begin(), s.end(), 0) / (k + 1);
    while (left <= right) {
      int mid = left + (right - left) / 2;
      int ncuts = 0;
      int sum = 0;
      for (int i = 0; i < n; i++) {
        sum += s[i];
        if (sum >= mid) {
          sum = 0;
          ncuts++;
        }
      }
      LOG(INFO) << pair<int, int>{left, right} << " mid: " << mid << " ncuts:" << ncuts;
      if (ncuts >= k + 1) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    LOG(INFO) << "final: " << pair<int, int>{left, right};
    return left - 1;
  }
};
