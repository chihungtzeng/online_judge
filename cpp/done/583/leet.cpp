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
  int minDistance(string s1, string s2) {
    if (s1.size() > s2.size()) {
      swap(s1, s2);
    }
    if (s1.size() == 0) {
      return s2.size();
    }
    vector<int> prev(s1.size()), cur(s1.size());
    for (int i = 0; i < s2.size(); i++) {
      if (s1[0] == s2[i]) {
        cur[0] = 1;
      } else {
        cur[0] = prev[0];
      }

      for (int j = 1; j < s1.size(); j++) {
        if (s1[j] == s2[i]) {
          cur[j] = 1 + prev[j - 1];
        } else {
          cur[j] = max(cur[j - 1], prev[j]);
        }
      }
      //LOG(INFO) << cur;
      swap(cur, prev);
    }
    //LOG(INFO) << "LCS: " << prev.back();
    return s1.size() + s2.size() - prev.back() * 2;
  }
};
