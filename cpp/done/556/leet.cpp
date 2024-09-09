#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
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
  int nextGreaterElement(int n) {
    int temp = n;
    if (n <= 10) {
      return -1;
    }
    vector<int> digits;
    while (temp > 0) {
      digits.push_back(temp % 10);
      temp /= 10;
    }
    reverse(digits.begin(), digits.end());
    // LOG(INFO) << digits;
    next_permutation(digits);
    // LOG(INFO) << digits;
    uint64_t ret = 0;
    for (int i = 0; i < digits.size(); i++) {
      ret = ret * 10 + digits[i];
    }
    if (ret == n || ret > 0x7fffffff) {
      return -1;
    } else {
      return ret;
    }
  }
  void next_permutation(vector<int>& digits) {
    for (int i = digits.size() - 1; i >= 1; i--) {
      if (digits[i] > digits[i - 1]) {
        int k = digits.size() - 1;
        while (digits[k] <= digits[i - 1]) k--;
        swap(digits[k], digits[i - 1]);
        reverse(digits.begin() + i, digits.end());
        return;
      }
    }
  }
};
