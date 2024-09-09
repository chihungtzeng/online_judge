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

int v2i(vector<int>& digits) {
  int ret = 0;
  for (auto v : digits) {
    ret = (ret << 3) + (ret << 1) + v;
  }
  return ret;
}

vector<int> find_digits(int k) {
  vector<int> digits(k);
  vector<int> ret;
  for (int i = 0; i < k; i++) {
    digits[i] = i + 1;
  }
  ret.push_back(v2i(digits));
  bool done = false;
  for (int i = 0; i < 10 && !done; i++) {
    for (int j = 0; j < k && !done; j++) {
      digits[j]++;
      if (digits[j] == 10) done = true;
    }
    if (!done) {
      ret.push_back(v2i(digits));
    }
  }
  return ret;
}

vector<int> get_all_candidates() {
  vector<int> cans;
  for (int i = 2; i <= 8; i++) {
    for (auto v : find_digits(i)) {
      cans.push_back(v);
    }
  }
  cans.push_back(123456789);
  return cans;
}

class Solution {
 public:
  vector<int> sequentialDigits(int low, int high) {
    auto cans = get_all_candidates();
    auto it_start = lower_bound(cans.begin(), cans.end(), low);
    auto it_end = upper_bound(cans.begin(), cans.end(), high);
    return vector<int>{it_start, it_end};
  }
};
