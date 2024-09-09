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
  int slidingPuzzle(vector<vector<int>>& board) {
    const vector<vector<int>> valid{{1, 2, 3}, {4, 5, 0}};
    const uint32_t hash_valid = encode(valid);
    unordered_map<uint32_t, int> cache;
    deque<vector<vector<int>>> q;
    cache[encode(board)] = 0;
    q.push_back(board);
    while (!q.empty()) {
      auto cur = q.front();
      auto hash_cur = encode(cur);
      q.pop_front();
      if (hash_cur == hash_valid) {
        return cache[hash_cur];
      }
      auto where0 = locate0(cur);
      vector<ipair> nbrs{
          {where0.first + 1, where0.second},
          {where0.first - 1, where0.second},
          {where0.first, where0.second + 1},
          {where0.first, where0.second - 1},
      };
      for (auto& nbr : nbrs) {
        if (nbr.first < 0 || nbr.first > 1 || nbr.second < 0 || nbr.second > 2)
          continue;
        swap(cur[where0.first][where0.second], cur[nbr.first][nbr.second]);
        auto hash = encode(cur);
        if (cache.find(hash) == cache.end()) {
          // LOG(INFO) << "push to queue: " << cur;
          cache[hash] = 1 + cache[hash_cur];
          q.push_back(cur);
        }
        swap(cur[where0.first][where0.second], cur[nbr.first][nbr.second]);
      }
    }
    return -1;
  }
  ipair locate0(vector<vector<int>>& board) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {
        if (board[i][j] == 0) return {i, j};
      }
    }
    return {-1, -1};
  }
  constexpr uint32_t encode(const vector<vector<int>>& board) {
    uint32_t ret = 0;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {
        ret = (ret << 4) + board[i][j];
      }
    }
    return ret;
  }
};

