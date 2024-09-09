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
  int maxHeight(vector<vector<int>>& cuboids) {
    for (auto& cube : cuboids) {
      sort(cube.begin(), cube.end());
    }
    sort(cuboids.begin(), cuboids.end());
    const int n = cuboids.size();
    vector<int> dp(n);
    dp[n - 1] = cuboids[n - 1][2];
    int ans = dp[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      for (int j = n - 1; j > i; j--) {
        if (can_stack(cuboids[j], cuboids[i])) {
          dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
        } else {
          dp[i] = max(dp[i], cuboids[i][2]);
        }
      }
      ans = max(dp[i], ans);
    }
    return ans;
  }
  bool can_stack(vector<int>& bottom, vector<int>& top) {
    for (int i = 0; i < 3; i++) {
      if (bottom[i] < top[i]) return false;
    }
    return true;
  }
};
