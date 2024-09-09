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
  int tupleSameProduct(vector<int>& nums) {
    unordered_map<int, int> cnt;
    const int n = nums.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        cnt[nums[i] * nums[j]] += 1;
      }
    }
    int ret = 0;
    for (auto& [_, count] : cnt) {
      if (count > 1) {
        ret += ((count - 1) * count) >> 1;
      }
    }
    return ret << 3;
  }
};
