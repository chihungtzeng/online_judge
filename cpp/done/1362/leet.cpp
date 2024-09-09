#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
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
  vector<int> closestDivisors(int n) {
    if (n == 1) return vector<int>{1, 2};
    int n_2 = n + 2;
    int s = sqrt(n + 2);
    while (s) {
      int d = n_2 / s;
      int m = s * d;
      if (m == n + 1 || m == n_2) {
        return vector<int>{s, d};
      }
      s--;
    }
    return vector<int>{1, n + 1};
  }
};
