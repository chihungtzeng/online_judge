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
  bool containsPattern(vector<int>& arr, int m, int k) {
    for (int i = 0; i < arr.size(); i++) {
      int nrepeat = 1;
      for (int j = i + m; j < arr.size(); j += m) {
        if (same(arr, i, j, m)) {
          //   LOG(INFO) << "arr [" << i << ", " << i+m << "]  same with ["  <<
          //   j
          //   << ", " << j +m << "]";
          nrepeat++;
        } else {
          break;
        }
        if (nrepeat == k) break;
      }
      if (nrepeat >= k) return true;
    }
    return false;
  }
  bool same(vector<int>& arr, int s1, int s2, int m) {
    if (s2 + m - 1 >= arr.size()) return false;
    for (int i = s1, j = s2, stop = i + m; i < stop; i++, j++) {
      if (arr[i] != arr[j]) return false;
    }
    return true;
  }
};
