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
  int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
    int ans = 0;
    int start_pos = 0, last_valid_pos = -1;
    for (int i = 0; i < A.size(); i++) {
      if (A[i] > R) {
        start_pos = i + 1;
        last_valid_pos = -1;
      } else {
        if (L <= A[i] && A[i] <= R) {
          last_valid_pos = i;
        }
        if (last_valid_pos >= 0) {
          ans += last_valid_pos - start_pos + 1;
        }
      }
    }
    return ans;
  }
};
