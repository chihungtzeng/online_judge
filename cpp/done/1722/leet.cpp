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

struct DisjointSet {
  vector<int> parents_, ranks_;
  DisjointSet(int n) : parents_(n), ranks_(n) {
    for (int i = 0; i < n; i++) {
      parents_[i] = i;
    }
  }
  int find(int u) {
    if (u != parents_[u]) {
      parents_[u] = find(parents_[u]);
    }
    return parents_[u];
  }
  void join(int u, int v) {
    int ur = find(u), vr = find(v);
    if (ur == vr) return;
    if (ranks_[ur] < ranks_[vr]) {
      parents_[ur] = vr;
    } else if (ranks_[ur] == ranks_[vr]) {
      parents_[ur] = vr;
      ranks_[vr]++;
    } else {
      parents_[vr] = ur;
    }
  }
};

class Solution {
 public:
  int minimumHammingDistance(vector<int>& source, vector<int>& target,
                             vector<vector<int>>& allowedSwaps) {
    const int n = source.size();
    DisjointSet ds(n);
    for (auto& uv : allowedSwaps) {
      int u = uv[0], v = uv[1];
      ds.join(u, v);
    }
    unordered_map<int, vector<int>> groups;
    for (int i = 0; i < n; i++) {
      int root = ds.find(i);
      groups[root].push_back(i);
    }
    int num_same = 0;
    for (auto& [root, group] : groups) {
      unordered_map<int, int> src_cnt, target_cnt;
      for (auto idx : group) {
        src_cnt[source[idx]]++;
        target_cnt[target[idx]]++;
      }
      for (auto& [key, cnt] : src_cnt) {
        num_same += min(cnt, target_cnt[key]);
      }
    }
    return n - num_same;
  }
};
