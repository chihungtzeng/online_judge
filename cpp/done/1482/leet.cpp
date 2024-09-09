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
  int minDays(vector<int>& bloomDay, int m, int k) {
    const int n = bloomDay.size();
    if (m * k > n) return -1;
    int bouquet = 0, left = 0, right = 1e9, flower = 0;
    int ret = INT_MAX;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      bouquet = 0;
      flower = 0;
      for (int i = 0; i < n; i++) {
        if (bloomDay[i] > mid) {
          flower = 0;
        } else {
          flower++;
          if (flower == k) {
            bouquet++;
            flower = 0;
          }
        }
      }
      if (bouquet >= m) {
        ret = min(ret, mid);
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    if (ret == INT_MAX) return -1;
    return ret;
  }
};
