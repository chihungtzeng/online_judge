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
  int maximumSwap(int num) {
    if (num == 0) return 0;
    vector<int> digits;
    while (num > 0) {
      digits.push_back(num % 10);
      num = num / 10;
    }

    auto sdigits = digits;
    sort(sdigits.begin(), sdigits.end());
    int pos = digits.size() - 1;
    bool done = false;
    while (pos >= 0 && !done) {
      if (digits[pos] == sdigits[pos])
        pos--;
      else
        done = true;
    }
    if (pos >= 1) {
      auto it = max_element(digits.begin(), digits.begin() + pos);
      auto target = digits.begin() + pos;
      int temp = *it;
      *it = *target;
      *target = temp;
    }

    int ret = 0;
    for (int i = digits.size() - 1; i >= 0; i--) {
      ret = (ret << 3) + (ret << 1) + digits[i];
    }
    return ret;
  }
};
