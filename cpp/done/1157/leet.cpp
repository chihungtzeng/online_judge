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
class MajorityChecker {
 public:
  unordered_map<int, vector<int>> inv_arr_;
  vector<int> arr_;
  MajorityChecker(vector<int>& arr) {
    for (int i = 0, n = arr.size(); i < n; i++) {
      inv_arr_[arr[i]].push_back(i);
    }
    arr_ = arr;
  }

  int query(int left, int right, int threshold) {
    int len = right - left + 1;
    for (int i = 0; i < 20; i++) {
      int idx = left + rand() % len;
      int val = arr_[idx];
      if (inv_arr_[val].size() < threshold){
        continue;
      }
      auto start_it =
          lower_bound(inv_arr_[val].begin(), inv_arr_[val].end(), left);
      auto end_it =
          upper_bound(inv_arr_[val].begin(), inv_arr_[val].end(), right);
      if (end_it - start_it >= threshold) return val;
    }
    return -1;
  }
};

