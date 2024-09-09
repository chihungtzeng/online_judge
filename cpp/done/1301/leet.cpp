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

using ipair = pair<int, int>;
constexpr int base = 1e9 + 7;
class Solution {
 public:
  const vector<int> dx = {0, 1, 1}, dy = {1, 0, 1};
  vector<int> pathsWithMaxScore(vector<string>& board) {
    const int n = board.size();
    vector<vector<ipair>> ans(n, vector<ipair>(n, {INT_MIN, 0}));
    ans[n - 1][n - 1] = {0, 1};
    ans[0][0] = {INT_MIN, 0};
    for (int r = n - 1; r >= 0; r--) {
      for (int c = n - 1; c >= 0; c--) {
        if (board[r][c] == 'X' || board[r][c] == 'S') continue;
        for (int i = 0; i < 3; i++) {
          int nr = r + dx[i];
          int nc = c + dy[i];
          if (nr >= n || nc >= n) continue;
          if (ans[nr][nc].first == INT_MIN) continue;

          if (ans[r][c].first < ans[nr][nc].first) {
            ans[r][c] = {ans[nr][nc].first, ans[nr][nc].second};
          } else if (ans[r][c].first == ans[nr][nc].first) {
            ans[r][c].second += ans[nr][nc].second;
          }
        }
        if (ans[r][c].first != INT_MIN) {
          int inc = 0;
          if (r || c) {
            inc = board[r][c] - '0';
          }
          ans[r][c].first += inc;
          ans[r][c].second = ans[r][c].second % base;
        }
      }
      // LOG(INFO) << "row " << r << ": " << ans[r];
    }
    if (ans[0][0].first == INT_MIN) {
      return vector<int>{0, 0};
    } else
      return vector<int>{ans[0][0].first, ans[0][0].second};
  }
};
