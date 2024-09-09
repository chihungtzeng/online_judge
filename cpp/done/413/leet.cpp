#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int numberOfArithmeticSlices(const vector<int>& A) {
    int n = A.size();
    if (n < 3){
      return 0;
    }
    int i = 0;
    int ret = 0;
    while (i < n) {
      auto slice_end = find_longest_slice(A, i);
      int slice_len = slice_end - i + 1;
      // LOG(INFO) << "i: " << i << " slice_end: " << slice_end;
      if (slice_len >= 3 && slice_end < A.size()) {
        ret += (slice_len - 2) * (slice_len - 1) / 2;
      }
      i = slice_end;
    }
    return ret;
  }
  int find_longest_slice(const vector<int>& A, int start) {
    if (start >= A.size() - 2) {
      return A.size();
    }
    int diff = A[start + 1] - A[start];
    if (A[start + 2] - A[start + 1] != diff) {
      return start + 1;
    }
    int end = start + 3;
    for (; end < A.size() && A[end] - A[end - 1] == diff; end++) {
    }
    return end - 1;
  }
};
