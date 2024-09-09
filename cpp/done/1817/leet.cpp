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
  vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
    unordered_map<int, set<int>> uam;
    for (auto& log : logs) {
      uam[log[0]].insert(log[1]);
    }
    vector<int> ans(k);
    for (auto& [k, v] : uam) {
      ans[v.size() - 1]++;
    }
    return ans;
  }
};
