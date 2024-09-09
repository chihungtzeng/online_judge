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
  int findLongestChain(vector<vector<int>> &pairs) {
    auto cmp = [](auto const &a, auto const &b) {
      if (a[1] != b[1]) return a[1] < b[1];
      return a[0] < b[0];
    };
    sort(pairs.begin(), pairs.end(), cmp);
    int cur = INT_MIN;
    int ret = 0;
    for (int i = 0; i < pairs.size(); i++) {
      if (pairs[i][0] > cur) {
        cur = pairs[i][1];
        ret++;
      }
    }
    return ret;
  }
};
