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
  int dist(int a, int b) {
    if (a == 26) return 0;
    return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
  }
  int minimumDistance(string word) {
    vector<vector<vector<int>>> dp(
        27, vector<vector<int>>(27, vector<int>(word.size(), -1)));
    return helper(word, dp, 0, 26, 26);
  }
  int helper(string& word, vector<vector<vector<int>>>& dp, int pos, int left,
             int right) {
    if (pos == word.size()) return 0;
    if (dp[left][right][pos] >= 0) return dp[left][right][pos];
    int to = word[pos] - 'A';
    int ret = helper(word, dp, pos + 1, to, right) + dist(left, to);
    ret = min(ret, helper(word, dp, pos + 1, left, to) + dist(right, to));
    dp[left][right][pos] = ret;
    return ret;
  }
};
