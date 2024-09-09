#include <algorithm>
#include <cstdint>
#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void radix_sort(std::vector<int> &nums) {
  auto max_elem = *max_element(nums.begin(), nums.end());
  auto nelem = nums.size();
  int base = 1;
  std::vector<int> digits[10];
  for (int i = 0; i < 10; i++) {
    digits[i].reserve(nelem / 10);
  }
  while (base <= max_elem) {
    for (int i = 0; i < 10; i++) {
      digits[i].clear();
    }

    for (auto val : nums) {
      digits[(val / base) % 10].push_back(val);
    }
    int cur = 0;
    for (int i = 0; i < 10; i++) {
      for (auto val : digits[i]) {
        nums[cur++] = val;
      }
    }
    base = base * 10;
  }
}

class Solution {
public:
  int maximumGap(vector<int> &nums) {
    size_t nelem = nums.size();
    if (nelem <= 1)
    {
      return 0;
    }
    int ret = 0;
    radix_sort(nums);
    for (size_t i = 1; i < nelem; i++) {
      ret = max(ret, nums[i] - nums[i - 1]);
    }

    return ret;
  }
};
