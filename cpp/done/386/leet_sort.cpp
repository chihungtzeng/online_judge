#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int split_digits(int n, int *digits) {
  int i = 0;
  while (n > 0) {
    digits[i++] = n % 10;
    n = n / 10;
  }
  return i;
}

class Solution {
 public:
  vector<int> lexicalOrder(int n) {
    vector<int> nums(n);
    for (int i = 0, j = 1; i < n; i = j, j++) {
      nums[i] = j;
    }
    auto cmp = [](const int a, const int b) {
      int ad[8], bd[8];
      auto nad = split_digits(a, ad) - 1;
      auto bad = split_digits(b, bd) - 1;
      while (nad >= 0 and bad >= 0) {
        if (ad[nad] != bd[bad]) {
          if (ad[nad] < bd[bad]) {
            return true;
          }
          return false;
        }
        nad--;
        bad--;
      }
      if (bad >= 0){
        return true;
      }
      return false;
    };
    sort(nums.begin(), nums.end(), cmp);
    return nums;
  }
};
