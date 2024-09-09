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
  int findTheLongestSubstring(string s) {
    vector<uint8_t> shift(256, 0);
    shift['a'] = 1 << 0;
    shift['e'] = 1 << 1;
    shift['i'] = 1 << 2;
    shift['o'] = 1 << 3;
    shift['u'] = 1 << 4;
    vector<int> first(32, -1);
    uint16_t mask = 0;
    const int n = s.size();
    int ret = 0;
    for (int i = 0; i < n; i++) {
      mask ^= shift[s[i]];
      if (mask!=0 && first[mask] < 0)
        first[mask] = i;
      ret = max(ret, i - first[mask]);
    }
    return ret;
  }
};
