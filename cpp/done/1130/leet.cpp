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
  int mctFromLeafValues(vector<int>& arr) {
    if (arr.size() == 2) {
      return arr[0] * arr[1];
    }
    int product = INT_MAX;
    int best_i = -1;
    const int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
      int p = arr[i] * arr[i + 1];
      if (p < product) {
        product = p;
        best_i = i;
      }
    }
    vector<int> next_arr;
    for (int j = 0; j < best_i; j++) {
      next_arr.push_back(arr[j]);
    }
    next_arr.push_back(max(arr[best_i], arr[best_i + 1]));
    for (int j = best_i + 2; j < n; j++) {
      next_arr.push_back(arr[j]);
    }
    return product + mctFromLeafValues(next_arr);
  }
};
