#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int n, m;
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
    n = matrix.size();
    if (n == 0) {
      return {};
    }
    m = matrix[0].size();
    vector<vector<bool>> atlantic(n, vector<bool>(m, false)),
        pacific(n, vector<bool>(m, false)), visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) dfs(matrix, i, m - 1, visited, atlantic);
    for (int i = 0; i < m; i++) dfs(matrix, n - 1, i, visited, atlantic);

    visited = vector<vector<bool>>(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) dfs(matrix, i, 0, visited, pacific);

    for (int i = 0; i < m; i++) dfs(matrix, 0, i, visited, pacific);

    vector<vector<int>> ret;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (pacific[i][j] && atlantic[i][j]) {
          ret.push_back({i, j});
        }
      }
    }
    return ret;
  }
  void dfs(const vector<vector<int>>& matrix, const int r, const int c,
           vector<vector<bool>>& visited, vector<vector<bool>>& ocean) {
    if (r < 0 || r >= n || c < 0 || c >= m) {
      return;
    }
    visited[r][c] = true;
    ocean[r][c] = true;
    vector<pair<int, int>> nbrs{{r + 1, c}, {r - 1, c}, {r, c + 1}, {r, c - 1}};
    for (const auto& nbr : nbrs) {
      auto nr = nbr.first;
      auto nc = nbr.second;
      if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
        continue;
      }
      if (!visited[nr][nc] && matrix[nr][nc] >= matrix[r][c]) {
        dfs(matrix, nr, nc, visited, ocean);
      }
    }
  }
};
