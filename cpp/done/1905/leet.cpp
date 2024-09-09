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

vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
class Solution {
 public:
  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    auto island1 = find_islands(grid1);
    auto island2 = find_islands(grid2);
    map<int, set<int>> island_mapping;
    const int rows = grid1.size();
    const int cols = grid1[0].size();
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid2[i][j] == 0) continue;
        auto iid = island2[i][j];
        island_mapping[iid].insert(island1[i][j]);
      }
    }
    int ans = 0;
    for (auto& [key, val] : island_mapping) {
      if (val.size() == 1 && (*val.begin() != 0)) {
        ans++;
      }
    }
    return ans;
  }
  vector<vector<int>> find_islands(vector<vector<int>>& grid) {
    const int rows = grid.size();
    const int cols = grid[0].size();
    auto ret = grid;
    int iid = 2;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid[i][j] == 0 || ret[i][j] > 1) {
          continue;
        }
        vector<int> stack;
        stack.reserve(500);
        stack.push_back((i << 12) + j);
        while (!stack.empty()) {
          int pos = stack.back();
          stack.pop_back();
          int r = pos >> 12;
          int c = pos & 0xfff;
          ret[r][c] = iid;
          for (int k = 0; k < 4; k++) {
            auto nr = r + dx[k];
            auto nc = c + dy[k];
            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
            if (ret[nr][nc] == 1) {
              stack.push_back((nr << 12) + nc);
            }
          }
        }
        iid++;
      }
    }
    return ret;
  }
};
