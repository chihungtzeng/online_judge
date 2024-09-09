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
  bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    vector<vector<int>> cans;
    cans.reserve(triplets.size());
    set<int> digit_sets[3];
    for (auto& t : triplets) {
      if (t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]) {
        cans.push_back(t);
        for (int i = 0; i < 3; i++) {
          digit_sets[i].insert(t[i]);
        }
      }
    }
    for (int i = 0; i < 3; i++) {
      if (digit_sets[i].count(target[i]) == 0) return false;
    }
    return true;
  }
};
