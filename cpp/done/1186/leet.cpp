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
  int maximumSum(vector<int>& arr) {
    const int n = arr.size();

    vector<int> psum(n), ssum(n);
    psum[0] = max(0, arr[0]);
    int ans = arr[0];
    for (int i = 1; i < n; i++) {
      psum[i] = max(arr[i], arr[i] + psum[i - 1]);
      ans = max(ans, arr[i]);
      ans = max(ans, psum[i]);
    }
    ssum[n - 1] = max(0, arr[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
      ssum[i] = max(arr[i], arr[i] + ssum[i + 1]);
      ans = max(ans, ssum[i]);
    }
    for (int i = 1, j = n - 1; i < j; i++) {
      ans = max(ans, psum[i - 1] + ssum[i + 1]);
    }
    return ans;
  }
};
