#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
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
  int rand10() {
    int a = 0, b = 0;
    while (a == 0) {
      auto temp = rand7();
      if (temp < 7) {
        a = (temp % 2) + 1;
      }
    }
    while (b == 0) {
      auto temp = rand7();
      if (temp <= 5) {
        b = temp;
      }
    }
    return (a - 1) * 5 + b;
  }
};
