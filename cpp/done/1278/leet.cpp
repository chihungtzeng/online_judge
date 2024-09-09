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
  int n;
  int palindromePartition(string s, int k) {
    n = s.size();
    if (n == k) return 0;
    vector<vector<int>> min_change(n, vector<int>(n, -1));
    vector<vector<int>> cache(n, vector<int>(k + 1, -1));
    return dfs(s, k, 0, min_change, cache);
  }
  int get_min_change(string& s, vector<vector<int>>& min_change, int i, int j) {
    if (i >= j) return 0;
    if (min_change[i][j] >= 0) return min_change[i][j];
    min_change[i][j] = get_min_change(s, min_change, i + 1, j - 1);
    if (s[i] != s[j]) {
      min_change[i][j]++;
    }
    return min_change[i][j];
  }
  int dfs(string& s, int k, int si, vector<vector<int>>& min_change,
          vector<vector<int>>& cache) {
    if (si == n) {
      if (k > 0) return n + 1;
      return 0;
    }
    if (si < n && k == 0) return n + 1;
    if (cache[si][k] >= 0) return cache[si][k];

    int ans = INT_MAX;
    for (int j = si; j < n; j++) {
      ans = min(ans, get_min_change(s, min_change, si, j) + dfs(s, k-1, j+1, min_change, cache));
    }
    cache[si][k] = ans;
    return ans;
  }
};
