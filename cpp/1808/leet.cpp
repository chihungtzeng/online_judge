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

constexpr int base = 1e9 + 7;
class Solution {
 public:
  int maxNiceDivisors(int primeFactors) {
    int left = 1, right = primeFactors;
    int best = -1;
    while (left <= right) {
      int mid = (right - left) / 2 + left;
      double partion_of_mid = log_of_partition(primeFactors, mid);
      double partion_of_mid_1 = log_of_partition(primeFactors, mid - 1);
      double partion_of_mid_plus1 = log_of_partition(primeFactors, mid + 1);
      if (partion_of_mid >= partion_of_mid_1 &&
          partion_of_mid >= partion_of_mid_plus1) {
        best = mid;
        break;
      } else if (partion_of_mid >= partion_of_mid_1 &&
                 partion_of_mid < partion_of_mid_plus1) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
      best = left + 1;
    }
    // LOG(INFO) << "best number of partitions: " << best;
    int avg = primeFactors / best;
    int nmore = primeFactors - avg * best;
    int64_t ans = 1;
    for (int i = 0; i < nmore; i++) {
      ans = (ans * (avg + 1)) % base;
    }
    for (int i = best - nmore; i > 0; i--) {
      ans = (ans * avg) % base;
    }
    return ans;
  }

  double log_of_partition(int primeFactors, int x) {
    if (primeFactors < x) {
      return -1;
    }
    if (primeFactors == x) {
      return 0;
    }
    return x * (log(primeFactors) - log(x));
  }
};
