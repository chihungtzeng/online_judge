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
  int countLargestGroup(int n) {
    vector<int> gsize(9 * 4 + 1);
    for (int i = 1; i <= n; i++) {
      gsize[calc_gid(i)]++;
    }
    int max_size = *max_element(gsize.begin(), gsize.end());
    int ans = 0;
    for (int i = gsize.size() - 1; i >= 0; i--) {
      if (gsize[i] == max_size) ans++;
    }
    return ans;
  }
  int calc_gid(int n) {
    int ret = 0;
    while (n >= 10) {
      ret += n % 10;
      n = n / 10;
    }
    ret += n;
    return ret;
  }
};

