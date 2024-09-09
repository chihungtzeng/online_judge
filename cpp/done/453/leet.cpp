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
  int minMoves(const vector<int>& nums) {
    int target = *min_element(nums.begin(), nums.end());
    int total = 0;
    for (auto n : nums) {
      total += n - target;
    }
    return total;
  }
};
