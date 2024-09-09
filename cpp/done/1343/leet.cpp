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
  int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    const int n = arr.size();
    vector<int> psum(n + 1);
    for (int i = 0; i < n; i++) {
      psum[i + 1] = psum[i] + arr[i];
    }
    int ans = 0;
    for (int e = n; e - k >= 0; e--) {
      int avg = (psum[e] - psum[e - k]) / k;
      if (avg >= threshold) ans++;
    }
    return ans;
  }
};

