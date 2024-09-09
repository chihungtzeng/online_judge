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
  int countRangeSum(const vector<int>& nums, int lower, int upper) {
    vector<int64_t> psum(nums.size() + 1);
    for (size_t i = 1; i <= nums.size(); i++) {
      psum[i] = psum[i - 1] + nums[i - 1];
    }
    return merge(nums, psum, 0, nums.size(), lower, upper);
  }
  int merge(const vector<int>& nums, vector<int64_t>& psum, const int start,
            const int end, const int lower, const int upper) {
    if (start >= end) {
      return 0;
    }
    const int mid = start + (end - start) / 2;
    int cnt = merge(nums, psum, start, mid, lower, upper) +
              merge(nums, psum, mid + 1, end, lower, upper);
    int ell = mid + 1, u = mid + 1;
    for (int i = start; i <= mid; i++) {
      while (ell <= end && psum[ell] - psum[i] < lower) ell++;
      while (u <= end && psum[u] - psum[i] <= upper) u++;
      cnt += u - ell;
    }
    merge_psum(psum, start, end);
    return cnt;
  }
  void merge_psum(vector<int64_t>& psum, const int start, const int end) {
    const int mid = start + (end - start) / 2;
    int i = start, j = mid + 1, cur = 0;
    vector<int> temp(end - start + 1);
    while (i <= mid && j <= end) {
      if (psum[i] <= psum[j]) {
        temp[cur++] = psum[i++];
      } else {
        temp[cur++] = psum[j++];
      }
    }
    while (i <= mid) {
      temp[cur++] = psum[i++];
    }
    while (j <= end) {
      temp[cur++] = psum[j++];
    }
    std::copy(temp.begin(), temp.end(), psum.begin() + start);
  }
};
