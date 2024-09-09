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

class Solution {
 public:
  int minPartitions(string s) {
    int ret = 0;
    const int sz = s.size();
    for (int i = 0; i < sz && ret < 9; i++) {
      ret = max(ret, s[i] - '0');
    }
    return ret;
  }
};
