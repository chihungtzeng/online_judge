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
  int longestAwesome(string s) {
    vector<int> pos(1024, -10);
    int mask = 0, res = 0;
    pos[0] = -1;
    for (int i = 0; i < s.size(); i++) {
      mask ^= 1 << (s[i] - '0');
      if (pos[mask] == -10) {
        pos[mask] = i;
      } else {
        res = max(res, i - pos[mask]);
      }

      for (int k = 0; k < 10; k++) {
        auto temp = mask ^ (1 << k);
        if (pos[temp] != -10) {
          res = max(res, i - pos[temp]);
        }
      }
    }
    return res;
  }
};
