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
  int scheduleCourse(vector<vector<int>> &courses) {
    auto cmp = [](const auto &a, const auto &b) { return a[1] < b[1]; };
    sort(courses.begin(), courses.end(), cmp);
    int cur_day = 0;
    priority_queue<int> pq;
    for (auto &c : courses) {
      cur_day += c[0];
      pq.push(c[0]);
      if (cur_day > c[1] && !pq.empty()) {
        cur_day -= pq.top();
        pq.pop();
      }
    }
    return pq.size();
  }
};
