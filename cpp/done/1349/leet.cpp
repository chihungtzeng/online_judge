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
  int rows, cols;
  int maxStudents(vector<vector<char>>& seats) {
    uint64_t seats64 = 0;
    rows = seats.size();
    cols = seats[0].size();
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        uint32_t pos = bit_pos(i, j);
        if (seats[i][j] == '#') seats64 |= (1ull << pos);
      }
    }

    unordered_map<uint64_t, int> cache;
    return dfs(seats64, 0, 0, cache);
  }

  uint64_t bit_pos(int r, int c) { return r * cols + c; }

  int dfs(uint64_t s64, int r, int c, unordered_map<uint64_t, int>& cache) {
    auto it = cache.find(s64);
    if (it != cache.end()) {
      return it->second;
    }

    auto [er, ec] = next_empty(s64, r, c);
    if (er < 0) {
      return 0;
    }

    s64 |= (1ull << bit_pos(er, ec));
    int ans1 = dfs(s64, er, ec, cache);
    vector<int> blocked_seats;
    const vector<ipair> redzones{{0, -1}, {0, 1}, {1, -1}, {1, 1}};
    for (auto& [dr, dc] : redzones) {
      int nr = er + dr, nc = ec + dc;
      if (0 <= nr && nr < rows && 0 <= nc && nc < cols) {
        uint64_t pos = bit_pos(nr, nc);
        if (((s64 >> pos) & 1) == 0) {
          s64 |= (1ull << pos);
          blocked_seats.push_back(pos);
        }
      }
    }
    int ans2 = 1 + dfs(s64, er, ec, cache);
    s64 ^= (1ull << bit_pos(er, ec));
    for (auto pos : blocked_seats) {
      s64 ^= (1ull << pos);
    }
    int best = max(ans1, ans2);
    cache[s64] = best;
    return best;
  }

  ipair next_empty(uint64_t s64, int r, int c) {
    for (int j = c; j < cols; j++) {
      if (0 == ((s64 >> bit_pos(r, j)) & 1)) return {r, j};
    }
    for (int i = r + 1; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (0 == ((s64 >> bit_pos(i, j)) & 1)) return {i, j};
      }
    }
    return {-1, -1};
  }
};
