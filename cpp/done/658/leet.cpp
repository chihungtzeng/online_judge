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
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    vector<int> ret;
    ret.reserve(k);
    auto it = lower_bound(arr.begin(), arr.end(), x);
    int i = it - arr.begin();
    int j = i - 1;
    while (k--) {
      if (0 <= i && i < arr.size() && 0 <= j && j < arr.size()) {
        if (abs(arr[i] - x) < abs(arr[j] - x)) {
          ret.push_back(arr[i++]);
        } else {
          ret.push_back(arr[j--]);
        }
      } else if (0 <= i && i < arr.size()) {
        ret.push_back(arr[i++]);
      } else {
        ret.push_back(arr[j--]);
      }
    }
    sort(ret.begin(), ret.end());
    return ret;
  }
};
