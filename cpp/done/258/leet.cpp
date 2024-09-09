#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int addDigits(int num) {
    while (num >= 10) {
      num = sum_digits(num);
    }
    return num;
  }
  int sum_digits(int num) {
    int ret = 0;
    while (num > 0) {
      ret += num % 10;
      num /= 10;
    }
    return ret;
  }
};
