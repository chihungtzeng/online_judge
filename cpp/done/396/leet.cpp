#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxRotateFunction(vector<int>& A) {
    int64_t sum = accumulate(A.begin(), A.end(), 0ll);
    int64_t f0 = 0;
    int64_t ssize = A.size();
    for (int i = 1; i < ssize; i++) {
      f0 += i * A[i];
    }
    int64_t ans = f0;
    for (int i = 0; i < ssize; i++) {
      // LOG(INFO) << f0;
      int64_t f1 = f0 - sum + A[i] * ssize;
      f0 = f1;
      ans = max(ans, f0);
    }
    return static_cast<int>(ans);
  }
};
