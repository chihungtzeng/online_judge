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
  int minElements(vector<int>& nums, int limit, int goal) {
    int64_t sum = accumulate(nums.begin(), nums.end(), 0LL);
    int64_t diff = abs(goal - sum);
    return diff / limit + (diff % limit == 0 ? 0 : 1);
  }
};
