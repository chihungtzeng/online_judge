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

using ipair = pair<int, int>;
class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int multiply = 0, add = 0;
    for (int i = 0; i < nums.size(); i++) {
      auto item = ncalls(nums[i]);
      add += item.first;
      multiply = max(multiply, item.second);
    }
    return add + multiply;
  }

  ipair ncalls(int n) {
    int add = 0, multiply = 0;
    if (n == 0) return {0, 0};
    while (n > 0) {
      if (n & 1) {
        add++;
        n -= 1;
      } else {
        multiply++;
        n = n >> 1;
      }
    }
    return {add, multiply};
  }
};
