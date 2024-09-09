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
  int findComplement(int num) {
    int c = ~num;
    int ret = 0;
    for (int i = 0; num > 0; i++, num = num >> 1) {
      ret = ret | (((c >> i) & 1) << i);
    }
    return ret;
  }
};
