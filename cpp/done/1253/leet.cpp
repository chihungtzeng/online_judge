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
  vector<vector<int>> reconstructMatrix(int upper, int lower,
                                        vector<int>& colsum) {
    const int n = colsum.size();
    vector<vector<int>> ans(2, vector<int>(n, -1));
    int usum = 0;
    int lsum = 0;

    for (int i = 0; i < n; i++) {
      if (colsum[i] == 0) {
        ans[0][i] = 0;
        ans[1][i] = 0;
      } else if (colsum[i] == 2) {
        ans[0][i] = 1;
        ans[1][i] = 1;
        usum++;
        lsum++;
      }
    }
    bool possible = true;
    for (int i = 0; i < n && possible; i++) {
      if (ans[0][i] == -1) {
        if (usum < upper && lsum < lower) {
          ans[0][i] = 1;
          ans[1][i] = 0;
          usum++;
        } else if (usum == upper && lsum < lower) {
          ans[0][i] = 0;
          ans[1][i] = 1;
          lsum++;
        } else if (usum < upper && lsum == lower) {
          ans[0][i] = 1;
          ans[1][i] = 0;
          usum++;
        } else {
          possible = false;
        }
      }
    }
#if 0    
    for(int i=0; i<2; i++){
      LOG(INFO) << ans[i];
    }
#endif
    if (usum != upper || lsum != lower || !possible) {
      ans.clear();
    }

    return ans;
  }
};
