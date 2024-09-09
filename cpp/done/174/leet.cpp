#include <algorithm>
#include <cstdint>
#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  int rows, cols;
  int min_hp(int addon, int expect) {
    if (addon >= 0) {
      if (addon >= expect) {
        return 1;
      }
      return expect - addon;
    }
    return expect - addon;
  }
  int calculateMinimumHP(vector<vector<int>> &dungeon) {
    rows = static_cast<int>(dungeon.size());
    cols = static_cast<int>(dungeon[0].size());
    vector<vector<int>> hp(rows);
    int r, c;
    for (auto &v : hp) {
      v.resize(cols);
    }
    hp[rows - 1][cols - 1] = min_hp(dungeon[rows - 1][cols - 1], 1);
    c = cols - 1;
    for (r = rows - 2; r >= 0; r--) {
      hp[r][c] = min_hp(dungeon[r][c], hp[r + 1][c]);
    }
    r = rows - 1;
    for (c = cols - 2; c >= 0; c--) {
      hp[r][c] = min_hp(dungeon[r][c], hp[r][c + 1]);
    }
    for (r = rows - 2; r >= 0; r--) {
      for (c = cols - 2; c >= 0; c--) {
        hp[r][c] = min_hp(dungeon[r][c], min(hp[r][c + 1], hp[r + 1][c]));
      }
    }

    return hp[0][0];
  }
};
