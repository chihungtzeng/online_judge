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
  double averageWaitingTime(vector<vector<int>>& customers) {
    const int n = customers.size();
    uint64_t last_finish = 0;
    uint64_t total_wait = 0;
    for (int i = 0; i < n; i++) {
      uint64_t arrival = customers[i][0];
      uint64_t prepare = customers[i][1];
      if (arrival > last_finish) {
        total_wait += prepare;
        last_finish = arrival + prepare;
      } else {
        last_finish = last_finish + prepare;
        total_wait += last_finish - arrival;
      }
    }
    return double(total_wait) / n;
  }
};
