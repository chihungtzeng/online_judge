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

constexpr int intro = 1;
constexpr int extro = 2;
class Solution {
 public:
  int m_, n_, mn_;
  const vector<int> dx{0, 0, 1, -1}, dy{1, -1, 0, 0};
  int getMaxGridHappiness(int m, int n, int intros, int extros) {
    m_ = m;
    n_ = n;
    mn_ = m * n;
    vector<int> row(mn_);

    return dfs(row, 0, intros, extros);
  }
  int dfs(vector<int>& row, const int pos, const int intros, const int extros) {
    if (intros == 0 && extros == 0) {
      return calc_happiness(row);
    }
    if (pos == mn_) {
      return calc_happiness(row);
    }
    int ans = dfs(row, pos + 1, intros, extros);
    if (intros > 0) {
      row[pos] = intro;
      ans = max(ans, dfs(row, pos + 1, intros - 1, extros));
      row[pos] = 0;
    }
    if (extros > 0) {
      row[pos] = extro;
      ans = max(ans, dfs(row, pos + 1, intros, extros - 1));
      row[pos] = 0;
    }
    return ans;
  }
  int calc_happiness(vector<int>& row) {
    vector<vector<int>> grid(m_, vector<int>(n_));
    int pos = 0;
    for (int i = 0; i < m_; i++) {
      for (int j = 0; j < n_; j++) {
        grid[i][j] = row[pos];
        pos++;
      }
    }
    int ret = 0;
    for (int r = 0; r < m_; r++) {
      for (int c = 0; c < n_; c++) {
        if (grid[r][c] == 0) continue;

        int nbr = 0;
        for (int i = 0; i < 4; i++) {
          int nr = r + dx[i];
          int nc = c + dy[i];
          if (nr < 0 || nr >= m_ || nc < 0 || nc >= n_) continue;
          if (grid[nr][nc] == 0) continue;
          nbr++;
        }

        if (grid[r][c] == intro)
          ret += 120 - 30 * nbr;
        else
          ret += 40 + 20 * nbr;
      }
    }

    return ret;
  }
};
