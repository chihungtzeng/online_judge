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
  int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    int ret = 0;
    for (auto v : left) ret = max(ret, v);
    for (auto v : right) ret = max(ret, n - v);
    return ret;
  }
};
