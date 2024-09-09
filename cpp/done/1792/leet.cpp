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

using ppair = pair<double, int>;
class Solution {
 public:
  double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    vector<ppair> pairs;
    const int n = classes.size();
    pairs.reserve(n);
    for (int i = 0; i < n; i++) {
      double cur_ratio = double(classes[i][0]) / classes[i][1];
      double expect_gain =
          double(classes[i][0] + 1) / (classes[i][1] + 1) - cur_ratio;
      pairs.emplace_back(ppair{expect_gain, i});
    }
    priority_queue<ppair> q{pairs.begin(), pairs.end()};
    for (int i = 0; i < extraStudents; i++) {
      auto [ratio, cid] = q.top();
      //      LOG(INFO) << "assign student -- ratio: " << ratio << " cid: " <<
      //      cid;
      q.pop();
      classes[cid][0]++;
      classes[cid][1]++;
      double cur_ratio = double(classes[cid][0]) / classes[cid][1];
      double expect_gain =
          double(classes[cid][0] + 1) / (classes[cid][1] + 1) - cur_ratio;
      q.push(ppair{expect_gain, cid});
    }
    double ans = 0;
    for (auto& c : classes) {
      ans += double(c[0]) / c[1];
    }
    ans /= n;
    //    LOG(INFO) << "ans=" << ans;
    return ans;
  }
};
