#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

int guess(int num);
class Solution {
 public:
  int guessNumber(int n) {
    int low = 1, high = n;
    while (low <= high) {
      auto mid = low + (high - low) / 2;
      auto ret = guess(mid);
      if (ret == 0) {
        return mid;
      } else if (ret > 0) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return low;
  }
};
