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
  int m, n;
  const vector<int> dx{-1, 1, 0, 0, 0}, dy{0, 0, -1, 1, 0};
  int minFlips(vector<vector<int>>& mat) {
    m = mat.size();
    n = mat[0].size();
    vector<int> dist(1024, -1);
    int cur = encode(mat);
    if (cur == 0) return 0;

    deque<int> q;
    q.push_back(cur);
    dist[cur] = 0;
    while (!q.empty()) {
      cur = q.front();
      q.pop_front();
      for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
          auto next = flip(cur, r, c);
          if (next == 0) return dist[cur] + 1;
          if (dist[next] < 0) {
            dist[next] = dist[cur] + 1;
            q.push_back(next);
          }
        }
      }
    }
    return -1;
  }
  int encode(vector<vector<int>>& mat) {
    int ret = 0;
    for (int r = 0; r < m; r++) {
      for (int c = 0; c < n; c++) {
        ret |= (mat[r][c] << (r * n + c));
      }
    }
    return ret;
  }
  int flip(int mat, int r, int c) {
    for (int i = 0; i < 5; i++) {
      int nr = r + dx[i];
      int nc = c + dy[i];
      if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
      mat ^= (1 << (nr * n + nc));
    }
    return mat;
  }
};
