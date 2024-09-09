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
  int minNumberOperations(vector<int>& target) {
    int ret = target.back();
    for (int i = target.size() - 2; i >= 0; i--) {
      if (target[i] > target[i + 1]) {
        ret += target[i] - target[i + 1];
      }
    }
    return ret;
  }
};
