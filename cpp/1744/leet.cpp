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
  vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
    const int n = candiesCount.size();
    vector<int64_t> psum(n);
    psum[0] = candiesCount[0];
    for (int i = 1; i < n; i++) {
      psum[i] = psum[i - 1] + candiesCount[i];
    }
    const int m = queries.size();
    vector<bool> ans(m);
    for (int i = 0; i < m; i++) {
      int t = queries[i][0];
      int day = queries[i][1];
      int cap = queries[i][2];
      if (t == 0) {
        ans[i] = bool(day < psum[0]);
      } else {
        ans[i] = bool((day >= psum[t - 1] / cap) && day <= psum[t] - 1);
      }
    }
    return ans;
  }
};

