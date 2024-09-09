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
  int findBestValue(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    const int n = arr.size();
    vector<int> psum(n);
    psum[0] = arr[0];
    for (int i = 1; i < n; i++) {
      psum[i] = psum[i - 1] + arr[i];
    }
    //LOG(INFO) << arr;
    //LOG(INFO) << psum;
    if (psum.back() <= target) return arr.back();

    int left = 0, right = arr.back();
    while (left <= right) {
      int mid = (left + right) / 2;
      int mutated_sum = mutate_and_sum(arr, psum, mid);
      //LOG(INFO) << "mutate with " << mid << " sum: " <<mutated_sum;
      if (mutated_sum == target) {
        return mid;
      } else if (mutated_sum > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    int diff = INT_MAX;
    int ans = 0;
    for (int i = left - 1; i <= left + 1; i++) {
      int can = abs(mutate_and_sum(arr, psum, i) - target);
      if (can < diff) {
        diff = can;
        ans = i;
      }
    }
    return ans;
  }

  int mutate_and_sum(vector<int>& arr, vector<int>& psum, int val) {
    int idx = upper_bound(arr.begin(), arr.end(), val) - arr.begin();
    //LOG(INFO) << "mutate with val " << val << " pos starts with " << idx;
    return range_sum(psum, 0, idx - 1) + (psum.size() - idx) * val;
  }
  int range_sum(vector<int>& psum, int from, int to) {
    if (to < 0) return 0;
    if (from == 0)
      return psum[to];
    else
      return psum[to] - psum[from - 1];
  }
};
