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
  int minSwaps(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<int> nzeros(n);
    for (int i = 0; i < n; i++) {
      int nz = 0;
      for (int j = n - 1; j >= 0; j--) {
        if (grid[i][j] == 0)
          nz++;
        else
          break;
      }
      nzeros[i] = nz;
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      int required_zero = n - 1 - i;
      bool found = false;
      int dest;
      for (int j = i; j < n && !found; j++) {
        if (nzeros[j] >= required_zero) {
          found = true;
          dest = j;
        }
      }
      if (!found) return -1;
      ans += dest - i;
      for (int j = dest - 1; j >= i; j--) {
        swap(nzeros[j], nzeros[j + 1]);
      }
    }
    return ans;
  }
};
