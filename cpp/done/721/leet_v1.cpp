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
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    vector<vector<string>> ret;
    if (accounts.empty()) return ret;
    int n = accounts.size();
    unordered_map<string, int> email2id;
    vector<string> names(n);
    vector<int> parents(n), ranks(n);
    for (int i = 0; i < n; i++) parents[i] = i;
    for (int i = 0; i < n; i++) {
      names[i] = accounts[i][0];
      for (int j = 1; j < accounts[i].size(); j++) {
        auto it = email2id.find(accounts[i][j]);
        if (it == email2id.end()) {
          email2id[accounts[i][j]] = i;
        } else {
          join(parents, ranks, i, it->second);
        }
      }
    }
    map<int, set<string>> emails;
    for (int i = 0; i < n; i++) {
      int root = find(parents, i);
      for (int j = 1; j < accounts[i].size(); j++) {
        emails[root].insert(accounts[i][j]);
      }
    }
    for (auto& [id, val] : emails) {
      ret.push_back(vector<string>{names[id]});
      for (auto& email : val) {
        ret.back().push_back(email);
      }
    }
    return ret;
  }
  int find(vector<int>& parents, int i) {
    if (parents[i] != i) {
      parents[i] = find(parents, parents[i]);
    }
    return parents[i];
  }
  void join(vector<int>& parents, vector<int>& ranks, int u, int v) {
    int uroot = find(parents, u);
    int vroot = find(parents, v);
    if (ranks[uroot] < ranks[vroot])
      parents[uroot] = vroot;
    else if (ranks[uroot] == ranks[vroot]) {
      parents[uroot] = vroot;
      ranks[vroot]++;
    } else {
      parents[vroot] = uroot;
    }
  }
};
