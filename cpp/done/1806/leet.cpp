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
  int reinitializePermutation(int n) {
    int cur = 1;
    int cnt = 0;
    do {
      if (cur * 2 < n){
        cur <<= 1;
      } else {
        cur = (cur << 1) - n + 1;
      }
      cnt++;
    } while (cur != 1);
    return cnt;
  }
};
