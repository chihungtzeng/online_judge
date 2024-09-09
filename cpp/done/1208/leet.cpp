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
  int equalSubstring(string s, string t, int maxCost) {
    vector<int> cost(s.size());
    const int n = s.size();
    for (int i = 0; i < n; i++) {
      cost[i] = abs(s[i] - t[i]);
    }
    int i = 0, j = 0;
    int cur = 0;
    int ans = 0;
    for (; j < n; j++) {
      cur += cost[j];
      while (i < n && cur > maxCost) {
        cur -= cost[i];
        i++;
      }

      ans = max(ans, j - i + 1);
    }
    return ans;
  }
};
