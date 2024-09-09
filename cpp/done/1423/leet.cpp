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
  int maxScore(vector<int>& ps, int k) {
    int ans = 0;
    unordered_map<int, int> psum;
    psum[-1] = 0;
    const int n = ps.size();
    for (int i = 0; i < n; i++) {
      psum[i] = psum[i - 1] + ps[i];
    }

    for (int l = 0; l <= k; l++) {
      int r = k - l;
      ans = max(ans, psum[l - 1] + psum[n - 1] - psum[n - r - 1]);
    }
    return ans;
  }
};
