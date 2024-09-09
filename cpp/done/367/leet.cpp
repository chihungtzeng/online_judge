#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
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
  bool isPerfectSquare(int num) {
    bool done = false;
    int i = 0;
    int64_t s = 0;
    int64_t ub = (1ll << 31);
    while(!done){
//      LOG(INFO) << i << ": " << s;
      if (s == num){
        return true;
      }
      s = s + (i<<1) + 1;
      i++;
      if (s >= ub) {
        done = true;
      }
    }
    return false;
  }
};
