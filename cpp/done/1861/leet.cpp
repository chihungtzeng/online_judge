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

constexpr char empty = '.';
constexpr char stone = '#';
constexpr char obs = '*';
class Solution {
 public:
  vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    int rows = box.size();
    int cols = box[0].size();
    vector<vector<char>> ans(cols, vector<char>(rows, '.'));
    for (int r = 0; r < rows; r++) {
      int rc = rows - 1 - r;
      int c = cols - 1;
      int rr = cols - 1;
      while (c >= 0) {
        if (box[r][c] == obs) {
          rr = c;
          ans[rr][rc] = obs;
          rr--;
        } else if (box[r][c] == stone) {
          ans[rr][rc] = stone;
          rr--;
        }
        c--;
      }
    }
#if 0    
    for(auto& row: ans)
    {
      LOG(INFO) << row;
    }
#endif
    return ans;
  }
};
