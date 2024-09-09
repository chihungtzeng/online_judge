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
  int countBalls(int lowLimit, int highLimit) {
    vector<int> boxes(46);
    for (int i = lowLimit; i <= highLimit; i++) {
      boxes[box_id(i)]++;
    }
    return *max_element(boxes.begin(), boxes.end());
  }
  int box_id(int ball) {
    int ret = 0;
    while (ball > 0) {
      ret += ball % 10;
      ball /= 10;
    }
    return ret;
  }
};
