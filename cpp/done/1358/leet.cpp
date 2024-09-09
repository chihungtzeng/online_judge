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
  int numberOfSubstrings(string s) {
    vector<int> pos(3, -1);
    vector<pair<int, int>> target{{1, 2}, {0, 2}, {0, 1}};
    const int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int idx = s[i] - 'a';
      pos[idx] = i;
      if (pos[0] >= 0 && pos[1] >= 0 && pos[2] >= 0) {
        ans += min(pos[target[idx].first], pos[target[idx].second]) + 1;
      }
    }
    return ans;
  }
};
