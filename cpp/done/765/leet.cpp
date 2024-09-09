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
  int minSwapsCouples(vector<int>& row) {
    unordered_map<int, int> pos_of;
    for (int i = 0; i < row.size(); i++) {
      pos_of[row[i]] = i;
    }
    int ret = 0;
    for (int i = 0; i < row.size(); i += 2) {
      if (row[i] == spouse_of(row[i + 1])) continue;

      auto spouse = spouse_of(row[i]);
      auto pos = pos_of[spouse];
      pos_of[row[i + 1]] = pos;
      pos_of[spouse] = i + 1;
      swap(row[i + 1], row[pos]);
      ret++;
    }
    return ret;
  }
  int spouse_of(int idx) {
    if (idx & 1)
      return idx - 1;
    else
      return idx + 1;
  }
};
