#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int countBattleships(vector<vector<char>>& board) {
    int nship = 0;
    int n = board.size();
    if (n == 0) {
      return 0;
    }
    int m = board[0].size();
    if (m == 0){
      return 0;
    }
    if (board[0][0] == 'X') nship++;
    for (int i = 1; i < m; i++) {
      if (board[0][i] == 'X' && board[0][i - 1] != 'X') nship++;
    }
    for (int i = 1; i < n; i++) {
      if (board[i][0] == 'X' && board[i - 1][0] != 'X') nship++;
    }

    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        if (board[i][j] == 'X' && board[i - 1][j] != 'X' &&
            board[i][j - 1] != 'X')
          nship++;
      }
    }
    return nship;
  }
};
