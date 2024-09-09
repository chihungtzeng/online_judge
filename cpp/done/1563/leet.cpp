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
  int stoneGameV(vector<int>& svals) {
    int n = svals.size();
    vector<int> psum(n);
    psum[0] = svals[0];
    for (int i = 1; i < n; i++) {
      psum[i] = psum[i - 1] + svals[i];
    }
    vector<vector<int>> cache(n, vector<int>(n, -1));
    return calc(svals, cache, psum, 0, n - 1);
  }
  int calc(vector<int>& svals, vector<vector<int>>& cache, vector<int>& psum,
           int left, int right) {
    if (left == right) return 0;
    if (cache[left][right] >= 0) return cache[left][right];

    // LOG(INFO) << "left: " << left << " right:" << right;
    int ret = 0;
    for (int i = left; i < right; i++) {
      int lhs = rsum(psum, left, i);
      int rhs = rsum(psum, i + 1, right);
      if (lhs > rhs) {
        ret = max(ret, rhs + calc(svals, cache, psum, i + 1, right));
      } else if (lhs < rhs) {
        ret = max(ret, lhs + calc(svals, cache, psum, left, i));
      } else {
        ret = max(ret, rhs + max(calc(svals, cache, psum, left, i),
                                 calc(svals, cache, psum, i + 1, right)));
      }
    }
    cache[left][right] = ret;
    return ret;
  }
  int rsum(vector<int>& psum, int l, int r) {
    if (l == 0) return psum[r];
    return psum[r] - psum[l - 1];
  }
};
