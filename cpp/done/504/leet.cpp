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
  string convertToBase7(int num) {
    if (num == 0) return "0";
    int sign = 1;
    string digits;
    if (num < 0) {
      sign = -1;
      num = -num;
    }
    while (num > 0) {
      digits.push_back(num % 7 + '0');
      num = num / 7;
    }
    reverse(digits.begin(), digits.end());
    if (sign < 0) {
      digits.insert(0, "-");
    }
    return digits;
  }
};
