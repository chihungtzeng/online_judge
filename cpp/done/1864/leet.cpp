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
  int minSwaps(string s) {
    int n0 = 0, n1 = 0;
    for (auto ch : s) {
      if (ch == '0')
        n0++;
      else
        n1++;
    }
    if (abs(n0 - n1) >= 2) return -1;

    auto cans = find_candidates(n0, n1);
    int ans = INT_MAX;
    for (auto& can : cans) {
      int diff = 0;
      for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] != can[i]) {
          diff++;
        }
      }
      ans = min(ans, diff >> 1);
    }
    return ans;
  }
  vector<string> find_candidates(int n0, int n1) {
    if (n0 == n1) {
      return vector<string>{builds(0, n0 + n1), builds(1, n0 + n1)};
    } else if (n0 == n1 + 1) {
      return vector<string>{builds(0, n0 + n1)};
    } else {
      return vector<string>{builds(1, n0 + n1)};
    }
  }
  string builds(int start, int len) {
    string s;
    for (int i = 0; i < len; i++) {
      s.push_back(start + '0');
      start = 1 - start;
    }
    return s;
  }
};
