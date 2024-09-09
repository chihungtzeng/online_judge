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

class Solution {
 public:
  int chalkReplacer(vector<int>& chalk, int k) {
    const int n = chalk.size();
    vector<int64_t> psum(n, 0);
    psum[0] = chalk[0];
    for (int i = 1; i < n; i++) {
      psum[i] = psum[i - 1] + chalk[i];
    }
    k = k % psum.back();
    auto it = upper_bound(psum.begin(), psum.end(), k);
    return it - psum.begin();
  }
};
