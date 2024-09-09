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
  int minimumSwap(string s1, string s2) {
    if (s1.size() != s2.size()) return -1;
    int yx = 0, xy = 0;
    for (int i = s1.size() - 1; i >= 0; i--) {
      if (s1[i] == s2[i]) continue;
      if (s1[i] == 'x')
        xy++;
      else
        yx++;
    }
    int ans = xy / 2 + yx / 2;
    xy = xy % 2;
    yx = yx % 2;
    if (xy == 0 && yx == 0) return ans;
    if (xy == 1 && yx == 1) return ans + 2;
    return -1;
  }
};
