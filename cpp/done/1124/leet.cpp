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
  int longestWPI(vector<int>& hours) {
    const int n = hours.size();
    for (int i = 0; i < n; i++) {
      hours[i] = (hours[i] > 8) ? 1 : -1;
    }
    for (int i = 1; i < n; i++) {
      hours[i] += hours[i - 1];
    }
    int ans = 0;
    map<int, int> lookup;
    for (int i = 0; i < n; i++) {
      if (hours[i] > 0) {
        ans = max(ans, i + 1);
      } else {
        auto it = lookup.find(hours[i] - 1);
        if (it != lookup.end()) {
          ans = max(ans, i - it->second);
        }
        if (lookup.find(hours[i]) == lookup.end()) {
          lookup[hours[i]] = i;
        }
      }
    }
    return ans;
  }
};
