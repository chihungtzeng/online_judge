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
  const vector<vector<int>> rects_;
  vector<int> area_sum_;
  Solution(vector<vector<int>>& rects) : rects_(rects) {
    int prev = 0;
    area_sum_.resize(rects.size());
    for (size_t i = 0; i < rects_.size(); i++) {
      area_sum_[i] =
          (rects_[i][2] - rects_[i][0] + 1) * (rects_[i][3] - rects_[i][1] + 1) + prev;
      prev = area_sum_[i];
    }
    srand(time(NULL));
  }

  vector<int> pick() {
    int temp = rand() % area_sum_.back();
    auto i = std::upper_bound(area_sum_.begin(), area_sum_.end(), temp) -
             area_sum_.begin();
    auto x = rand() % (rects_[i][2] - rects_[i][0] + 1) + rects_[i][0];
    auto y = rand() % (rects_[i][3] - rects_[i][1] + 1) + rects_[i][1];
    return vector<int>{x, y};
  }
};
