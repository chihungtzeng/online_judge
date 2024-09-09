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

constexpr int base = 1e9 + 7;
class Solution {
 public:
  int numWays(int steps, int arrLen) {
    arrLen = min(steps, arrLen);
    vector<vector<long>> nways(2, vector<long>(arrLen));

    nways[0][0] = 1;
    int cur = 0;
    for (int i = 1; i <= steps; i++) {
      cur = 1 - cur;
      int prev = 1 - cur;

      nways[cur][0] = nways[prev][0] + nways[prev][1];
      for (int j = 1, stop = arrLen - 1; j < stop; j++) {
        nways[cur][j] =
            nways[prev][j - 1] + nways[prev][j] + nways[prev][j + 1];
      }
      nways[cur][arrLen - 1] =
          nways[prev][arrLen - 2] + nways[prev][arrLen - 1];
      for (int j = 0; j < arrLen; j++) {
          nways[cur][j] %= base;
      }
    }
    return nways[cur][0];
  }
};
