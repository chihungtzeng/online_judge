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

constexpr int nsquares = 320;
class Solution {
 public:
  vector<int> squares;
  bool winnerSquareGame(int n) {
    if (squares.empty()) {
      squares.resize(nsquares);
      for (int i = 1; i < nsquares; i++) squares[i] = i * i;
    }
    vector<bool> win(100001, false);
    win[1] = true;
    for (int i = 2; i <= n; i++) {
      auto it = lower_bound(squares.begin(), squares.end(), i);
      int dist = it - squares.begin();
      if (squares[dist] > i) dist--;

      for (int j = dist; j >= 1; j--) {
        int sq = squares[j];
        if (!win[i - sq]) {
          win[i] = true;
          break;
        }
      }
    }
    return win[n];
  }
};
