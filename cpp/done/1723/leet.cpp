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
  int minimumTimeRequired(vector<int>& jobs, int k) {
    sort(jobs.begin(), jobs.end());
    reverse(jobs.begin(), jobs.end());
    int best = INT_MAX;
    int right = accumulate(jobs.begin(), jobs.end(), 0);
    if (k == 1) return right;
    int left = 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (can_handle(jobs, k, mid)) {
        best = mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return best;
  }
  bool can_handle(vector<int>& jobs, int k, int max_cap) {
    if (max_cap < jobs.back()) {
      return false;
    }
    vector<int> caps(k, max_cap);
    return helper(jobs, caps, k, max_cap, 0);
  }
  bool helper(vector<int>& jobs, vector<int>& caps, int k, int max_cap,
              int idx) {
    if (idx == jobs.size()) return true;
    for (int i = 0; i < k; i++) {
      if (caps[i] >= jobs[idx]) {
        caps[i] -= jobs[idx];
        if (helper(jobs, caps, k, max_cap, idx + 1)) {
          return true;
        }
        caps[i] += jobs[idx];
      }
      if (caps[i] == max_cap){
        break;
      }
    }
    return false;
  }
};
