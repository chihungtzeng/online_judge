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
  int maxDiff(int num) {
    vector<int> digits;
    while (num > 0) {
      digits.push_back(num % 10);
      num /= 10;
    }
    int k = digits.size();
    int from = 9, to = 9;
    for (int i = k - 1; i >= 0; i--) {
      if (digits[i] != 9) {
        from = digits[i];
        to = 9;
        break;
      }
    }
    int from2 = 9, to2 = 0;
    if (digits[k - 1] == 1) {
      for (int i = k - 2; i >= 0; i--) {
        if (digits[i] > 1) {
          from2 = digits[i];
          to2 = 0;
          break;
        }
      }
    } else {
      from2 = digits[k - 1];
      to2 = 1;
    }
    return change(digits, from, to) - change(digits, from2, to2);
  }
  int change(vector<int> digits, int from, int to) {
    for (int i = 0; i < digits.size(); i++) {
      if (digits[i] == from) digits[i] = to;
    }
    int ret = 0;
    for (int i = digits.size() - 1; i >= 0; i--) {
      ret = ret * 10 + digits[i];
    }
    //    LOG(INFO) << "from: " << from << " to " << to << " ret: " << ret;
    return ret;
  }
};
