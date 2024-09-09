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
#define DEBUG 1

using pos_t = int16_t;
using ipair = pair<pos_t, pos_t>;
class Solution {
 public:
  const vector<pos_t> dx{0, 0, 1, -1}, dy{1, -1, 0, 0};
  pos_t m, n;

  int minPushBox(vector<vector<char>>& grid) {
    m = grid.size();
    n = grid[0].size();
    vector<vector<pos_t>> dist(m, vector<pos_t>(n, -1));
    pos_t dest_idx = -1;
    pos_t box_idx = -1;
    pos_t src_idx = -1;
    for (pos_t r = 0; r < m; r++) {
      for (pos_t c = 0; c < n; c++) {
        if (grid[r][c] == '#') continue;
        pos_t idx = r * n + c;
        if (grid[r][c] == 'T') dest_idx = idx;
        if (grid[r][c] == 'S') src_idx = idx;
        if (grid[r][c] == 'B') box_idx = idx;
        grid[r][c] = '.';
      }
    }
    deque<ipair> q;

    dist[box_idx / n][box_idx % n] = 0;
    q.push_back({box_idx, src_idx});
    while (!q.empty()) {
      auto [box_idx, src_idx] = q.front();
      q.pop_front();
      pos_t br = box_idx / n;
      pos_t bc = box_idx % n;
      pos_t sr = src_idx / n;
      pos_t sc = src_idx % n;
#if DEBUG
      LOG(INFO) << "box: " << ipair{br, bc} << " person: " << ipair{sr, sc};
#endif
      for (pos_t i = 0; i < 4; i++) {
        pos_t nr = br + dx[i];
        pos_t nc = bc + dy[i];
        if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
        if (grid[nr][nc] == '#') continue;

        pos_t exp_sr = br - dx[i];
        pos_t exp_sc = bc - dy[i];
        if (can_reach(grid, sr, sc, exp_sr, exp_sc, br, bc)) {
#if DEBUG
          LOG(INFO) << "person can move from " << ipair{sr, sc} << " to " << ipair{exp_sr, exp_sc};
#endif
          dist[nr][nc] = dist[br][bc] + 1;
          q.push_back({nr * n + nc, box_idx});
        } else {
#if DEBUG
          LOG(INFO) << "person can't move from " << ipair{sr, sc} << " to " << ipair{exp_sr, exp_sc};
#endif
        }
      }
    }
#if DEBUG
    for(pos_t r=0; r<m; r++){
      for(auto v: dist[r]){
        printf("%2d ", v);
      }
      printf("\n");
    }
#endif
    return dist[dest_idx / n][dest_idx % n];
  }
  bool can_reach(vector<vector<char>>& grid, pos_t sr, pos_t sc, pos_t dr, pos_t dc, pos_t br, pos_t bc) {
    if (dr < 0 || dr >= m || dc < 0 || dc >= n) return false;
    if (sr < 0 || sr >= m || sc < 0 || sc >= n) return false;
    if (grid[dr][dc] == '#') return false;

    deque<pos_t> q;
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    q.push_back(sr * n + sc);
    vis[sr][sc] = true;
    while (!q.empty()) {
      pos_t cur = q.front();
      q.pop_front();
      sr = cur / n;
      sc = cur % n;
      for (pos_t i = 0; i < 4; i++) {
        pos_t nr = sr + dx[i];
        pos_t nc = sc + dy[i];
        if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
        if (grid[nr][nc] == '#') continue;
        if (nr == br && nc == bc) continue;
        if (nr == dr && nc == dc) return true;

        if (!vis[nr][nc]) {
          vis[nr][nc] = true;
          q.push_back(nr * n + nc);
        }
      }
    }
    return false;
  }
};
