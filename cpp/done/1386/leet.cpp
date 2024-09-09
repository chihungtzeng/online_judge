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

class Solution {
 public:
  int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    unordered_map<int, vector<int>> rseats;
    for (auto& seat : reservedSeats) {
      int row = seat[0], col = seat[1];
      rseats[row].push_back(col);
    }
    int ans = (n - rseats.size()) << 1;
    for (auto& [key, seats] : rseats) {
      bool r25 = false, r69 = false, r47 = false;
      int inc = 0;
      for (auto pos : seats) {
        if (pos == 2 || pos == 3) r25 = true;
        if (pos == 4 || pos == 5) {
          r47 = true;
          r25 = true;
        }
        if (pos == 6 || pos == 7) {
          r47 = true;
          r69 = true;
        }
        if (pos == 8 || pos == 9) {
          r69 = true;
        }
      }
      if (!r25) {
        if (!r69) {
          inc = 2;
        } else {
          inc = 1;
        }
      } else {
        if ((!r47) || (!r69)) {
          inc = 1;
        }
      }
      ans += inc;
    }
    return ans;
  }
};
