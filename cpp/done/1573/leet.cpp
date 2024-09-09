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
  int numWays(string s) {
    vector<int> psum(s.size());
    const int base = 1e9 + 7;
    psum[0] = s[0] - '0';
    for (int i = 1; i < s.size(); i++) {
      psum[i] = psum[i - 1] + s[i] - '0';
    }
    //  LOG(INFO) << psum.back();
    if (psum.back() % 3 != 0) return 0;
    if (psum.back() == 0) {
      const int64_t n = s.size();
      int64_t sum = (n - 2) * (n - 1) / 2;
      return sum % base;
    }
    int l =
        lower_bound(psum.begin(), psum.end(), psum.back() / 3) - psum.begin();
    int r = lower_bound(psum.begin(), psum.end(), 1 + psum.back() * 2 / 3) -
            psum.begin();
    //    LOG(INFO) << "l:" << l << " r:" << r;
    int64_t nz1 = 0, nz2 = 0;
    l++;
    while (s[l++] == '0') nz1++;
    r--;
    while (s[r--] == '0') nz2++;
    int64_t sum = (nz1 + 1) * (nz2 + 1);
    return sum % base;
  }
};
