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
  vector<vector<int>> getFactors(int n) {
    vector<vector<int>> ans;
    vector<int> can;
    dfs(n, ans, can, 2);
    return ans;
  }
  void dfs(const int n, vector<vector<int>>& ans, vector<int>& can, int start) {
    if (n == 1) {
      if (can.size() > 1) {
        ans.push_back(can);
      }
      return;
    }
    int sq = sqrt(n);
    for (int i = start; i <= sq; i++) {
      if (n % i == 0) {
        can.push_back(i);
        dfs(n / i, ans, can, i);
        can.pop_back();
      }
    }
    can.push_back(n);
    dfs(1, ans, can, start);
    can.pop_back();
  }
};
