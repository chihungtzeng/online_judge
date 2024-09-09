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
  vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
    const int n = favoriteCompanies.size();
    int nc = 0;
    unordered_map<string, int> cid;
    for (auto& fc : favoriteCompanies) {
      for (auto& cname : fc) {
        auto it = cid.find(cname);
        if (it == cid.end()) {
          cid[cname] = nc++;
        }
      }
    }
    vector<unordered_set<int>> fcids(n);
    for (int i = 0; i < n; i++) {
      for (int j = favoriteCompanies[i].size() - 1; j >= 0; j--) {
        fcids[i].insert(cid[favoriteCompanies[i][j]]);
      }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (!subset_of_any(i, fcids)) ans.push_back(i);
    }
    return ans;
  }
  bool subset_of_any(int idx, vector<unordered_set<int>>& fcids) {
    for (int i = 0; i < fcids.size(); i++) {
      if (i == idx) continue;
      bool subset_of_i = true;
      for (auto cid : fcids[idx]) {
        if (fcids[i].find(cid) == fcids[i].end()) {
          subset_of_i = false;
          break;
        }
      }
      if (subset_of_i) return true;
    }
    return false;
  }
};

