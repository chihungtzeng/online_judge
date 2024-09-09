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
  unordered_map<int, int> nums;

  int numTilings(int N) {
    vector<uint64_t> nums{0, 1, 2, 5};
    for (int i = 4; i <= N; i++) {
      uint64_t cnt = 0;
      for (int j = 1; j < i; j++) {
        int k = i - j;
        cnt = (cnt + nums[j] * nums[k]) % 1000000007;
      }
      nums.push_back(cnt);
    }
    return nums[N];
  }
};
