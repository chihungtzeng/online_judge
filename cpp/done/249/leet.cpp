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

struct DisjointSet {
  vector<int> parents, ranks;
  DisjointSet(int n) : parents(n), ranks(n) {
    for (int i = 0; i < n; i++) {
      parents[i] = i;
    }
  }
  int find(int u) {
    if (u != parents[u]) {
      parents[u] = find(parents[u]);
    }
    return parents[u];
  }
  void join(int u, int v) {
    int uroot = find(u);
    int vroot = find(v);
    if (uroot == vroot) return;

    if (ranks[uroot] < ranks[vroot]) {
      parents[uroot] = vroot;
    } else if (ranks[uroot] == ranks[vroot]) {
      parents[uroot] = vroot;
      ranks[vroot]++;
    } else {
      parents[vroot] = uroot;
    }
  }
};

class Solution {
 public:
  vector<vector<string>> groupStrings(vector<string>& strings) {
    const int n = strings.size();
    unordered_map<string, int> sid;
    for (int i = 0; i < n; i++) {
      sid[strings[i]] = i;
    }
    vector<bool> vis(n, false);
    DisjointSet ds(n);
    for (int i = 0; i < n; i++) {
      if (vis[i]) continue;
      auto rotated = rotations(strings[i]);
      vis[i] = true;
      for (auto& t : rotated) {
        auto it = sid.find(t);
        if (it != sid.end()) {
          ds.join(it->second, sid[strings[i]]);
          vis[it->second] = true;
        }
      }
    }
    vector<vector<string>> groups(n);
    for (int i = 0; i < n; i++) {
      int id = sid[strings[i]];
      int gid = ds.find(id);
      groups[gid].push_back(strings[i]);
    }
    vector<vector<string>> ans;
    for (int i = 0; i < n; i++) {
      if (!groups[i].empty()) {
        ans.emplace_back(std::move(groups[i]));
      }
    }
    return ans;
  }
  string next_rotation(string& s) {
    string t = s;
    for (int i = 0; i < s.size(); i++) {
      t[i] = (t[i] - 'a' + 1) % 26 + 'a';
    }
    return t;
  }
  vector<string> rotations(string& s) {
    vector<string> res(26);
    res[0] = s;
    for (int i = 0; i < 25; i++) {
      res[i + 1] = next_rotation(res[i]);
    }
    return res;
  }
};
