#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  void gameOfLife(vector<vector<int>>& board) {
    const auto org = board;
    for(auto i=0; i<board.size(); i++){
      for(auto j=0; j<board[0].size(); j++){
        auto nlive_nbr = get_live_nbr(org, i, j);
        if (org[i][j] == 1) {
          if (nlive_nbr < 2 || nlive_nbr > 3)
          {
            board[i][j] = 0;
          }
        }
        else {
          if (nlive_nbr == 3)
          {
            board[i][j] = 1;
          }
        }
      }
    }
  }

  int get_live_nbr(const vector<vector<int>>& org, int i, int j){
    int rows = org.size();
    int cols = org[0].size();
    int res = 0;
    for (int x=-1; x<=1; x++){
      for(int y=-1; y<=1; y++){
        if ((x==0) && (y==0)) {
          continue;
        }
        auto r = i + x;
        auto c = j + y;
        if (r >= 0 && c >= 0 && r < rows && c < cols && org[r][c] == 1) {
          res += 1;
        }
      }
    }
    return res;
  }
};
