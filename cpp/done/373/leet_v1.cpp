#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

using ip = std::pair<int, int>;

class Solution {
 public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                     int k) {
    vector<vector<int>> ret;
    if (nums1.size() == 0 || nums2.size() == 0) {
      return ret;
    }
    ret.reserve(k);
    auto cmp = [&nums1, &nums2](auto& t1, auto& t2) {
      return nums1[t1.first] + nums2[t1.second] >
             nums1[t2.first] + nums2[t2.second];
    };
    std::priority_queue<ip, vector<ip>, decltype(cmp)> q(cmp);
    for (int i = 0; i < nums1.size(); i++) {
      q.push(ip{i, 0});
    }
    while ((k--) && !q.empty()) {
      auto t = q.top();
      q.pop();
      ret.emplace_back(vector<int>{nums1[t.first], nums2[t.second]});
      if (t.second < nums2.size() - 1) {
        q.push(ip{t.first, t.second + 1});
      }
    }
    return ret;
  }
};
