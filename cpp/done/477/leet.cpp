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
  int totalHammingDistance(const vector<int>& nums) {
    vector<int> ones(31), zeros(31);
    for (auto val : nums) {
      for (int i = 0; i < 31; i++) {
        if (((val >> i) & 1) == 0) {
          zeros[i]++;
        } else {
          ones[i]++;
        }
      }
    }
    int total = 0;
    for (int i = 0; i < 31; i++) {
      total += ones[i] * zeros[i];
    }
    return total;
  }
};
