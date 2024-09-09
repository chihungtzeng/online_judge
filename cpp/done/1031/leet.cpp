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
  int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
    int n = A.size();
    vector<int> ml(n, 0), mr(n, 0), ll(n, 0), lr(n, 0), psum(n, 0);
    psum[0] = A[0];
    for (int i = 1; i < n; i++) {
      psum[i] = psum[i - 1] + A[i];
    }
    findl(ll, psum, L);
    findr(lr, psum, L);
    findl(ml, psum, M);
    findr(mr, psum, M);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, max(ml[i] + lr[i], ll[i] + mr[i]));
    }
    return ans;
  }
  void findl(vector<int>& left, vector<int>& psum, int len) {
    for (int i = len - 1; i < left.size(); i++) {
      left[i] = range_sum(psum, i - len + 1, i);
      if (i > 0) {
        left[i] = max(left[i], left[i - 1]);
      }
    }
  }
  void findr(vector<int>& right, vector<int>& psum, int len) {
    if (right.size() - len - 1 >= 0) {
      right[right.size() - len - 1] =
          range_sum(psum, right.size() - len, right.size() - 1);
    }
    for (int i = right.size() - len - 2; i >= 0; i--) {
      right[i] = range_sum(psum, i + 1, i + len);
      right[i] = max(right[i], right[i + 1]);
    }
  }
  int range_sum(vector<int>& psum, int i, int j) {
    if (i == 0) return psum[j];
    return psum[j] - psum[i - 1];
  }
};
