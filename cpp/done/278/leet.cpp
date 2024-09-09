#include <algorithm>
#include <cstdint>
#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    int left = 1, right = n, mid = 1;
    while (left <= right) {
      mid = left + (right - left) / 2;
      if (isBadVersion(mid)) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    if (isBadVersion(mid)) {
      return mid;
    } else {
      return mid + 1;
    }
  }
};
