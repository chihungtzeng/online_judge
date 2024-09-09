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
  vector<int> constructDistancedSequence(int n) {
    if (n == 1) {
      return vector<int>{1};
    }
    vector<int> ans(2 * n - 1);
    vector<int> used(n + 1);
    helper(ans, used, n, 0);
    return ans;
  }
  bool helper(vector<int>& ans, vector<int>& used, int n, int pos) {
    if (pos == ans.size()) return true;

    if (ans[pos] > 0) return helper(ans, used, n, pos + 1);
    for (int val = n; val > 0; val--) {
      if (used[val]) {
        continue;
      }
      if (val > 1 && pos + val < ans.size() && ans[pos + val] != 0) {
        continue;
      }
      if (val > 1 && pos + val >= ans.size()) {
        continue;
      }
      ans[pos] = val;
      used[val] = 1;

      if (val > 1) {
        ans[pos + val] = val;
      }
      if (helper(ans, used, n, pos + 1)) {
        return true;
      }

      ans[pos] = 0;
      used[val] = 0;
      if (val > 1) {
        ans[pos + val] = 0;
      }
    }
    return false;
  }
};
