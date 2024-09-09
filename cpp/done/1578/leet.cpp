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
  int minCost(string s, vector<int>& cost) {
    int ans = 0;
    int i = 0;
    while (i < s.size()) {
      int j = i + 1;
      while (j < s.size() && s[j] == s[i]) j++;
      j--;
      if (i == j) {
        i++;
        continue;
      }
      int s = 0;
      for (int k = i; k <= j; k++) s += cost[k];
      s -= *max_element(cost.begin() + i, cost.begin() + j + 1);
      ans += s;
      i = j + 1;
    }
    return ans;
  }
};
