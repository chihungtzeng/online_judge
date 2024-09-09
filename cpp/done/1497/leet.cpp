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
  bool canArrange(vector<int>& arr, int k) {
    vector<int> remains(k);
    for (auto v : arr) {
      remains[remain_of(v, k)]++;
    }
    if (remains[0] % 2 != 0) return false;
    if (k % 2 == 0 && remains[k / 2] % 2 != 0) return false;
    int l = 1;
    int r = k - 1;
    while (l < r) {
      if (remains[l] != remains[r]) return false;
      l++;
      r--;
    }
    return true;
  }
  int remain_of(int n, const int k) {
    if (n < 0) {
      n += (-n / k + 1) * k;
    }
    return n % k;
  }
};
