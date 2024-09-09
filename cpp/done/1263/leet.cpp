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
#define DEBUG 0

using ipair = pair<int, int>;
using rc_pair = pair<int8_t, int8_t>;
using pos_tuple = tuple<int8_t, int8_t, int8_t, int8_t>;

class Solution {
 public:
  int8_t m, n;
  vector<vector<int8_t>> offset{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  int encode_pos(int8_t pr, int8_t pc, int8_t br, int8_t bc) {
    return (pr << 24) | (pc << 16) | (br << 8) | bc;
  }

  pos_tuple decode_pos(int pos) {
    return pos_tuple{pos >> 24, (pos >> 16) & 0xff, (pos >> 8) & 0xff,
                     pos & 0xff};
  }

  bool oob(int8_t r, int8_t c) {
    // Out of bound
    return (r < 0 || r >= m || c < 0 || c >= n);
  }

  bool person_can_reach(vector<vector<char>>& grid, int pos, int dest_r,
                        int8_t dest_c) {
    if (oob(dest_r, dest_c)) return false;
    if (grid[dest_r][dest_c] == '#') return false;
    auto [pr, pc, br, bc] = decode_pos(pos);
    if (pr == dest_r && pc == dest_c) return true;

    vector<vector<bool>> vis(m, vector<bool>(n, false));

    deque<rc_pair> q;
    vis[pr][pc] = true;
    q.emplace_back(pr, pc);
    while (!q.empty()) {
      auto [cur_r, cur_c] = q.front();
      q.pop_front();
      for (int8_t i = 0; i < 4; i++) {
        int8_t nr = cur_r + offset[i][0];
        int8_t nc = cur_c + offset[i][1];
        if (oob(nr, nc)) continue;
        if (grid[nr][nc] == '#') continue;
        if (nr == br && nc == bc) continue;
        if (nr == dest_r && nc == dest_c) return true;

        if (!vis[nr][nc]) {
          vis[nr][nc] = true;
          q.emplace_back(nr, nc);
        }
      }
    }
    return false;
  }

  int minPushBox(vector<vector<char>>& grid) {
    m = grid.size();
    n = grid[0].size();
    vector<vector<vector<int8_t>>> dist(
        m, vector<vector<int8_t>>(n, vector<int8_t>(5, SCHAR_MAX)));
    // row and column for person, box and target, respectively.
    int8_t pr = 0, pc = 0, br = 0, bc = 0, tr = 0, tc = 0;
    for (int8_t r = 0; r < m; r++) {
      for (int8_t c = 0; c < n; c++) {
        if (grid[r][c] == '#') continue;
        if (grid[r][c] == 'T') {
          tr = r;
          tc = c;
        } else if (grid[r][c] == 'S') {
          pr = r;
          pc = c;
        } else if (grid[r][c] == 'B') {
          br = r;
          bc = c;
        }
      }
    }

    for (int i = 0; i < 5; i++) {
      dist[br][bc][i] = 0;
    }
    deque<int> q;
    q.push_back(encode_pos(pr, pc, br, bc));

    while (!q.empty()) {
      int pos = q.front();
      q.pop_front();
      auto [pr, pc, br, bc] = decode_pos(pos);
      int8_t cur_dist = dist[br][bc].back();

      for (int i = 0; i < 4; i++) {
        int next_br = br + offset[i][0];
        int next_bc = bc + offset[i][1];
        if (oob(next_br, next_bc)) continue;
        if (grid[next_br][next_bc] == '#') continue;
        int expect_pr = br - offset[i][0];
        int expect_pc = bc - offset[i][1];
        if (oob(expect_pr, expect_pc)) continue;
        if (grid[expect_pr][expect_pc] == '#') continue;
        if (!person_can_reach(grid, pos, expect_pr, expect_pc)) continue;

#if DEBUG
        LOG(INFO) << "box: " << ipair{br, bc}
                  << ", next box pos: " << ipair{next_br, next_bc}
                  << ", person can move from " << ipair{pr, pc} << " to "
                  << ipair{expect_pr, expect_pc};
#endif
        if (next_br == tr && next_bc == tc) {
          return cur_dist + 1;
        }
        if (dist[next_br][next_bc][i] == SCHAR_MAX) {
          dist[next_br][next_bc][i] = cur_dist + 1;
          dist[next_br][next_bc][4] = cur_dist + 1;
          q.push_back(encode_pos(br, bc, next_br, next_bc));
        }
      }
    }
    return -1;
    /*
        for(int i=0; i<4; i++){
          LOG(INFO) << dist[3][4][i] + 0;
        }
        int ans = *min_element(dist[tr][tc].begin(), dist[tr][tc].end());
        if (ans == SCHAR_MAX) return -1;
        return ans;
    */
  }
};
