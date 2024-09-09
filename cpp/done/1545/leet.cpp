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
  char findKthBit(int n, int k) {
    if (n == 1) return '0';
    int nbits = (1 << n) - 1;
    int half = nbits >> 1;
    if (k - 1 == half) return '1';
    if (k <= half) return findKthBit(n - 1, k);
    k = k - half - 1;
    k = half + 1 - k;
    // LOG(INFO) << "half: " << half << " k: " << k;
    return '1' - findKthBit(n - 1, k) + '0';
  }
};
