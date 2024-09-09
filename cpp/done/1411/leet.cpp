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
  int numOfWays(int n) {
    const int base = 1e9 + 7;
    int s = 6, t = 6, ns = 0, nt = 0;
    for (int i = 2; i <= n; i++) {
      ns = (((s + t) % base) << 1) % base;
      nt = (ns + t) % base;
      s = ns;
      t = nt;
    }
    return (s + t) % base;
  }
};
