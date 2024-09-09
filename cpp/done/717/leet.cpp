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
  bool isOneBitCharacter(vector<int>& bits) {
    if (bits.size() == 1) return true;
    int index = 0;
    while (index < bits.size()) {
      if (bits[index] == 1)
        index += 2;
      else
        index += 1;

      if (index == bits.size() - 1) return true;
    }
    return false;
  }
};
