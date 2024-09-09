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

using ipair = pair<int, int>;
class Solution {
 public:
  string stoneGameIII(vector<int>& vs) {
    unordered_map<int, ipair> dp;
    auto [alice, bob] = dfs(vs, 0, dp);
    if (alice > bob)
      return "Alice";
    else if (alice == bob)
      return "Tie";
    else
      return "Bob";
  }
  ipair dfs(vector<int>& vs, int start, unordered_map<int, ipair>& dp) {
    if (start >= vs.size()) return {0, 0};
    if (dp.find(start) != dp.end()) return dp[start];
    int sum = 0, alice = INT_MIN, bob = INT_MIN;
    for (int i = 0; i < 3; i++) {
      if (start + i < vs.size()) {
        sum += vs[start + i];
        auto ret = dfs(vs, start + i + 1, dp);
        if (alice < ret.second + sum) {
          alice = ret.second + sum;
          bob = ret.first;
        }
      }
    }
    dp[start] = {alice, bob};
    return dp[start];
  }
};
