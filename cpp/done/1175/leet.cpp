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

const uint64_t base = 1e9 + 7;
const vector<int> primes{2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                         43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
class Solution {
 public:
  int numPrimeArrangements(int n) {
    auto it = lower_bound(primes.begin(), primes.end(), n);
    int nprimes = it - primes.begin();
    if (it != primes.end() && n == *it) nprimes++;
    uint64_t ans = 1;
    for (int i = nprimes; i >= 1; i--) {
      ans *= i;
      ans %= base;
    }
    for (int i = n - nprimes; i >= 1; i--) {
      ans *= i;
      ans %= base;
    }
    return ans;
  }
};
