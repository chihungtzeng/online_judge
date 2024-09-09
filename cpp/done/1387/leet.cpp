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

using ipair = pair<int, int>;
class Solution {
 public:
  int getKth(int lo, int hi, int k) {
    vector<ipair> pairs;
    for (int i = lo; i <= hi; i++) {
      pairs.push_back({nsteps(i), i});
    }
    sort(pairs.begin(), pairs.end());
    return pairs[k - 1].second;
  }
  int nsteps(int n) {
    int ret = 0;
    while (n != 1) {
      if (n & 1)
        n = (n << 1) + n + 1;
      else
        n = n >> 1;
      ret++;
    }
    return ret;
  }
};
