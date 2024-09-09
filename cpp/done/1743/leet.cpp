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
  vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    unordered_map<int, vector<int>> val_to_idx;
    unordered_set<int> endpoints;
    const int n = adjacentPairs.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 2; j++) {
        int u = adjacentPairs[i][j];
        val_to_idx[u].push_back(i);
        auto it = endpoints.find(u);
        if (it == endpoints.end()) {
          endpoints.insert(u);
        } else {
          endpoints.erase(it);
        }
      }
    }
    vector<int> ans;
    ans.reserve(n);
    int ep = *endpoints.begin();
    ans.push_back(ep);
    int prev_idx = -1;
    while (ans.size() <= n) {
      while (val_to_idx[ep].back() == prev_idx) {
        val_to_idx[ep].pop_back();
      }
      int idx = val_to_idx[ep].back();
      val_to_idx[ep].pop_back();
      if (adjacentPairs[idx][0] == ep) {
        ep = adjacentPairs[idx][1];
        ans.push_back(ep);
      } else {
        ep = adjacentPairs[idx][0];
        ans.push_back(ep);
      }
      prev_idx = idx;
    }
    return ans;
  }
};
