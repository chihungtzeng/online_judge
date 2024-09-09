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
 int n;
  const vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
  int minimumMoves(vector<vector<int>>& grid) {
    n = grid.size();
    vector<int> nodes; // encoded as [head_r, head_c, tail_r, tail_c]
    unordered_map<int, vector<int>> nbrs;
    for(int r = 0; r<n; r++){
      for(int c = 0; c<n; c++){
        if (grid[r][c] == 1) continue;

        for(int i=0; i<4; i++){
          int nr = r + dx[i];
          int nc = c + dy[i];
          if (oob(nr, nc)) continue;
          if (grid[nr][nc] == 1) continue;
          nodes.push_back(r, c, nr, nc);
        }
      }
    }
    for(auto& node: nodes){
      int head_r = node >> 24;
      int head_c = (node >> 16) & 0xff;
      int tail_r = (node >> 8) & 0xff;
      int tail_c = node & 0xff;
      if (head_r == tail_r){
        int nhr = head_r - 1;
        if (!oob(nhr, head_c, nhr, tail_c))
        {
          if (grid[nhr][head_c] == 1 && grid[nhr][tail_c] == 1){
            nbrs[node].push_back(encode(nhr, head_c, nhr, tail_c));
          }
        }
        int nhr = head_r + 1;
        if (!oob(nhr, head_c, nhr, tail_c))
        {
          if (grid[nhr][head_c] == 1 && grid[nhr][tail_c] == 1){
            nbrs[node].push_back(encode(nhr, head_c, nhr, tail_c));
          }
        }
      }
      if (head_c == tail_c){
      }
    }

  }
  int encode(int hr, int hc, int tr, int tc){
    return (hr << 24) | (hc << 16) | (tr << 8) | tc;
  }

  bool oob(int r, int c){
    return bool(r < 0 || r >= n || c<0 || c>=n);
  }
};
