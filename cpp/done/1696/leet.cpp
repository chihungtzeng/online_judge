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

using ipair = pair<int, int>;
class Solution {
 public:
  int maxResult(vector<int>& nums, int k) {
    multiset<ipair> ms;
    const int n = nums.size();
    vector<int> scores(n, INT_MIN);
    scores[0] = nums[0];
    ms.insert({nums[0], 0});

    for (int i = 1; i < n; i++) {
      auto [biggest, idx] = *ms.rbegin();
      scores[i] = nums[i] + scores[idx];
      if (i - k >= 0) {
        int j = i - k;
        auto it = ms.find({scores[j], j});
        ms.erase(it);
      }
      ms.insert({scores[i], i});
    }
    // LOG(INFO) << scores;
    return scores.back();
  }
};
